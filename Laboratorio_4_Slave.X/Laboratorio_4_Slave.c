/*
 * File:   Laboratorio_4_Slave.c
 * Author: juanz
 *
 * Created on February 14, 2020, 5:22 PM
 */
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include "Labor4Slave.h"
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000


void main(void) {
    
    OSCCONbits.IRCF =0b110;
    OSCCONbits.OSTS= 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;
    
    SDO = 0;
    SDI = 1;
    SCK = 1;
    
    TRISA = 0b00000111;
    TRISB = 0;
    TRISE = 0b0100;
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b0000;
    
    ANSEL = 0b11000111;  //defino los puertos analogicos
    ANSELH = 0b00000000;
    
    spiSlaveInit();
    adcInit();
    
    while(1){

        spiFunctionReadMaster();
        spiFunctionWriteMaster(1);
        POT(1);
        spiFunctionReadMaster();
        spiFunctionWriteMaster(slaveOut);
        
        spiFunctionReadMaster();
        spiFunctionWriteMaster(2);
        POT(7);
        spiFunctionReadMaster();
        spiFunctionWriteMaster(slaveOut);
    }
    //return;
}
