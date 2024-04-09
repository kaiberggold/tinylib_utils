
#include <stdint.h>

 

// Manually define the SPCR register address

constexpr uint8_t SPCR = 0x2C;

uint8_t step=0;

 

template <typename addr_t, typename reg_t, addr_t addr, reg_t value>

inline void __attribute__((always_inline)) writeToReg() {

    asm volatile (

        "sts %0, %1 \n\t"

        :

        : "M" (reinterpret_cast<volatile uint8_t*>(addr)), "r" (static_cast<uint8_t>(value))

        : "memory"

    );

}

 

template <typename addr_t, typename reg_t, reg_t value>

inline void __attribute__((always_inline)) writeToSPI() {

     writeToReg<addr_t,reg_t,SPCR,0x1F>();

  }




// Manually define the ISR for SPI_STC_vect

extern "C" void __vector_12(void) __attribute__((signal, used, externally_visible));

void __vector_12(void) {

    switch (step)

    {

     

           writeToSPI<uint8_t,uint8_t,0x1F>();  // Example with uint8_t template argument

           

    }

    step+=1;

    if (step>3)

    step=0;

}

 

 

 

Dr. Kai Berggold

Software Engineer

Magna Powertrain

 

Magna PT B.V. & Co. KG
Scarletallee 2
50735 Köln, Deutschland

BÜRO     +49-221-340272275

kai.berggold@magna.com

www.magna.com

 

 

