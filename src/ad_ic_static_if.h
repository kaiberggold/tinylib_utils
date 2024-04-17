#ifndef AD_IC_STATIC_IF
#define AD_IC_STATIC_IF
#include <cstdint>
namespace ifc
{
    template <typename AdIcStatic, typename byte_com_static, typename addr_t, typename reg_t>
    struct AdIcStaticIf
    {
        static std::uint16_t get_raw_value()
        {
            return 0;
        }

        template <reg_t step_idx>
        static void send()
        {
            AdIcStatic::template send<step_idx>();
        }

        static reg_t read()
        {
            return AdIcStatic::read();
        }

        static void enable()
        {
            AdIcStatic::enable();
        }

        static void disable()
        {
            AdIcStatic::disable();
        }

        static void bus_transmission_wait_blocking()
        {
            AdIcStatic::bus_transmission_wait_blocking();
        }
    };
}
#endif

// cs_ad.set_pin(false);
// spi.send(0x01);
// while (spi.transmission_active())
// {
// }
// spi.read();
// spi.send(0x90);
// while (spi.transmission_active())
// {
// }
// std::uint8_t d2 = spi.read();
// spi.send(0x00);
// while (spi.transmission_active())
// {
// }
// std::uint8_t d3 = spi.read();
// cs_ad.set_pin(true);