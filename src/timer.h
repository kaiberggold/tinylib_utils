#ifndef UTILS_TIMER
#define UTILS_TIMER
#include <cstdint>
#include <hal.h>

namespace utils
{
    template <typename addr_t, typename reg_t, reg_t timer_idx>
    class Timer
    {
    private:
    public:
        constexpr Timer()
        {
            //    static_assert(clock_scaling == 2 || clock_scaling == 4 || clock_scaling == 8 || clock_scaling == 16 || clock_scaling == 32 || clock_scaling == 64 || clock_scaling == 128, "clock_scaling must be 2, 4, 8, 16, 32, 64, or 128");
        }

        static constexpr void init()
        {
            hal::HalTimer<addr_t, reg_t, timer_idx>::init();
        }
    };
}

#endif