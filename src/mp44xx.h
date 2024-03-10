#ifndef MP44XX
#define DIGITAL_POTI_IC
#include <cstdint>
#include <hal.h>
#include "i2c_com.h"
namespace utils
{
    // Forward declaration
    template <typename addr_t, typename reg_t, const std::uint32_t freq, const std::uint8_t bus_idx>
    class I2cCom;

    template <const std::uint8_t address, const std::uint8_t chip_select>
    class Mp44xx
    {
    private:
        utils::I2cCom<std::uint8_t, std::uint8_t, /* provide i2c_freq and bus_idx here */> *_i2c;

    public:
        // Constructor
        Mp44xx(utils::I2cCom<std::uint8_t, std::uint8_t, /* provide i2c_freq and bus_idx here */> *i2c) : _i2c(i2c)
        {
            // Constructor body
        }
    };

    // template <typename addr_t, typename reg_t, const std::uint32_t freq, const std::uint8_t bus_idx, const reg_t address, const reg_t chip_select>
    // class Mp44xx
    // {
    // private:
    //     utils::I2cCom<addr_t, reg_t, freq, bus_idx> *_i2c;

    // public:
    //     Mp44xx(auto *i2c) : _i2c(i2c){

    //                         };

    //     void set_val_volatile(reg_t poti_id)
    //     {
    //         _i2c->send(address);
    //     }
    // };
} // namespace utils

#endif