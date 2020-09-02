#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <stdint.h>
#include "USART.h"

void initUSART(void) {
    UBRR0H = (MYUBRR>>8);
    UBRR0L = MYUBRR;
    UCSR0B |= (1<<TXEN0)|(1<<RXEN0);
    UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);
}

void transmitByteUSART(unsigned int data) {
    while (!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

void transmitMessageUSART(const char message[]) {
    uint8_t index = 0;
    while(message[index]) {
        transmitByteUSART(message[index]);
        index++;
    }
}

unsigned int receiveUSART(void) {
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}