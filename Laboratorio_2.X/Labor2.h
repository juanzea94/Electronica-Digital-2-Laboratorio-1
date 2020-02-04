/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LABOR2_H
#define	LABOR2_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#define _XTAL_FREQ 4000000

//Se declaran las funciones del sistema para ser llamadas en el Labor2.c
void segme (void);
void pot (void);
void split (void);
void conec (void);
void change (void);
void loop (void);

//Se declaran las variables del programa utilizadas en las funciones
uint8_t contador;
uint8_t valana;
uint8_t antirebote;
uint8_t variable = 0;
uint8_t sino;
uint8_t numero1;
uint8_t numero2;
//uint8_t array[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};
uint8_t array2[] = {0x77,0x41,0x3B,0x6B,0x4D,0x6E,0x7E,0x47,0x7F,0x6F,0x5F,0x7C,0x38,0x79,0x3E,0x1E};

#endif

