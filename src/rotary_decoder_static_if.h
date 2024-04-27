#ifndef ROTARY_ENCODER_STATIC
#define ROTARY_ENCODER_STATIC
#include "digital_pin.h"

namespace utils
{

    template <typename addr_t, typename reg_t, typename digital_pin_1_t, typename digital_pin_2_t>

    class RotaryEncoderStatic
    {
    public:
        static void init()
        {
            digital_pin_1_t::set_to_out_pin();
            digital_pin_2_t::set_to_out_pin();
        }
    };
}

#endif