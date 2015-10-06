#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

int main() {
    DDRB &= ~(1 << 3); // PB3 is input
    //DDRB |= (1 << 0); // PB0 is output
    DDRB |= (1 << 5); // PB5 is output
    PORTB &= ~(1 << 3); // PB3 is tristate
    while (1) {
        _delay_ms(50);
        /*
        bit = (PINB >> 3)&1;
        PORTB |= bit << 0; 
        */
        if (PINB & (1<<3)) {
            //PORTB |= (1 << 0);
            PORTB |= (1 << 5);
        } else {
            //PORTB &= ~(1<<0);
            PORTB &= ~(1<<5);
        }
    }
    return 0;
}
