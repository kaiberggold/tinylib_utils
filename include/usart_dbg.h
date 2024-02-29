#ifndef USART_DBG
  #define USART_DBG


#include <cstdint>
#include <array>
#include <mcal_usart.h>
#include <cstring>

#ifndef BAUD                          
#define BAUD  9600                    
#endif

namespace utils{

    class UsartDbg
    {
    private:
        constexpr static  std::uint8_t buffer_size =255;
        std::array<std::uint8_t, buffer_size> _send_buffer;
        std::uint8_t _pos_in;
        std::uint8_t _pos_out;
        std::uint8_t _n;
        
        void _ring_buffer_in(std::uint8_t data);
        std::uint8_t _ring_buffer_out();
        bool _ring_buffer_empty();


        bool _usart_buffer_empty();
        mcal::us::McalUsart mu;



        

    public:
        UsartDbg()
        {
            _pos_in=0;
            _pos_out=0;
            _n=0;
        }
 
        template <typename T> void print_decimal(T value);
        void print_text(const char text[]);
        void print_ascii(std::uint8_t value);
        void usart_dbg_step();
        void usart_dbg_init();
        void usart_transmit_byte(std::uint8_t);     
    };
}
#endif // USART_DBG
