#ifndef _UART_H_
#define _UART_H_

#include <avr/io.h>
#define _FCPU 8000000UL
#include <util/delay.h>



#define  FOSC        8000000// Clock Speed
#define  BAUD        9600
#define  BAUDRATE    ((FOSC)/(BAUD*16UL)-1)


/*********************************************************************
* Function    : uart_init();
*
* DESCRIPTION : initialize the UART
*
* PARAMETERS  : none
*
* Return Value: Nothing
***********************************************************************/
void uart_init();



/*********************************************************************
* Function    : uart_transmit(uint8_t data);
*
* DESCRIPTION : transmit data
*
* PARAMETERS  : uint8_t data
*
* Return Value: Nothing
***********************************************************************/
void uart_transmit(uint8_t data);



/*********************************************************************
* Function    : uart_receive(void);
*
* DESCRIPTION : recieve data
*
* PARAMETERS  : none
*
* Return Value: UDR value (UART Data Register)
***********************************************************************/
uint8_t uart_receive(void);



/*********************************************************************
* Function    : uart_transmit_string (char * str);
*
* DESCRIPTION : transmit each cahracter of the string
*
* PARAMETERS  : char * str
*
* Return Value: Nothing
***********************************************************************/
void uart_transmit_string (char * str);


#endif
