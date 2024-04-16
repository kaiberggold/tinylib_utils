#ifndef POTI_IC
#define POTI_IC
#include <cstdint>
#include <poti_ic_if.h>
namespace utils
{
    template <typename PotiIc, typename addr_t, typename reg_t>
    struct PotiIcIf
    {
    public:
        void set_val_volatile(reg_t poti_id, std::uint16_t value)
        {
            PotiIc::set_val_volatile(poti_id, value);
        }
    };
}
#endif
