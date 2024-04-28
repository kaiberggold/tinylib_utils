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
            Interrupts::enable_pin_change_pin<addr_t, reg_t, digital_pin_1_t::get_port_idx() << 3 + digital_pin_1_t::get_pin_idx()>();
            digital_pin_2_t::set_pin(true);
            digital_pin_2_t::set_to_in_pin();
            Interrupts::enable_pin_change_port<addr_t, reg_t, digital_pin_2_t::get_port_idx()>();
            Interrupts::enable_pin_change_pin<addr_t, reg_t, digital_pin_2_t::get_port_idx() << 3 + digital_pin_2_t::get_pin_idx()>();
        }
    };
}

#endif