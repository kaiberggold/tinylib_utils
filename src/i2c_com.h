#ifndef USART_I2C
#define USART_I2C
#include <cstdint>

namespace utils
{
    template <typename addr_t, typename reg_t, const std::uint8_t idx>
    class i2cCom
    {
        void i2c_com_init()
        {
            hal::HalI2CCom<addr_ty, reg_t, idx>::init();
        }
    };
}
#endif