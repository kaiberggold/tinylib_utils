#ifndef ROTARY_ENCODER
#define ROTARY_ENCODER
#include "digital_pin.h"
#include "circular_buffer.h"

namespace utils
{

    template <typename addr_t, typename reg_t>

    class RotaryEncoderVirtual
    {
    private:
        reg_t _pos_min;
        reg_t _pos_max;
        reg_t _step;
        reg_t _pos;
        uint8_t _rot_state;
        uint8_t _rot_state_mem;
        CircularBuffer<std::uint8_t, 4> _state_buffer;

    public:
        RotaryEncoderVirtual(reg_t min, reg_t max, reg_t s, reg_t p) : _pos_min(min), _pos_max(max), _step(s), _pos(p)
        {
        }

        void rot_state_change(std::uint8_t rot_state)
        {
            _state_buffer.buffer_in(rot_state);
        }
    };
}

#endif