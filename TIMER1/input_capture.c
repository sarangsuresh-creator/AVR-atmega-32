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
int i=0;

void main(void) {
    DDRB = 0X00;
    PORTB = 0x00;
    TCCR1A = 0X00;
    TCCR1B = 0x45;
    
    while(1){ }
 
  return;
}


