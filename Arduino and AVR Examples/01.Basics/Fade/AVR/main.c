#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/delay.h>
#include <Timers.h>




int main() {
    uint8_t fadeAmount = 5;
    uint8_t fadeDelay = 50;

    DDRB |= (1 << PB1);

    initFastPWM16Bit(1, 0, 0);

    while (1) {
        OCR1A = OCR1A + fadeAmount;

        if (OCR1A <= 0 || OCR1A >= 255) {
            fadeAmount = -fadeAmount;
            }
        _delay_ms(fadeDelay);
        
    }
    

    return 0;
}