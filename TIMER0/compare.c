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
    TCCR0 = 0X15;
    TCNT0 = 0;
    OCR0 = 150;
    while(1);  
    
  return;
}

