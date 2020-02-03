
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
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

#include <xc.h>
#include <stdint.h>
#include "Labor2.h"
#define _XTAL_FREQ 4000000


void __interrupt() ISR(void) {
    if (TMR0IF) {
        change();
    TMR0IF = 0;
    TMR0 = 4;
    return;
    }
}

//DECLARAR TODAS LAS VARIABLES, INICIALIZADORES
void main(void) {
    OSCCONbits.IRCF =0b110;
    OSCCONbits.OSTS= 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;
    
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 1;
    
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.T0SE = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS = 0b000;
    TMR0 = 4;
    OPTION_REGbits.nRBPU =1;
    OPTION_REGbits.INTEDG = 0; 
    
    ADCON0bits.ADCS0 =1;
    ADCON0bits.ADCS1 =0;
    ADCON0bits.CHS0 =1;
    ADCON0bits.CHS1 =0;
    ADCON0bits.CHS2 =1;
    ADCON0bits.CHS3 =1;
    ADCON0bits.ADON = 1;
    ADCON1bits.ADFM =0;
    ADCON1bits.VCFG0 =0;
    ADCON1bits.VCFG1 =0;
    
    TRISA = 0b00000000;
    TRISB = 0b00100011;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;
    ANSEL = 0b00000000;
    ANSELH = 0b00100000;
    PORTD = 0b00000000;
    PORTA = 0;
    PORTB = 0;
    PORTD = 0;
    loop();
    return;
    
}
