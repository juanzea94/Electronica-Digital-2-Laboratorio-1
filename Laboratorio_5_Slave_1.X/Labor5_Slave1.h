/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LABOR5_SLAVE1_H
#define	__LABOR5_SLAVE1_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000  


#define SDA TRISCbits.TRISC4
#define SCL TRISCbits.TRISC3
//#define SMP SSPSTATbits.SMP
//#define DnA SSPSTATbits.D_nA
//#define STOP SSPSTATbits.P
//#define START SSPSTATbits.S
//#define RnW SSPSTATbits.R_nW
//#define BF SSPSTATbits.BF
////
//#define GIE INTCONbits.GIE
//#define PEIE INTCONbits.PEIE
//#define SSPIF PIR1bits.SSPIF
//#define SSPIE PIE1bits.SSPIE
//#define CKP SSPCONbits.CKP
//#define SSPOV SSPCONbits.SSPOV
//#define WCOL SSPCONbits.WCOL

//Declaración de prototipos de funciones
void I2C_Slave_Init(uint8_t address);
//void __interrupt() i2cSlaveRead(void);
void print (void);
void adcInit (void);
void setup(void);

//Declaración de las variables no internas que se utilizan en el programa
uint8_t valana;
uint8_t desecho;
//short z;

/////////////////////MASTER////////////////////////

//void float2int (float valor);
//char valana1[8];
//char valana2[8];
//char valana3[8];
//float voltaje;
//int valanapot1;
//int valanapot2;
//int valanapot3;
//float valor;

//////////////////////MASTER/////////////////////////

#endif	/* XC_HEADER_TEMPLATE_H */

