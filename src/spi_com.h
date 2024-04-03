#ifndef UTILS_SPI_COM
#define UTILS_SPI_COM
#include <cstdint>
#include <hal.h>
#include "digital_pin.h"

namespace utils
{
    template <typename addr_t, typename reg_t, reg_t bus_idx, utils::DigitalPin cs, std::uint8_t clock_scaling>
    class SpiCom
    {
    private:
    public:
        constexpr SpiCom()
        {
            static_assert(clock_scaling == 2 || clock_scaling == 4 || clock_scaling == 8 || clock_scaling == 16 || clock_scaling == 32 || clock_scaling == 64 || clock_scaling == 128, "clock_scaling must be 2, 4, 8, 16, 32, 64, or 128");
        }

        static constexpr void init()
        {
            hal::HalSpiCom<addr_t, reg_t, bus_idx, cs.get_port_idx(), cs.get_pin_idx(), clock_scaling>::init();
        }

        static void send(std::uint8_t data)
        {
            hal::HalSpiCom<addr_t, reg_t, bus_idx, cs.get_port_idx(), cs.get_pin_idx(), clock_scaling>::send(data);
        }

        static reg_t read()
        {
            return hal::HalSpiCom<addr_t, reg_t, bus_idx, cs.get_port_idx(), cs.get_pin_idx(), clock_scaling>::read();
        }

        static bool transmission_active()
        {
            return hal::HalSpiCom<addr_t, reg_t, bus_idx, cs.get_port_idx(), cs.get_pin_idx(), clock_scaling>::transmission_active();
        }
    };
}

#endif