#ifndef MPC3202
#define MPC3202
#include <cstdint>
#include <array>
namespace utils
{
    template <typename byte_com_static_t, typename addr_t, typename reg_t, typename digital_pin_t>
    struct Mpc3202
    {
    public:
        static std::uint16_t get_raw_value()
        {
            return 0;
        }

        static void enable()
        {
            digital_pin_t::set_pin(false);
        }

        static void disable()
        {
            digital_pin_t::set_pin(true);
        }
        template <reg_t step_idx>
        static void send()
        {
            if (step_idx == 0)
            {
                byte_com_static_t::send(0x01);
            }
            else if (step_idx == 1)
            {
                byte_com_static_t::send(0x90);
            }
            else
            {
                byte_com_static_t::send(0x00);
            }
        }

        reg_t
        read()
        {
            return byte_com_static_t::read();
        }
    };

} // namespace utils

#endif