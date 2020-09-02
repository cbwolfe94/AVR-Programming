// POV toy demo framework //

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>

// -------- Functions --------- //
void POVDisplay(uint8_t oneByte) {
  PORTB = oneByte;
  _delay_ms(75);
}

int main(void) {
  // -------- Inits --------- //
  DDRB = 0xff;                    /* Set up all of LED pins for output */
  // ------ Event loop ------ //
  while (1) {                                              /* mainloop */
    POVDisplay(0b00000001);
    POVDisplay(0b00000010);
    POVDisplay(0b10000100);
  }                                                    /* end mainloop */
  return 0;
}
