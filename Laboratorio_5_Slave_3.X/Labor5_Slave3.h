
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
void I2C_Slave_Init(uint8_t address);
void setup(void);
uint8_t z;
uint8_t dato;
uint8_t desecho;
uint16_t distancia;

#endif	/* XC_HEADER_TEMPLATE_H */