//Change defines if need be
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <stdint.h>
#include "ADC.h"

//Rerence selection bits can be changed
//Prescaler is dependent on F_CPU and desired ADC frequency. In this case, I'm using a 16 MHz oscillator with a prescaler of 128 for an
//ADC frequency of 125 kHz. The lower the frequency, the higher the resolution. And vice versa.

void initADC(void) {
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    ADCSRA |= (1 << ADEN);
}

//Channel is selected using the internal multiplexer. Returns value stored in ADC registered.
uint16_t readADC(uint8_t adcChannel) {
    ADMUX = (ADMUX & 0xF0) | (adcChannel & 0x0F);
    ADCSRA |= (1 << ADSC);
    while(ADCSRA & (1<<ADSC));
    return ADC;
}
