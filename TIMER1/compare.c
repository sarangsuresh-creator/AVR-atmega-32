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
    DDRD = 0Xff;
    PORTD = 0x00;
    TCCR1A = 0X40;
    TCCR1B = 0x05;
    TCNT1 = 0;
    OCR1A = 32767;
    while(1){ }
    
    
    
  return;
}

