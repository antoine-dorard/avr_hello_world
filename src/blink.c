#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
    DDRB |= _BV(DDB0); // Set pin
    
    while(1) 
    {
        PORTB ^= _BV(PB0);
        _delay_ms(500);
    }

    /*
    DDRB: Data Direction Register for B Ports (input is 0 and ouput is 1)
    DDB0: bit nb for the Data Direction Register B
    PORTB: Data Register for Port B
    PB0: bit nb for the Data Register B
    PINB: Input Pins Address for Port B
    _BV(x): macro that returns a byte with only the bit x set to 1 (1 << x)
    */

}