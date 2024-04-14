#ifndef TIMER_IF
#define TIMER_IF
#include <cstdint>
namespace ifc
{
    template <typename TimerT, typename addr_t, typename reg_t, typename timer_t, reg_t timer_idx>
    struct TimerIf
    {
    public:
        static void init(timer_t start_time)
        {
            TimerT::init(start_time);
        }
    };
}
#endif
