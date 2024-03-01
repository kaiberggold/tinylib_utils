set( sources
    src/usart_dbg.cpp 
    src/digital_port.h
    src/usart_dbg.h
    src/digital_port.h
    )


cmake_print_variables(sources)

add_avr_library (usart ${sources})
target_include_directories (usart PUBLIC include)
target_include_directories (usart PUBLIC src)

avr_target_link_libraries(usart mcal)
