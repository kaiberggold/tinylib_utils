#ifndef MPC3202
#define MPC3202
#include <cstdint>
#include <array>
// #include <hal.h>
#include "spi_com.h"
namespace utils
{
    template <typename addr_t, typename reg_t, reg_t bus_idx, utils::DigitalPin cs, std::uint8_t clock_scaling>
    class ADConverterIC
    {
    private:
        utils::DigitalPin _chip_select;
        utils::SpiCom<addr_t, reg_t, bus_idx, cs, clock_scaling> *_spi;

    public:
        ADConverter(addr_t a, addr_t cs, utils::SpiCom<addr_t, reg_t bus_idx, cs, clock_scaling> *i) : _address(a),
                                                                                                       _chip_select(cs),
                                                                                                       _spi(i)
        {
            ;
        }

        std::uint16_t get_raw_value()
        {
        }
    };

} // namespace utils

#endif