#ifndef POTI_IC_IF
#define POTI_IC_IF
#include <cstdint>
namespace ifc
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
