/*
 * File:   Laboratorio_5_Slave_3.c
 * Author: juanz
 *
 * Created on February 24, 2020, 10:06 PM
 */
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#include "Labor5_Slave3.h"
#define _XTAL_FREQ  4000000 


//void __interrupt() i2cSlaveRead(void);

void main(void) {
        TRISBbits.TRISB0 =0;
        PORTBbits.RB0 = 1;
    
        int a;

        TRISB = 0b00000000;         //RB4 as Input PIN (ECHO)
        TRISA = 0b00000000; 
//        TRISD = 0b10000001;              // LCD Pins as Output
        PORTBbits.RB0 = 1;
        __delay_ms(3000);
        T1CON = 0x20;               //Initialize Timer Module
        PORTB = 0;
        PORTD = 0;
        PORTA = 1;
        PORTBbits.RB0 = 1;
        PORTBbits.RB1 = 1;
        PORTBbits.RB2 = 1;
        PORTBbits.RB3 = 1;
        PORTBbits.RB4 = 1;
        TRIGGER = 0;
        ECHO = 1;
        
        
  while(1)
  { 
    TMR1H = 0;                //Sets the Initial Value of Timer
    TMR1L = 0;                //Sets the Initial Value of Timer

    TRIGGER = 1;                  //TRIGGER HIGH
    __delay_us(10);           //10uS Delay 
    TRIGGER = 0;                  //TRIGGER LOW

    while(ECHO==0);              //Waiting for Echo
    T1CONbits.TMR1ON = 1;               //Timer Starts
    while(ECHO==1);               //Waiting for Echo goes LOW
    T1CONbits.TMR1ON = 0;               //Timer Stops

    a = (TMR1L | (TMR1H<<8)); //Reads Timer Value
    a = a/58.82;              //Converts Time to Distance
    a = a + 1;                //Distance Calibration
    PORTB = a;
    
    PORTBbits.RB0 = 1;
}
}