#ifndef DIGITAL_POTI
#define DIGITAL_POTI
#include <cstdint>
#include <poti_ic_if.h>
namespace utils
{
    template <typename poti_ic_t, typename addr_t, typename reg_t>
    class DigiPoti
    {
        poti_ic_t _poti_ic;
        reg_t _poti_idx;

    public:
        DigiPoti(poti_ic_t p, reg_t i) : _poti_ic(p), _poti_idx(i){};
        reg_t get_max()
        {
            return 127;
        }

        void set_volatile(std::uint16_t val)
        {
            _poti_ic.set_val_volatile(_poti_idx, val);
        }
    }; // namespace utils
}
#endif