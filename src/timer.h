#ifndef UTILS_TIMER
#define UTILS_TIMER
#include <cstdint>
#include "timer_if.h"

namespace utils
{
    template <typename TimerT, typename addr_t, typename reg_t, typename timer_t, reg_t timer_idx>
    class Timer
    {
    private:
    public:
        constexpr Timer()
        {
        }

        static constexpr void init(timer_t start_time)
        {
            hal::TimerT<addr_t, reg_t, timer_t, timer_idx>::init(start_time);
        }
    };
}

#endif