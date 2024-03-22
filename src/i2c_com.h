#ifndef USART_I2C
#define USART_I2C
#include <cstdint>
#include <hal.h>
#include "circular_buffer.h"
#include <avr/io.h>
#include <util/delay.h>
namespace utils
{
    typedef void (*CallbackFunction)();
    enum class i2cCommand
    {
        start_e,
        stop_e,
        send_e,
        read_ack_e,
        read_no_ack_e
    };
    template <typename T, std::uint8_t buffer_size>
    class I2cCircularBuffer : public CircularBuffer<std ::uint8_t, buffer_size>
    {
    private:
    public:
        // derived(T v) : base<T>{v} {}
        I2cCircularBuffer() : CircularBuffer<T, buffer_size>()
        {
        }

        // template <typename T, std::uint8_t buffer_size>
    };

    template <typename addr_t, typename reg_t, reg_t bus_idx>
    class I2cCom
    {
        I2cCircularBuffer<std::uint8_t, 255> _i2c_buffer;
        CircularBuffer<CallbackFunction, 10> _call_back_puffer;
        std::uint32_t _freq;
        // const reg_t _bus_idx;

    public:
        constexpr I2cCom(std::uint32_t f) : _freq(f)
        {
        }
        // I2cCom() {}
        void init()
        {
            hal::HalI2CCom<addr_t, reg_t, bus_idx>::init(_freq);
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
                    break;
                case utils::i2cCommand::stop_e:
                    hal::HalI2CCom<addr_t, reg_t, bus_idx>::stop();
                    break;
                case utils::i2cCommand::send_e:
                    hal::HalI2CCom<addr_t, reg_t, bus_idx>::send(_i2c_buffer.buffer_out());
                    break;
                default:
                    break;
                }
            }
        }

        void flush_blocking()
        {
            while (!_i2c_buffer.buffer_empty())
            {
                this->transmit();
                while (transmission_active())
                {
                    // wait;
                }
            }
        }

        bool transmission_active()
        {
            return hal::HalI2CCom<addr_t, reg_t, bus_idx>::transmission_active();
        }
    };
}
#endif