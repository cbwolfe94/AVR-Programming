MCU   = atmega328p
PROGRAMMER_TYPE = usbtiny
F_CPU = 16000000UL  
BAUD  = 9600UL
LFUSE = 0xFF
HFUSE = 0xD9
EFUSE = 0x07

FUSES = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(SOURCES:.c=.h)

CC = avr-gcc
CFLAGS = -Wall -Os -I
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude -c $(PROGRAMMER_TYPE) -p $(MCU) 
TARGET_ARCH = -mmcu=$(MCU)
TARGET = main

COMPILE = $(CC) $(CFLAGS) -DF_CPU=$(F_CPU) $(TARGET_ARCH)


%.o: %.c $(HEADERS)
	$(COMPILE) -c -o $@ $<

$(TARGET).elf: $(OBJECTS)
	$(COMPILE) $(OBJECTS) -o $@

$(TARGET).hex: $(TARGET).elf
	rm -f main.hex
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

verify:
	$(AVRDUDE)

write_fuses:
	$(AVRDUDE) $(FUSES)

get_fuses: 
	$(AVRDUDE) -nv

flash: main.hex
	$(AVRDUDE) -U flash:w:$(TARGET).hex

debug:
	@echo
	@echo "Source files:"   $(SOURCES)
	@echo "Header files:"   $(HEADERS)
	@echo "Object files:"   $(OBJECTS)
	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
	
clean:
	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).obj \
	$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
	$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
	$(TARGET).eeprom

squeaky_clean:
	rm -f *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom
