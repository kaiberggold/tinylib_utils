#ifndef DIGITAL_PIN
#define DIGITAL_PIN
#include <cstdint>
#include <hal.h>
namespace utils
{
    template <typename addr_t, typename reg_t, const std::uint8_t port_idx, std::uint8_t pin_idx>
    struct DigitalPin
    {
        static void set_pin(bool val)
        {
            if (val)
            {
                hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_or(1U << pin_idx);
            }
            else
            {

                hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_and(~(static_cast<reg_t>(1U) << pin_idx));
            }
        }

        static void set_to_out_pin()
        {
            hal::HalDigitalPort<addr_t, reg_t, port_idx>::set_to_out_mask(1U << pin_idx);
        }

        static void set_to_in_pin()
        {
            hal::HalDigitalPort<addr_t, reg_t, port_idx>::set_to_in_mask(1U << pin_idx);
        }

        static void set_pin_toggle()
        {
            hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_xor(1U << pin_idx);
        }

        static constexpr reg_t get_port_idx()
        {
            return port_idx;
        }

        static constexpr reg_t get_pin_idx()
        {
            return pin_idx;
        }

        static reg_t get_pin()
        {
            return (hal::HalDigitalPort<addr_t, reg_t, port_idx>::get_reg() >> pin_idx) & 1;
        }
    };

} // namespace utils

#endif