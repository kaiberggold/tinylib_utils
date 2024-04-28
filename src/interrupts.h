#ifndef INTERRUPTS
#define INTERRUPTS
#include <hal.h>
namespace utils
{
    struct Interrupts
    {
    public:
        static void enable_all_interrupts()
        {
            hal::enable_all_interrupts();
        }

        template <typename addr_t, typename reg_t, reg_t port_idx>
        static void enable_pin_change_port() noexcept
        {
            hal::enable_pin_change_port<addr_t, reg_t, port_idx>();
        }

        template <typename addr_t, typename reg_t, reg_t pin_idx>
        static void enable_pin_change_pin() noexcept
        {
            hal::enable_pin_change_pin<addr_t, reg_t, pin_idx>();
        }

    }; // namespace utils
}
#endif
