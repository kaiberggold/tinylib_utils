#ifndef M23X512_
#define M23X512_
namespace utils
{
    template <typename addr_t, typename reg_t, typename byte_com_static_t, typename digital_pin_t>
    struct M23X512
    {
        static void
        write_byte()
        {
            //;
        }

        static void init()
        {
            digital_pin_t::set_pin(false);
        }

        static void disable()
        {
            digital_pin_t::set_pin(true);
        }

        static reg_t read()
        {
            return 0;
            // byte_com_static_t::read();
        }

        static void bus_transmission_wait_blocking()
        {
            while (byte_com_static_t::transmission_active())
            {
                // wait
            }
        }
    };

}

#endif