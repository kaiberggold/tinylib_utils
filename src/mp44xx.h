#ifndef MP44XX
#define MP44XX
#include <cstdint>
#include <array>
// #include <hal.h>
#include "i2c_com.h"
namespace utils
{
    template <typename addr_t, typename reg_t, reg_t bus_idx, std::uint32_t freq>
    class PotiIc
    {
    private:
        addr_t _address;
        addr_t _chip_select_address;
        utils::I2cCom<addr_t, reg_t, bus_idx, freq> *_i2c;
        const std::array<reg_t, 4> vol_wiper = {0x00, 0x01, 0x06, 0x07};
        // const reg_t fixed_addr = 0b01011000;

    public:
        PotiIc(addr_t a, addr_t c, utils::I2cCom<addr_t, reg_t, bus_idx, freq> *i) : _address(a),
                                                                                     _chip_select_address(c), _i2c(i)
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
            _i2c->start();
            _i2c->send(byte_0);
            _i2c->send(byte_1);
            _i2c->send(byte_2);
            _i2c->stop();
        }
    };

} // namespace utils

#endif