#ifndef USART_I2C
#define USART_I2C
#include <cstdint>
#include <hal.h>
#include "circular_buffer.h"

namespace utils
{

    enum i2cCommand
    {
        start,
        stop,
        send,
        read_ack,
        read_no_ack
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

    template <typename addr_t, typename reg_t, const std::uint32_t freq, const std::uint8_t bus_idx>
    class I2cCom
    {
        I2cCircularBuffer<std::uint8_t, 255> _i2c_buffer;

    public:
        void init()
        {
            hal::HalI2CCom<addr_t, reg_t, freq, bus_idx>::init();
        }
        void send(std::uint8_t data)
        {
            _i2c_buffer.buffer_in(static_cast<std::uint8_t>(i2cCommand(send)));
            _i2c_buffer.buffer_in(data);
        }
        void start()
        {
            _i2c_buffer.buffer_in(static_cast<std::uint8_t>(i2cCommand(start)));
        }

        void stop()
        {
            _i2c_buffer.buffer_in(static_cast<std::uint8_t>(i2cCommand(stop)));
        }
        void transmit()
        {
            if (!_i2c_buffer.buffer_empty())
            {
                i2cCommand c = _i2c_buffer.buffer_out();
                switch (c)
                {
                case start:
                    start();
                    break;
                case stop:
                    stop();
                    break;
                case send:
                    send();
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
            return hal::HalI2CCom<addr_t, reg_t, freq, bus_idx>::transmission_active();
        }
    };
}
#endif