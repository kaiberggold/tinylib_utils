#ifndef SPI_COM_STATIC
#define SPI_COM_STATIC
#include <cstdint>
#include <hal.h>
#include "digital_pin.h"

namespace utils
{

    template <typename addr_t, typename reg_t, reg_t bus_idx, reg_t clock_scaling, reg_t spi_mode, typename digital_pin_t>

    struct SpiComStatic
    {
        using SpiCom_t = hal::HalSpiCom<addr_t, reg_t, bus_idx, clock_scaling, spi_mode, 0>;

    public:
        constexpr SpiComStatic()
        {
            static_assert(clock_scaling == 2 || clock_scaling == 4 || clock_scaling == 8 || clock_scaling == 16 || clock_scaling == 32 || clock_scaling == 64 || clock_scaling == 128, "clock_scaling must be 2, 4, 8, 16, 32, 64, or 128");
        }

        static constexpr void init()
        {
            digital_pin_t::set_pin(true);
            digital_pin_t::set_to_out_pin();
            SpiCom_t::init();
        }

        static constexpr void send(std::uint8_t data)
        {
            SpiCom_t::send(data);
        }

        static reg_t read()
        {
            return SpiCom_t::read();
        }

        static bool transmission_active()
        {
            return SpiCom_t::transmission_active();
        }
    };
}

#endif