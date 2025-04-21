/*
 * File:   sample.c
 * Author: LENOVO
 *
 * Created on 17 April, 2025, 9:39 AM
 *makig a delay of 10 ms*/

#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void main(void) {
    DDRD = 0x00;
    PORTD = 0X00;
    DDRB = 0Xff;
    PORTB = 0X00;
    MCUCR = 0X0c;
    GICR = (1<<INT1);
    sei();
    while(1){
        
      
    }
 
  return;
}
ISR(INT1_vect){
    PORTB ^= (1<<7);
}


