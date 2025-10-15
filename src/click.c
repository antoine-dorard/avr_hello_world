#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(){

    // Set PORTB 0 to output (1)
    DDRB |= _BV(DDB0);

    // Set PORTB 1 to input (0)
    DDRB &= ~_BV(DDB1);

    // Set internal pull up 
    //PORTB |= _BV(PB1); // No need to use the internal pull UP since we need to set an external pull DOWN resistor

    while(1){

        if (PINB & _BV(PB1)) PORTB &= ~_BV(PB0);
        else PORTB |= _BV(PB0);
        _delay_ms(10);
    }

    return 0;
}