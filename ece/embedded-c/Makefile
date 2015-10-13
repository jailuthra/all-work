CFLAGS=-mmcu=atmega328p
CC=avr-gcc

all: $(name).hex

$(name).hex: $(name).elf
	avr-objcopy -O ihex $(name).elf $(name).hex

$(name).elf: $(name).c
	$(CC) $(CFLAGS) -o $(name).elf $(name).c

clean:
	rm -rf *.o *.hex *.elf

push: all
	avrdude -c arduino -p atmega328p -P /dev/ttyACM0 -U flash:w:$(name).hex 
