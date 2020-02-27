
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LABOR5_MASTER_H
#define	__LABOR5_MASTER_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#include "Labor5_Master.h"
#define _XTAL_FREQ  4000000

#define SDA TRISCbits.TRISC4
#define SCL TRISCbits.TRISC3
//#define GIE INTCONbits.GIE
//#define PEIE INTCONbits.PEIE
//#define SSPIF PIR1bits.SSPIF
//#define SSPIE PIE1bits.SSPIE
#define  LCD PORTD
#define  RS  PORTCbits.RC5
#define  RW  PORTCbits.RC6
#define  EN  PORTCbits.RC7
#define LCD_PRIMERA_FILA 128
#define LCD_SEGUNDA_FILA 192
#define LCD_FUNCION_8BITS 56
#define LCD_BORRAR 1
#define LCD_APAGAR_CURSOR_ENCENDER_DISPLAY 12
#define LCD_MODO_INGRESO 6 

char distancia1[16];
uint16_t distancia;
char valana1[8];
char valana2[8];
char valana3[8];
char contador1[8];
float voltaje;
int valanapot1;
int valanapot2;
int valanapot3;
float valor;
uint8_t valana;
uint8_t desecho;
uint8_t contador;

//Declaración de prototipos de funciones

void setup(void);
void lcd_ini (void);
void lcd_com (uint8_t dato);
void lcd_ready(void);
void lcd_msg(unsigned char *c);
void lcd_dwr(unsigned char x);
void float2int (float valor);
void I2C_Master_Init(const unsigned long c);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_Master_Write(unsigned d);
unsigned short I2C_Master_Read(unsigned short a);


#endif	/* XC_HEADER_TEMPLATE_H */

