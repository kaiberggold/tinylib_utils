#ifndef MP44XX
#define DIGITAL_POTI_IC
#include <cstdint>
#include <hal.h>
#include "i2c_com.h"
namespace utils
{
    // Forward declaration

    template <typename addr_t, typename reg_t, reg_t bus_idx>
    class PotiIc
    {
    private:
        utils::I2cCom<addr_t, reg_t, bus_idx> _i2c;
        addr_t _address;
        addr_t _chip_select;

    public:
        PotiIc(addr_t a, addr_t c, utils::I2cCom<addr_t, reg_t, bus_idx> i) : _address(a), _chip_select(c), _i2c(i)
        {
            // Constructor body
        }

        void set_val_volatile(reg_t poti_id, std::uint16_t value)
        {
            unsigned char Register = 0;
            unsigned char firstCommandByte = 0x00;  // Prep the firstCommandByte with 00b for writes
            unsigned char secondCommandByte = 0x00; // Empty data byte
            unsigned short tempWord = value;
            unsigned char tempByte;
            Register *= 16;                                // Shift the value of Register to the left by four bits
            firstCommandByte |= Register;                  // Load the register address into the firstCommandByte
            tempWord &= 0x0100;                            // Clear the top 7 bits and the lower byte of the input value to pick up the two data bits
            tempWord /= 256;                               // Shift the top byte of the input value to the right by one byte
            tempByte = (unsigned char)(tempWord);          // Store the top byte of the input value in a byte sized variable
            firstCommandByte |= tempByte;                  // Load the two top input data bits into the firstCommandByte
            tempWord = value;                              // Load the input value into the tempWord
            tempWord &= 0x00FF;                            // Clear the top byte
            secondCommandByte = (unsigned char)(tempWord); // Store the lower byte of the input value in the secondCommandByte

            _i2c.start();
            _i2c.send(88);
            _i2c.send(firstCommandByte);
            _i2c.send(secondCommandByte);
            _i2c.stop();
        }
    };

} // namespace utils

#endif