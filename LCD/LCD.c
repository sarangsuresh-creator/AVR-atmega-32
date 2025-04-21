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
#define RS PC0
#define RW PC1
#define EN PC2
void command( char cmd);
void data(char data);
void string(const char *s);
void lcd_initialize();

void main(void) {
    DDRC = 0Xff;
    DDRD = 0Xff;
    DDRB = 0x0f;
    PORTB = PORTC = PORTD = 0X00;
    lcd_initialize();
    while(1){
      command(0x80);
      string("hello");
      
    }
 
  return;
}
void command(char cmd){
    PORTD = cmd;
    PORTC &= ~(1<<RS);
    PORTC &= ~(1<<RW);
    PORTC |= (1<<EN);
    _delay_ms(5);
    PORTC &= ~(1<<EN);
}
void data(char data){
    PORTD = data;
    PORTC |= (1<<RS);
    PORTC &= ~(1<<RW);
    PORTC |= (1<<EN);
    _delay_ms(5);
    PORTC &= ~(1<<EN);
}
void string(const char *s){
    while(*s){
        data(*s++);
    }
}
void lcd_initialize(){
    command(0x38);
    command(0X80);
    command(0X0c);
    command(0X06);
}

