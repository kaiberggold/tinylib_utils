#include <cstdint>
#include <mcal.h>


namespace utils
{
    template<typename addr_t, typename reg_t, const std::uint8_t port_idx>
    struct DigitalPort
    {
        static void set_port(reg_t val)
        {
            tlm::dpo::McalDigitalPort<addr_t,reg_t,port_idx>::set_port(val);
        }       
        static void get_port(reg_t val)
        {
            tlm::dpo::McalDigitalPort<addr_t,reg_t,port_idx>::get_port(val);
        }
        static void set_to_out_mask(reg_t val)
        {
            tlm::dpo::McalDigitalPort<addr_t,reg_t,port_idx>::set_to_out_mask(val);
        }         
    };

}