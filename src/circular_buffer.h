#ifndef CIRCULAR_BUFFER
#define CIRCULAR_BUFFER

#include <array>
#include <cstdint>
#include <cstring>

#
namespace utils
{
    template <typename T, std::uint8_t buffer_size>
    class CircularBuffer
    {
    private:
        std::array<T, buffer_size> _send_buffer;
        std::uint8_t _pos_in;
        std::uint8_t _pos_out;
        std::uint8_t _n;

    public:
        CircularBuffer()
        {
            _pos_in = 0;
            _pos_out = 0;
            _n = 0;
        }
        void buffer_in(T data)
        {
            if (_n < buffer_size)
            {
                _send_buffer[_pos_in] = data;
                if (_pos_in < UINT8_MAX)
                {
                    _pos_in++;
                }
                else
                {
                    _pos_in = 0;
                }
                _n++;
            }
            // no else, just do nothing if buffer is full
        }
        T buffer_out()
        {
            std::uint8_t out;
            if (_n > 0)
            {
                out = _pos_out;
                if (_pos_out < UINT8_MAX)
                {
                    _pos_out++;
                }
                else
                {
                    _pos_out = 0;
                }
                _n--;
                return _send_buffer[out];
            }
            else
            {
                return 0; // should not happen
            }
        }

        bool buffer_empty()
        {
            return _n == 0;
        }
    };
    // class
} // namespace utils
#endif // CIRCULAR_BUFFER