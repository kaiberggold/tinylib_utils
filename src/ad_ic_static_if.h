#ifndef AD_IC_STATIC_IF
#define AD_IC_STATIC_IF
#include <cstdint>
namespace ifc
{
    template <typename AdIcStatic, typename addr_t, typename reg_t, reg_t bus_idx, utils::DigitalPin cs, std::uint8_t clock_scaling>
    struct AdIcStaticIf
    {
        std::uint16_t get_raw_value()
        {
        }
    }
}
#endif
