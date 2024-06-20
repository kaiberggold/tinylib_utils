#ifndef ROTARY_ENCODER
#define ROTARY_ENCODER
#include "digital_pin.h"
#include "circular_buffer.h"

namespace utils
{

    template <typename addr_t, typename pos_t>

    class RotaryEncoderVirtual
    {
    private:
        pos_t _pos_min;
        pos_t _pos_max;
        pos_t _step_size;
        pos_t _pos;

    public:
        RotaryEncoderVirtual(pos_t min, pos_t max, pos_t s, pos_t p) : _pos_min(min), _pos_max(max), _step_size(s), _pos(p)
        {
        }

        void step(std::int8_t step_val)
        {
            _pos += step_val * _step_size;
            _pos = std::min(_pos, _pos_max);
            _pos = std::max(_pos, _pos_min);
        }

        pos_t get_pos()
        {
            return _pos;
        }
    };
}

#endif