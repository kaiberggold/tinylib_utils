#include "usart_dbg.h"
#include <cstdint>
#include <hal_usart.h>

// #include <util/setbaud.h>

void utils::UsartDbg::usart_dbg_init(std::uint32_t baud_rate)
{
  mu.init(baud_rate);
};

void utils::UsartDbg::usart_dbg_step()
{
  if (!_send_buffer.buffer_empty() && _usart_buffer_empty())
  {
    this->usart_transmit_byte(_send_buffer.buffer_out());
  }
}

void utils::UsartDbg::usart_dbg_flush()
{
  while (!_send_buffer.buffer_empty())
  {
    while (!_usart_buffer_empty())
    {
      // wait
    }
    this->usart_transmit_byte(_send_buffer.buffer_out());
  }
}

void utils::UsartDbg::print_ascii(std::uint8_t data)
{
  _send_buffer.buffer_in(data);
}

void utils::UsartDbg::print_hex_byte(std::uint8_t data)
{
  std::uint8_t high = data >> 4;
  if (high < 10)
  {
    _send_buffer.buffer_in(high + '0');
  }
  else
  {
    _send_buffer.buffer_in(high - 10 + 'A');
  }
  std::uint8_t low = data & UINT8_C(0x0F);
  if (low < 10)
  {
    _send_buffer.buffer_in(low + '0');
  }
  else
  {
    _send_buffer.buffer_in(low - 10 + 'A');
  }
}

void utils::UsartDbg::usart_transmit_byte(std::uint8_t data)
{
  mu.transmit_byte_no_blocking(data);
}

bool utils::UsartDbg::_usart_buffer_empty() { return mu.buffer_is_empty(); }