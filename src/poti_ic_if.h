#ifndef POTI_IC_IF
#define POTI_IC_IF
#include <cstdint>
namespace utils
{
    template <typename PotiIc, typename byte_com_t, typename addr_t, typename reg_t>
    class PotiIcIf
    {
    protected:
        addr_t _address;
        addr_t _chip_select_address;
        byte_com_t _byte_com;

    public:
        PotiIcIf(addr_t a, addr_t c, byte_com_t i) : _address(a),
                                                     _chip_select_address(c),
                                                     _byte_com(i)
        {
            ;
        }
        void set_val_volatile(reg_t poti_id, std::uint16_t value)
        {
            static_cast<PotiIc *>(this)->set_val_volatile_l(poti_id, value);
        }
    };
}
#endif
