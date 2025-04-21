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
void lcd_initialize();
char keypad[4][4]={
    {'1','2','3','a'},
    {'4','5','6','b'},
    {'7','8','9','c'},
    {'#','0','*','d'}
};
char keypad_read(){
    while(1){
        char mychar[4]={0X0e,0X0d,0X0b,0X07};
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                PORTB = mychar[i];
                if((PINB & (1<<(j+4)))==0){
                    return keypad[i][j];
                }
            }
        }
    }
}
void main(void) {
    DDRC = 0Xff;
    DDRD = 0Xff;
    DDRB = 0x0f;
    PORTB = PORTC = PORTD = 0X00;
    lcd_initialize();
    while(1){
        char key = keypad_read();
        command(0X80);
        data(key);
     
      
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

void lcd_initialize(){
    command(0x38);
    command(0X80);
    command(0X0c);
    command(0X06);
}

