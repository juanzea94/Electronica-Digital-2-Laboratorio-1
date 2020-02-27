
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#ifndef __LABOR5_SLAVE2_H
#define	__LABOR5_SLAVE2_H

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
//
//#define GIE INTCONbits.GIE
//#define PEIE INTCONbits.PEIE
//#define SSPIF PIR1bits.SSPIF
//#define SSPIE PIE1bits.SSPIE
//#define CKP SSPCONbits.CKP
//#define SSPOV SSPCONbits.SSPOV
//#define WCOL SSPCONbits.WCOL

void I2C_Slave_Init(uint8_t address);
void setup (void);
void loop (void);

//Se declaran las variables del programa utilizadas en las funciones
uint8_t contador;
uint8_t antirebote;
uint8_t desecho;

#endif	/* XC_HEADER_TEMPLATE_H */