#ifndef USART_DBG
#define USART_DBG

#include "hal_usart.h"
#include <array>
#include <cstdint>
#include <cstring>
#include "circular_buffer.h"
#
namespace utils
{

  class UsartDbg
  {
  private:
    std::uint16_t baud_rate;

    CircularBuffer<std::uint8_t, 255> _send_buffer;

    bool _usart_buffer_empty();
    hal::HalUsart mu;

  public:
    UsartDbg(std::uint32_t baud_rate)
    {
      this->usart_dbg_init(baud_rate);
    }

    template <typename T>
    void print_decimal(T value);
    void print_text(const char text[]);
    void print_ascii(std::uint8_t value);
    void print_hex_byte(std::uint8_t value);
    void usart_dbg_step();
    void usart_dbg_flush();
    void usart_dbg_init(std::uint32_t baud_rate);
    void usart_transmit_byte(std::uint8_t);
  };
} // namespace utils
#endif // USART_DBG
