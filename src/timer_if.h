#ifndef TIMER_IF
#define TIMER_IF

#include <cstdint>
#include <type_traits>

namespace utils
{
    template <typename TimerT, typename addr_t, typename reg_t, typename timer_t, reg_t timer_idx>
    struct TimerIf
    {
        static void init(timer_t start_time)
        {
            TimerT::init_impl(start_time);
        }

        static void irq_reset(timer_t start_time)
        {
            TimerT::irq_reset_impl(start_time);
        }
    };
}

#endif
