#ifndef DIGITAL_PIN
#define DIGITAL_PIN
#include <cstdint>
// #include <mcal.h>
#include "digital_pin.h"
namespace utils
{
    template <typename addr_t, typename reg_t, const std::uint8_t port_idx, std::uint8_t pin>
    struct DigitalPin
    {
        static void set_pin(pin, reg_t val)
        {
            hal::McalDigitalPort<addr_t, reg_t, port_idx>::set_bits(val, pin);
        }
        // static void get_port(reg_t val)
        // {
        //     hal::McalDigitalPort<addr_t, reg_t, port_idx>::get_reg(val);
        // }
        static void set_to_out_pin(pin)
        {
            hal::McalDigitalPort<addr_t, reg_t, port_idx>::set_to_out_mask(val);
        }
    };

} // namespace utils

#endif