
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

#define SS TRISAbits.TRISA5
#define SCK TRISCbits.TRISC3
#define SDO TRISCbits.TRISC5
#define SDI TRISCbits.TRISC4
#define CONTADOR TRISB

void SPI_MASTER_INIT(void);

#endif	/* XC_HEADER_TEMPLATE_H */

