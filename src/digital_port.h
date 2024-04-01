#ifndef DIGITAL_PORT
#define DIGITAL_PORT
#include <cstdint>
#include <hal.h>

namespace utils
{
  template <typename addr_t, typename reg_t, const std::uint8_t port_idx>
  struct DigitalPort
  {
    static void set_port(reg_t val)
    {
      hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_set(val);
    }

    static void port_or(reg_t val)
    {
      hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_or(val);
    }

    static void port_and(reg_t val)
    {
      hal::HalDigitalPort<addr_t, reg_t, port_idx>::reg_and(val);
    }

    static void get_port(reg_t val)
    {
      hal::HalDigitalPort<addr_t, reg_t, port_idx>::get_reg(val);
    }
    static void set_to_out_mask(reg_t val)
    {
      hal::HalDigitalPort<addr_t, reg_t, port_idx>::set_to_out_mask(val);
    }
  };

} // namespace utils

#endif