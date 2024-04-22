#ifndef TIMER_IF
#define TIMER_IF

#include <cstdint>
#include <type_traits>

namespace utils
{
    // Define a helper type for SFINAE
    template <typename T, typename = void>
    struct has_init_impl : std::false_type
    {
    };

    template <typename T>
    struct has_init_impl<T, std::void_t<decltype(&T::init_impl)>> : std::true_type
    {
    };

    template <typename T, typename = void>
    struct has_irq_reset_impl : std::false_type
    {
    };

    template <typename T>
    struct has_irq_reset_impl<T, std::void_t<decltype(&T::irq_reset_impl)>> : std::true_type
    {
    };

    template <typename TimerT, typename addr_t, typename reg_t, typename timer_t, reg_t timer_idx>
    struct TimerIf
    {
        static void init(timer_t start_time)
        {
            static_assert(has_init_impl<TimerT>::value, "init_impl function not provided by TimerT");
            TimerT::init_impl(start_time);
        }

        static void irq_reset(timer_t start_time)
        {
            static_assert(has_irq_reset_impl<TimerT>::value, "irq_reset_impl function not provided by TimerT");
            TimerT::irq_reset_impl(start_time);
        }
    };
}

#endif
