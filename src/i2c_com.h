#ifndef UTILS_I2C_COM
#define UTILS_I2C_COM
#include <cstdint>
#include <hal.h>
#include "circular_buffer.h"
#include <util/delay.h>

utils::UsartDbg dbg(9600);
namespace utils
{
    typedef void (*CallbackFunction)();
    enum class i2cCommand : std::uint8_t
    {
        start_e,
        stop_e,
        send_e,
        read_ack_e,
        read_no_ack_e
    };

    template <typename addr_t, typename reg_t, reg_t bus_idx, std::uint32_t freq>
    class I2cCom
    {
        CircularBuffer<std::uint8_t, 20> _i2c_buffer;
        CircularBuffer<CallbackFunction, 10> _call_back_puffer;
        bool _transmission_active;
        // const reg_t _bus_idx;

    public:
        constexpr I2cCom()
        {
            static_assert(freq == 100000 || freq == 400000 || freq == 1000000, "only 100000,400000,1000000 allowed as i2c frequency");
        }

        // I2cCom() {}

        void buffer_reset()
        {
            _i2c_buffer.reset();
        }
        void init()
        {
            hal::HalI2CCom<addr_t, reg_t, bus_idx>::init(freq);
            _transmission_active = false;
            //    TWBR = 92;           /* set bit rate, see p. 242 */
            /* 20MHz / (16+2*TWBR*1) ~= 100kHz */
            //  TWCR |= (1 << TWEN); /* enable */
        }
        void send(std::uint8_t data)
        {
            _i2c_buffer.buffer_in(static_cast<std::uint8_t>(i2cCommand(utils::i2cCommand::send_e)));
            _i2c_buffer.buffer_in(data);
        }
        void start()
        {
            _i2c_buffer.buffer_in(static_cast<std::uint8_t>(i2cCommand(utils::i2cCommand::start_e)));
        }

        void stop()
        {
            _i2c_buffer.buffer_in(static_cast<std::uint8_t>(i2cCommand(utils::i2cCommand::stop_e)));
        }
        void transmit()
        {
            if (!_i2c_buffer.buffer_empty())
            {
                i2cCommand c = static_cast<i2cCommand>(_i2c_buffer.buffer_out());
                switch (c)
                {
                case utils::i2cCommand::start_e:
                    hal::HalI2CCom<addr_t, reg_t, bus_idx>::start();
                    _transmission_active = true;
                    break;
                case utils::i2cCommand::stop_e:
                    hal::HalI2CCom<addr_t, reg_t, bus_idx>::stop();
                    _transmission_active = false;
                    break;
                case utils::i2cCommand::send_e:
                    hal::HalI2CCom<addr_t, reg_t, bus_idx>::send(_i2c_buffer.buffer_out());
                    _transmission_active = true;
                    break;
                default:
                    break;
                }
            }
        }

        void flush_blocking()
        {
            while ((!_i2c_buffer.buffer_empty()))
            {
                this->transmit();

                while (transmission_active())
                {
                    //                    dbg.usart_transmit_byte(i + 65);
                }
            }
        }

        bool transmission_active()
        {
            if (_transmission_active)
                _transmission_active = hal::HalI2CCom<addr_t, reg_t, bus_idx>::transmission_active();
            return _transmission_active;
        }
    };
}
#endif