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
    TCCR1A = 0X00;
    TCCR1B = 0x07;
    TCNT1 = 0;
    while(1){
        if(TCNT1 == 1){
            PORTB ^= (1<<7);
            TCNT1 = 0;
            
        }
    
    }
    
  return;
}

