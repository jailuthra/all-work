name=a	
CFLAGS=-mmcu=atmega328p
CC=avr-gcc

all: $(name).hex

$(name).hex: $(name).elf
	avr-objcopy -O ihex $(name).elf $(name).hex

$(name).elf: $(name).c
	$(CC) $(CFLAGS) -o $(name).elf $(name).c

clean:
	rm -rf *.o *.hex *.elf
