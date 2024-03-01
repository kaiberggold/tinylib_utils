#include <cstdint>
#include <mcal.h>


namespace utils
{
    template<typename addr_t, typename reg_t, const std::uint8_t port_idx>
    struct DigitalPort
    {
        static void set_port(reg_t val);
    };
}