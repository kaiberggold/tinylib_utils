#include "usart_dbg.h"
#include <cstdint>
//#include <mcal.h>
//#include <util/setbaud.h>





void utils::UsartDbg::usart_dbg_init()
{
 
}



void utils::UsartDbg::usart_dbg_step()
{
  if (!this->_ring_buffer_empty())
  {
    if (this->_usart_buffer_empty())
    {
        this->_usart_transmit_byte(this->_ring_buffer_out());
    }
  }
};

void utils::UsartDbg::print_ascii(uint8_t data)
{
    this->_ring_buffer_in(data);
}

void utils::UsartDbg::_ring_buffer_in(std::uint8_t data){
    if (this->_n<this->buffer_size)
    {
        this->_send_buffer[_pos_in]=data;
        if (_pos_in< UINT8_MAX)
        {
            this->_pos_in++;
        }
        else
        {
            _pos_in=0;
        }
        this->_n++;
    }


}
