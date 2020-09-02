                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  DDRB = 0xff;            
  DDRC = 0xff;
  DDRD = 0xff;
  // ------ Event loop ------ //
  while (1) {
    
    PORTB = (1 << 0);
    _delay_ms(250);
    PORTB = (0 << 0);

    PORTC = (1 << 0);
    _delay_ms(250);
    PORTC = (0 << 0);

    PORTD = (1 << 0);
    _delay_ms(250);
    PORTD = (0 << 0);
  }
    return 0;
}
