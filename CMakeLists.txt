set( sources
    src/usart_dbg.cpp 
    src/digital_port.h
    src/digital_pin.h
    src/usart_dbg.h
    src/digi_poti.h
    src/circular_buffer.h
    src/i2c_com.h
    src/spi_com.h
    src/mp44xx.h
    )


cmake_print_variables(sources)
include_directories ("../tinylib_hal/src/${HAL_PATH}")
add_avr_library (utils ${sources})
target_include_directories (utils PUBLIC include)
target_include_directories (utils PUBLIC src)

avr_target_link_libraries(utils hal)
