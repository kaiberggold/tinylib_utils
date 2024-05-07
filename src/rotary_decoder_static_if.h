#ifndef ROTARY_ENCODER_STATIC
#define ROTARY_ENCODER_STATIC
#include "digital_pin.h"
#include "interrupts.h"
#include "usart_dbg.h"

extern utils::UsartDbg dbg;

namespace utils
{

    template <typename addr_t, typename reg_t, typename digital_pin_1_t, typename digital_pin_2_t>

    class RotaryEncoderStatic
    {
    public:
        static void init()
        {

            digital_pin_1_t::set_pin(true);
            digital_pin_1_t::set_to_in_pin();
            Interrupts::enable_pin_change_port<addr_t, reg_t, digital_pin_1_t::get_port_idx()>();
            Interrupts::enable_pin_change_pin<addr_t, reg_t, (digital_pin_1_t::get_port_idx() << 3) + digital_pin_1_t::get_pin_idx()>();
            digital_pin_2_t::set_pin(true);
            digital_pin_2_t::set_to_in_pin();
            Interrupts::enable_pin_change_port<addr_t, reg_t, digital_pin_2_t::get_port_idx()>();
            Interrupts::enable_pin_change_pin<addr_t, reg_t, (digital_pin_2_t::get_port_idx() << 3) + digital_pin_2_t::get_pin_idx()>();
        }

        static std::uint8_t get_raw_state()
        {
            return digital_pin_1_t::get_pin() * 2 + digital_pin_2_t::get_pin();
            // return digital_pin_2_t::get_pin();
        }

        static std::int8_t get_step(std::uint8_t old_state, std::uint8_t new_state)
        {
            constexpr std::array<std::int8_t, 16> lookup_table = {0, 0, 0, 0,
                                                                  -1, 0, 0, 1,
                                                                  0, 0, 0, 0,
                                                                  1, 0, 0, -1};
            return lookup_table[(old_state * 4) + new_state];
        }
    };
}

#endif