#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

int main()
{
    DDRB = 1 << 5; // PB5 (pin 13 LED) is set to output

    while(1)
    {
        PORTB |= 1 << 5;
        _delay_ms(200);

        PORTB &= ~(1 << 5);
        _delay_ms(200);
    }
    return 0;
}
