#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

int main() {
    DDRB &= ~(1 << 3); // PB3 is input
    DDRB |= (1 << 5); // PB5 is output
    PORTB |= (1 << 3); // PB3 is pulled-up
    while (1) {
        _delay_ms(50);
        // If PB3 goes 0, toggle PB5 (we'll connect switch to gnd)
        if (!(PINB & (1<<3))) {
            PORTB ^= (1 << 5);
            _delay_ms(100);
        }
    }
    return 0;
}
