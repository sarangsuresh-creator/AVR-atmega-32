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
void transmit(const char *data){
    while(*data){
        while(!(UCSRA & (1<<UDRE)));
        UDR = *data++;
        
        
    }
}
void write(char dat){
    while(!(UCSRA & (1<<UDRE)));
        UDR = dat;
}
char receive(){
    while(!(UCSRA & (1<<RXC)));
        return UDR;
    
}
void main(void) {
    DDRD |= (1<<PD1);
    DDRD &= ~(1<<PD0);
    PORTD = 0x00;
    UCSRA = 0X00;
    UCSRB = 0X18;
    UCSRC = 0X86;
    UBRRL = 51;
    transmit("type anything\r\n\t");
    while(1){
       write(receive()); 
    }
 
  return;
}


