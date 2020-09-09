#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <stdlib.h>
#include <avr/io.h>
#include <avr/delay.h>
#include "ADC.h"
#include "USART.h"

int main(){
    int sensorValue;
    char voltageString[5];

    initADC();
    initUSART();

    while(1) {

        sensorValue = readADC(0);
        float voltage = sensorValue*(5.0)/(1023.0);
        dtostrf(voltage, 3, 2, voltageString);
        transmitMessageUSART(voltageString);
        transmitByteUSART(10);
        _delay_ms(1000);
       
    }
    
    return 0;
}