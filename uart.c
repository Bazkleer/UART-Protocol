#include "uart.h"

void uart_init(){

  //set the communication Baud Rate
  UBRRH = (BAUDRATE>>8);
  UBRRL = BAUDRATE;
  //Enable Reciver and Transmit
  UCSRB |= (1<<TXEN)|(1<<RXEN);
  //select 8-bit data format
  UCSRC |= (1<<URSEL)|(1<<USCZ0)|(1<<USCZ1);
}


void uart_transmit(uint8_t data){
  //wait until the data register is empty
  while( ! ( UCSRA & (1 << UDRE) ) );
  //set the data to the data Register
  UDR=data;
}

uint8_t uart_read(void){
  //wait until the ongoing transmission completes
  while(! (UCSRA & ( 1 << RXC) ) );
  //return the value in the UDR register
  return UDR;
}

void UART_Transmit_string (char * str){
  uint8_t idx=0;
  while(str[idx]!='\0'){
    uart_transmit(str[i++]);
  }
}
