
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LABOR5_SLAVE3_H
#define	__LABOR5_SLAVE3_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000  

#define SDA TRISCbits.TRISC4
#define SCL TRISCbits.TRISC3
#define SMP SSPSTATbits.SMP
#define DnA SSPSTATbits.D_nA
#define STOP SSPSTATbits.P
#define START SSPSTATbits.S
#define RnW SSPSTATbits.R_nW
#define BF SSPSTATbits.BF

#define GIE INTCONbits.GIE
#define PEIE INTCONbits.PEIE
#define SSPIF PIR1bits.SSPIF
#define SSPIE PIE1bits.SSPIE
#define CKP SSPCONbits.CKP
#define SSPOV SSPCONbits.SSPOV
#define WCOL SSPCONbits.WCOL
#define ECHO TRISDbits.TRISD3
#define TRIGGER TRISDbits.TRISD6

void i2cInit(short address);
void __interrupt() i2cSlaveRead(void);

short z;

#endif	/* XC_HEADER_TEMPLATE_H */