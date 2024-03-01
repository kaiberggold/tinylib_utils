#include "usart_dbg.h"
#include <cstdint>
#include <mcal_usart.h>

//#include <util/setbaud.h>





void utils::UsartDbg::usart_dbg_init()
{
  mu.init(baud_rate);
};



void utils::UsartDbg::usart_dbg_step()
{
  if (!this->_ring_buffer_empty())
  {
       this->usart_transmit_byte(this->_ring_buffer_out());
  }
}

void utils::UsartDbg::print_ascii(std::uint8_t data)
{
    this->_ring_buffer_in(data);
}

void utils::UsartDbg::_ring_buffer_in(std::uint8_t data)
    {
        if (_n<buffer_size)
        {
            _send_buffer[_pos_in]=data;
            if (_pos_in< UINT8_MAX)
            {
                _pos_in++;
            }
            else
            {
                _pos_in=0;
            }
            _n++;
        }
        // no else, just do nothing if buffer is full
    }

std::uint8_t utils::UsartDbg::_ring_buffer_out()
{
    std::uint8_t out;
    if (_n>0)
    {
        out=_pos_out;
        if (_pos_out< UINT8_MAX)
            {
                _pos_out++;
            }
            else
            {
                _pos_out=0;
            }
        _n--;
        return _send_buffer[out];
    }
    else
    {
        return 0; // should not happen
    }
}

bool utils::UsartDbg::_ring_buffer_empty()
    {
        return _n==0;
    }

void utils::UsartDbg::usart_transmit_byte(std::uint8_t data)
    {
        mu.transmit_byte_no_blocking(data);
    }
 
bool utils::UsartDbg::_usart_buffer_empty()
    {
        return mu.buffer_is_empty();
    }