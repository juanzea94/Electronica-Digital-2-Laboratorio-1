
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LABOR4SLAVE_H
#define	__LABOR4SLAVE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000

#define SS TRISAbits.TRISA5
#define SCK TRISCbits.TRISC3
#define SDO TRISCbits.TRISC5
#define SDI TRISCbits.TRISC4
#define POT1 TRISAbits.TRISA1
#define POT2 TRISAbits.TRISA6


//****************************************************************************//
//**********************************VARIABLES**********************************//
//****************************************************************************//

uint8_t valana;
uint8_t m;
char pot1;
char buffer [20];
uint8_t num1;
uint8_t num2;
uint8_t num3;
float number;
unsigned char slaveIn;
unsigned char slaveOut;
uint8_t variableValeVerga;

//****************************************************************************//
//**********************************PROTOTIPOS**********************************//
//****************************************************************************//

void adcInit (void);
void POT (void);
//void IntToString (float number);
void spiSlaveInit();
void spiWrite(char dat);
unsigned spiDataReady();
char spiRead();
void spiFunctionReadMaster(void);
void spiFunctionWriteMaster(void);

#endif	/* XC_HEADER_TEMPLATE_H */

