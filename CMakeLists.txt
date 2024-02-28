set( sources
    src/usart_dbg/usart_dbg.cpp 
    src/usart_dbg/digital_out.cpp
    include/usart_dbg.h
    include/digital_out.h

)

cmake_print_variables(sources)

add_avr_library (usart ${sources})
target_include_directories (usart PUBLIC include)
avr_target_link_libraries(usart mcal)
