#ifndef DIGITAL_POTI
#define DIGITAL_POTI
#include <cstdint>
namespace utils
{
    template <typename addr_t, typename reg_t, reg_t bus_idx, std::uint32_t freq>
    class DigiPoti
    {
        utils::PotiIc<addr_t, reg_t, bus_idx, freq> _poti_ic;
        reg_t _poti_idx;

    public:
        DigiPoti(utils::PotiIc<addr_t, reg_t, bus_idx, freq> p, reg_t i) : _poti_ic(p), _poti_idx(i){};
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