#ifndef ROTARY_ENCODER
#define ROTARY_ENCODER
#include "digital_pin.h"

namespace utils
{

    template <typename addr_t, typename reg_t, typename digital_pin_1_t, typename digital_pin_2_t>

    class RotaryEncoder
    {
    private:
        reg_t pos_min;
        reg_t pos_max;
        reg_t step;
        reg_t pos;

    public:
        constexpr RotaryEncoder(reg_t min, reg_t max, reg_t s, reg_t p) : pos_min(min), pos_max(max), step(s), pos(p)
        {
        }
    };
}

#endif