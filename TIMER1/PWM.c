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
    DDRD = 0Xff;
    PORTD = 0x00;
    TCCR1A = 0X83;
    TCCR1B = 0x0d;
    SREG = (1<<7);
    TIMSK = (1<<2);
    
    
    while(1){ 
        
    for(i=800;i<1023;i++){
      OCR1A = i;
      _delay_ms(10);
    }
     for(i=1023;i>800;i--){
      OCR1A = i;
      _delay_ms(10);
    }
    }
    
    
    
  return;
}
ISR(TIMER1_OVF_vect){
    TCNT1 = 800;
}


