#ifndef DIGITAL_PIN
#define DIGITAL_PIN
#include <cstdint>
#include <hal.h>
namespace utils
{
    template <typename addr_t, typename reg_t, const std::uint8_t port_idx, std::uint8_t pin>
    struct DigitalPin
    {
        static void set_pin(reg_t val)
        {
            if (val)
            {
                hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_or(1U << pin);
            }
            else
            {
                hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_and(~(static_cast<reg_t>(1U) << pin));
            }
        }

        static void set_to_out_pin()
        {
            hal::HalDigitalPort<addr_t, reg_t, port_idx>::set_to_out_mask(1U << pin);
        }
    };

} // namespace utils

#endif