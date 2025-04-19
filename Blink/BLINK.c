/*
 * File:   sample.c
 * Author: sarang
 *
 * Created on 17 April, 2025, 9:39 AM
 */

#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

void main(void) {
    DDRB = 0xff;
    PORTB = 0x00;
    while(1){
        PORTB |= (1<<4)|(1<<6);
        _delay_ms(1000);
        PORTB &= ~((1<<4)|(1<<6));
        _delay_ms(1000);
    }
    return;
}

