#ifndef MP44XX
#define DIGITAL_POTI_IC
#include <cstdint>
#include <hal.h>
#include "i2c_com.h"
namespace utils
{
    // Forward declaration

    template <typename addr_t, typename reg_t, reg_t bus_idx>
    class PotiIc
    {
    private:
        utils::I2cCom<addr_t, reg_t, bus_idx> _i2c;
        addr_t _address;
        addr_t _chip_select;

    public:
        PotiIc(addr_t a, addr_t c, utils::I2cCom<addr_t, reg_t, bus_idx> i) : _address(a), _chip_select(c), _i2c(i)
        {
            // Constructor body
        }

        void set_val_volatile(reg_t poti_id)
        {
            _i2c.send(1);
        }
    };

} // namespace utils

#endif