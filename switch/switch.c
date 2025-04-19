/*
 * File:   sample.c
 * Author: LENOVO
 *
 * Created on 17 April, 2025, 9:39 AM
 */

#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
int i=0;

void main(void) {
    DDRB = 0X00;
    DDRC = 0Xff;
    PORTC = 0X00;
    PORTB = 0x00;
    while(1){
        if(PINB & (1<<4)){
            i++;
            while(PINB &(1<<4));
        }
        if(i==1){
            PORTC = 0X01;
            }
        else if(i==2){
                PORTC = 0X02;
        }
        else if(i==3){
            PORTC = 0x04;
         
        }
        else if(i==4){
            PORTC = 0X08;
            i=0;
        }
    }
        
    return;
}

