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
    TCCR0 = 0X07;
    while(1){
        if(TCNT0 == 1){
            PORTB ^= (1<<7);
            TCNT0 =0;
        }
    
    }
    
  return;
}

