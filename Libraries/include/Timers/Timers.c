#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <stdint.h>
#include <avr/io.h>
#include "Timers.h"


//Available prescaler values: 0(No clock source), 1(No prescaling), 2(1/8 prescaling), 3(1/64 prescaling),
//4(1/256 prescaling), 5(1/1024 prescaling), 6(External clock source on T0 pin. Clock on falling edge),
//7(External clock source on T0 pin. Clock on rising edge). PWM0 is an 8 bit timer. 8 bits of resolution = 0 to 255 for OCR1A value

void initFastPWM8Bit0(uint8_t prescaler, uint8_t dutyCycleA, uint8_t dutyCycleB) {
    TCCR0A |= (1<<WGM01)|(1<<WGM00)|(1<<COM0A1)|(1<<COM0B1);
    TCCR0B = prescaler;
    OCR0A = dutyCycleA % 255;
    OCR0B = dutyCycleB % 255;
}


void initFastPWM16Bit(uint8_t prescaler, uint8_t dutyCycleA, uint8_t dutyCycleB) {
    TCCR1A |= (1<<WGM10)|(1<<COM1A1)|(1<<COM1B1);
    TCCR1B |= (1<<WGM12)|(prescaler);
    OCR1A = dutyCycleA % 255;
    OCR1B = dutyCycleB % 255;
}

void initFastPWM8Bit1(uint8_t prescaler, uint8_t dutyCycleA, uint8_t dutyCycleB) {
    OCR2A = dutyCycleA % 255;
    OCR2B = dutyCycleB % 255;
}