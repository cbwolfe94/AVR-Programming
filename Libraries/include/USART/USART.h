//Can change BAUD rate and F_CPU if not explicitly defined in Makefile
#ifndef BAUD    
    #define BAUD 9600
#endif

#ifndef F_CPU
    #define F_CPU 16000000
#endif

#define MYUBRR ((F_CPU/(16UL*BAUD) - 1))

void initUSART(void);

void transmitByteUSART(unsigned int);

void transmitMessageUSART(const char[]);

unsigned int receiveUSART(void);
