#ifndef MPC3202
#define MPC3202
#include <cstdint>
#include <array>
namespace utils
{
    template <typename addr_t, typename reg_t, typename byte_com_static_t, typename digital_pin_t>
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
            static_assert(step_idx >= 0 && step_idx <= 3, "step_idx only from 1-3");
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

        static reg_t read()
        {
            return byte_com_static_t::read();
        }

        static void bus_transmission_wait_blocking()
        {
            while (byte_com_static_t::transmission_active())
            {
                // wait
            }
        }
    };

} // namespace utils

#endif