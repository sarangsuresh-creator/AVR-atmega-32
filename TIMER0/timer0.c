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
int i=0;

void main(void) {
    DDRB = 0Xff;
    PORTB = 0x00;
    TCCR0 = 0X05;
    TCNT0 = 177;
    TIMSK |= (1<<0);
    while(1){
        timer();
        
    }
  return;
}
void timer(){
    if(TIFR & (1<<0)){
        PORTB =~ PORTB;
        TCNT0 = 177;
        TIFR |= (1<<0);
        
    }
}

