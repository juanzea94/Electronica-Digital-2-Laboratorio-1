
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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <math.h>
#include <stdint.h>
#include <pic16f887.h>
#define _XTAL_FREQ 4000000

void pot ();
uint16_t contador =0;
int antirebote =0;
uint16_t variable = 0;
uint16_t array[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};

void main(void) {
    OSCCONbits.IRCF =0b110;
 //   OSCCON = 0b110;
    TRISA = 0b00000000;
 //   TRISB = 0b00000001;
    ANSEL = 0b00000000;
    ANSELH = 0b00100000;
 //   ANSELH = 0b00000000;
    PORTA = 0b00000000;
 //   PORTB =0b00000000;
    PORTB = 0b00100011;
    TRISB = 0b00100011;
    ADCON0bits.ADCS0 =1;
    ADCON0bits.ADCS1 =0;
    ADCON0bits.CHS0 =1;
    ADCON0bits.CHS1 =0;
    ADCON0bits.CHS2 =1;
    ADCON0bits.CHS3 =1;
    ADCON1bits.ADFM =0;
    ADCON1bits.VCFG0 =0;
    ADCON1bits.VCFG1 =0;
    pot();
    return;


   while (1){
        if (PORTBbits.RB1 == 0 && PORTBbits.RB0 == 0){
            antirebote = 1;
            __delay_ms (1);
        }
        if(PORTBbits.RB0 == 1 && antirebote ==1 && contador<=8 && contador >=0){
            antirebote=0;
            contador++;
            if(contador == 9){
                contador = 8;
            }
            variable = array[contador];
            PORTA = variable; 
        }
        if(PORTBbits.RB1 == 1 && antirebote ==1 && contador>= 0 && contador<=8){
            antirebote= 0;
            contador--;
            if(contador ==-1){
                contador = 0;
            }
            variable = array[contador];
            PORTA = variable;   
        }
    }
}

void pot(void){
    while(0.05){
        __delay_ms(1);
        ADCON0bits.ADON =1;
        if (ADCON0bits.GO_DONE ==0){
            ADCON0bits.GO_DONE = 1;
        }
        PORTA = ADRESH;
 //       return;
    }
}