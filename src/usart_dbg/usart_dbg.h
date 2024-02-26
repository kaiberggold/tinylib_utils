
#include <cstdint>
#include <array>

#include <mcal.h>
namespace usart{

    class UsartDbg
    {
    private:
        //constexpr std::array<std::uint8_t, std::uint8_t buffer_size> send_buffer;

    public:

        void send_byte(uint8_t data);
        void usart_dbg_step();
        
    };
}