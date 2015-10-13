#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

int main()
{
    DDRB &= ~(1 << 0); // PB0 is input to toggle which LED blinks
    DDRB |= (3 << 1); // PB1 and PB2 are outputs for the two LEDs
    PORTB |= 1 << 0; // PB0 is pulled up
    int c = 0;
    while (1) {
        _delay_ms(10);
        // If PB0 goes 0, toggle c
        if (!(PINB & (1 << 0))) {
            c ^= 1; 
            _delay_ms(100);
        }

        // If c is 0, blink PB1, if c is 1, blink PB2
        PORTB |= 1 << (1 + c);
        _delay_ms(100);

        PORTB &= ~(1 << (1 + c));
        _delay_ms(100);
    }
            
    return 0;
}
