#include <cstdint>
#include <mcal.h>

namespace utils
{
    template<mcal::r::port_type port_id_type,std::uint8_t pin_type>
    class DigitalOut: public mcal::dio::McalDigitalOut
    {
        public:
         DigitalOut() : mcal::dio::McalDigitalOut(port_id_type,pin_type)
        {
        }   
    };

}