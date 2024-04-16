#ifndef MP44XX
#define MP44XX
#include <cstdint>
#include <array>
#include <poti_ic_if.h>
#include "i2c_com.h"
namespace utils
{
    template <typename byte_com_t, typename addr_t, typename reg_t>
    class Mp44xx
    {
    private:
        addr_t _address;
        addr_t _chip_select_address;
        byte_com_t _byte_com;
        const std::array<reg_t, 4> vol_wiper = {0x00, 0x01, 0x06, 0x07};
        // const reg_t fixed_addr = 0b01011000;

    public:
        Mp44xx(addr_t a, addr_t c, byte_com_t &i) : _address(a),
                                                    _chip_select_address(c),
                                                    _byte_com(i)
        {
            ;
        }

        void set_val_volatile(reg_t poti_id, std::uint16_t value)
        {
            // byte_0, a=fixed address, v: variable adress, 1 write
            // 0bfffffww0
            // byte_1, r= register value, c= command, 9 = bit 9
            // 0brrrrccx8
            // byte_2, remaining data bytes
            // 0b76543210
            reg_t byte_0 = _address | (_chip_select_address & 0x03) << 1;
            reg_t byte_1 = (vol_wiper[poti_id] << 4) | static_cast<reg_t>(((value >> 8) & 0x01));
            reg_t byte_2 = static_cast<reg_t>(value);
            _byte_com.start();
            _byte_com.send(byte_0);
            _byte_com.send(byte_1);
            _byte_com.send(byte_2);
            _byte_com.stop();
        }
    };

} // namespace utils

#endif