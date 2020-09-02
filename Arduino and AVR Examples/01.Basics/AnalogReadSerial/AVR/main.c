#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#define F_CPU 16000000UL
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "USART.h"



int main() {
    int sensorValue;
    char sensorValueString[4];

    initUSART();
    initADC();
    
    while (1)
    {
        sensorValue = readADC(0);
        itoa(sensorValue, sensorValueString, 10);

        transmitMessageUSART(sensorValueString);

        transmitByteUSART(10);
        _delay_ms(1000);
    }

    return 0;
}