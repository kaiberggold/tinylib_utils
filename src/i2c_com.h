#ifndef USART_I2C
#define USART_I2C
#include <cstdint>
#include <hal.h>
#include "circular_buffer.h"

namespace utils
{
    template <typename addr_t, typename reg_t, const std::uint32_t freq, const std::uint8_t bus_idx>
    class I2cCom
    {
        utils::CircularBuffer<std ::uint8_t, 255> _i2c_buffer;

    public:
        void init()
        {
            hal::HalI2CCom<addr_t, reg_t, freq, bus_idx>::init();
        }
    };
}
#endif