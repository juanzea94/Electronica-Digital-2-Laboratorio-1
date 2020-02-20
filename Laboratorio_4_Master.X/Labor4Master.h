
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LABOR4MASTER_H
#define	__LABOR4MASTER_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000

#define SS TRISAbits.TRISA4
#define SCK TRISCbits.TRISC3
#define SDO TRISCbits.TRISC5
#define SDI TRISCbits.TRISC4
#define CONTADOR TRISB
#define BANDERA TRISAbits.TRISA1
#define SYNC TXSTAbits.SYNC
#define SPEN RCSTAbits.SPEN
#define TX TRISCbits.TRISC7
#define RX TRISCbits.TRISC6
#define CREN RCSTAbits.CREN
#define TXEN TXSTAbits.TXEN
#define BRGH TXSTAbits.BRGH
#define TX9 TXSTAbits.TX9
#define RX9 RCSTAbits.RX9
#define BRG16 BAUDCTLbits.BRG16

//****************************************************************************//
//**********************************VARIABLES**********************************//
//****************************************************************************//

char dat;
unsigned char masterIn;
unsigned char masterOut;

//****************************************************************************//
//**********************************PROTOTIPOS**********************************//
//****************************************************************************//

void UARTR (void);
void UARTW (void);
char UART_Init(const long int baudrate);
char UART_TX_Empty();
char UART_Data_Ready();
char UART_Read();
void UART_Read_Text(char *Output, unsigned int length);
void UART_Write(char data);
void UART_Write_Text(char *text);

void spiMasterInit(void);
void spiWrite(char dat);
unsigned spiDataReady();
char spiRead();
void spiFunctionReadSlave (void);
void spiFunctionWriteSlave (void);

#endif	/* XC_HEADER_TEMPLATE_H */

