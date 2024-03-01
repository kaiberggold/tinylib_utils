#include "digital_port.h"
#include "mcal.h"


template<typename addr_t, typename reg_t, const std::uint8_t port_idx>
void utils::DigitalPort<addr_t,reg_t,port_idx>::set_port(reg_t val) 
{
    tlm::dpo::McalDigitalPort<addr_t,reg_t,port_idx>::setport(reg_t::val);
}