#include <iostream>
#include <type_traits>

// Base class using CRTP
template <typename Derived>
class Base {
public:
    template <typename T = Derived>
    static typename std::enable_if<std::is_same_v<decltype(T::baseStaticFunction), void(*)()>>::type
    baseStaticFunction() {
        Derived::derivedStaticFunction();
    }
};

// Derived class implementing the derived static function
class Derived : public Base<Derived> {
public:
   //static void baseStaticFunction() {
   //     std::cout << "Base static function called!" << std::endl;
   // }


};

int main() {
    Derived::baseStaticFunction(); // Output: "Derived static function called!"

    return 0;
}


#ifndef TIMER_IF
#define TIMER_IF
#include <cstdint>
namespace ifc
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
