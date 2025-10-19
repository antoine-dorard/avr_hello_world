#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t adc_result = 0;

void start_ADC_conversion(){
    /* Trigger a conversion, two options:
        1. set ADSC in ADCSRA to manually trigger a conversion (will be set to 0 when conversion is finished)
        2. set ADATE in ADCSRA to enable auto trigger, which exepts to have the source specified with ADTS[2:0] (ADTriggerSource) in ADCSRB
            - The default trigger source 0b000 is 'Free Running Mode'
    */
    ADCSRA |= _BV(ADSC);
}

void setup_ADC(){
    // enable ADC with ADEN in ADCS

    ADMUX |= 3; // Select ADC3 (PC3)
    ADMUX |= _BV(ADLAR); // Left adjust the 10 bits of the ADC result
    ADMUX |= _BV(REFS0); // Set reference voltage to AVcc (5V)

    ADCSRA |= _BV(ADEN); // Enable ADC
    ADCSRA |= _BV(ADIE); // Enable ADC interrupt
    ADCSRA |= _BV(ADPS1) |  _BV(ADPS0); // set prescaler to 8 (125kHz ADC clock with 1MHz system clock)

    start_ADC_conversion(); // start the first conversion

}

void setup_PWM(){
    /* PWM - Using the Timer/Counter
        Activate the timer:
        - Set CS[2..0] in TCCR0B to set the clock source. 0b000 is no clock. 
        Set WGM0[2..0] in TCCR0A to activate FastPWM mode. Hint: Set it to 7
        Set COM0xn in TCCR0A to set the OC0x pins behavior 
        Set the ports OC0A and/or/? OC0B to output 
    */

    TCCR0A |= (1<<WGM01) | (1<<WGM00); // set WGM01 and WGM00 for FastPWM mode (WGM02 is 0 by default so that TOP is 0xFF and not OCR0A)
    TCCR0B |= (1<<CS00); // set clock source to clk (no prescaling)

    TCCR0A |= (1<<COM0B1); // set COM0B1 and COM0B0 to 1 and 1 respectively for inverting mode (which activates the OCB port by definition)

    DDRD |= _BV(PD5); // Set direction of port pin 5 (OC0B)

    OCR0B = 128; 

}

int main(void){

    setup_ADC();
    setup_PWM();
    sei(); // enable global interrupts

    while(1){
        OCR0B = adc_result; // Set the compare value to the ADC result
    }
    
    return 0;
}


ISR(ADC_vect){
    adc_result = ADCH;
    start_ADC_conversion();
}
