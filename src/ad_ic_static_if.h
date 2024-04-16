#ifndef AD_IC_STATIC_IF
#define AD_IC_STATIC_IF
#include <cstdint>
namespace ifc
{
    template <typename AdIcStatic, typename byte_com_static, typename addr_t, typename reg_t>
    struct AdIcStaticIf
    {
        std::uint16_t get_raw_value()
        {
            return 0;
        }
    };
}
#endif
