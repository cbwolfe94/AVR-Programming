#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include "Timers.h"


//Available prescaler values: 0(No clock source), 1(No prescaling), 2(1/8 prescaling), 3(1/64 prescaling),
//4(1/256 prescaling), 5(1/1024 prescaling), 6(External clock source on T0 pin. Clock on falling edge),
//7(External clock source on T0 pin. Clock on rising edge)

void initFastPWM0(int prescaler) {
    TCCR0A |= (1<<WGM01)|(1<<WGM00)|(1<<COM0A1)|(1<<COM0B1);
    TCCR0B = prescaler;
}

void initFastPWM1(int prescaler) {

}

void initFastPWM2(int prescaler) {

}