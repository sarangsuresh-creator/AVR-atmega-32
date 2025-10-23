/*
 * File:   uart.c
 * Author: LENOVO
 *
 * Created on 20 June, 2025, 11:19 AM
 */


#define F_CPU 8000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include<string.h>
void newline();
char a[100];
int i=0;
void main(void) {
     DDRD |= (1<<PD1);
    DDRD &= ~(1<<PD0);
    PORTD = 0x00;
    UCSRA = 0X00;
    UCSRB = 0X18;
    UCSRC = 0X86;
    UBRRL = 51;
    while(1){
    while(!(UCSRA&(1<<RXC)));
    char s = UDR;
    if((s=='\r')){
        newline();
        char temp;
      for(i = 0;i<(((strlen(a)))/2);i++ ){
        temp=a[i];
        a[i]=a[(((strlen(a))-1)-i)];
        a[(((strlen(a))-i)-1)]=temp;
      }
      i=0;
     while(a[i]){
        while(!(UCSRA &(1<<UDRE)));
            UDR = a[i++];
         
     } 
        i=0;
        newline();
    }
    else
    {
      a[i++]=s; 
      while(!(UCSRA&(1<<5)));
      UDR = s;
    }
    

    }
    return;
}
void newline(){
         while(!(UCSRA&(1<<5)));
      UDR = '\r';
             while(!(UCSRA&(1<<5)));
      UDR = '\n';
      return;
}
