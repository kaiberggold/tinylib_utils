#ifndef UTILS_SPI_COM
#define UTILS_SPI_COM
#include <cstdint>
#include <hal.h>

namespace utils
{
    template <typename addr_t, typename reg_t, reg_t bus_idx, std::uint8_t port_idx, reg_t pin_idx, std::uint8_t clock_scaling>
    class SpiCom
    {
    private:
    public:
        constexpr SpiCom()
        {
            static_assert(clock_scaling == 2 || clock_scaling == 4 || clock_scaling == 8 || clock_scaling == 16 || clock_scaling == 32 || clock_scaling == 64 || clock_scaling == 128, "clock_scaling must be 2, 4, 8, 16, 32, 64, or 128");
        }

        constexpr void init()
        {
            hal::HalSpiCom<addr_t, reg_t, bus_idx, port_idx, pin_idx, clock_scaling>::init();
        }

        void send(std::uint8_t data)
        {
        }

        void start()
        {
        }

        void stop()
        {
        }
    };
}

#endif