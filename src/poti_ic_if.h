#ifndef POTI_IC
#define POTI_IC
#include <cstdint>
namespace ifc
{
    template <typename PotiIc, typename addr_t, typename reg_t, reg_t bus_idx, std::uint32_t freq>
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
