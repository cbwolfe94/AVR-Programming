#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>


int main() {

    DDRB |= (1<<PB1)|(1<<PB2);
    TCCR1A |= (1<<WGM10);
    TCCR1B |= (1<<WGM12)|(1<<CS10);
    TCCR1A |= (1<<COM1A1)|(1<<COM1B1);
    OCR1A = 127;
    OCR1B = 63;

    while(1) {
        
    }

    return 0;
}