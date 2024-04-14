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

    }; // namespace utils
}
#endif
