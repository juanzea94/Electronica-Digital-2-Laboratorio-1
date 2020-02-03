
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
//#include <math.h>
#include <stdint.h>
//#include <pic16f887.h>
#define _XTAL_FREQ 4000000
//#include "Labor2.h"


//VALORES INICIALES Y DECLARACIÓN DE FUNCIONES
void pot (void);
void split (void);
void conec (void);
void segme (void);
void change (void);
char contador =0;
uint8_t valana = 0;
uint8_t antirebote =0;
uint8_t variable = 0;
unsigned char array[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};
uint16_t array2[16] = {0xE7,0x81,0x6B,0xCB,0x8D,0xCE,0x7D,0x83,0xEF,0xCF,0xAF,0xEC,0x68,0xE9,0x6E,0x2E};
uint8_t sino =0;
uint8_t numero1 =0;
uint8_t numero2=0;

void __interrupt() ISR(void) {
//    if (TMR0IF) {
    change();
        //Enter your code here
    TMR0IF = 0;
    TMR0 = 3;
    return;
    }
//}

//DECLARAR TODAS LAS VARIABLES, INICIALIZADORES
void main(void) {
    OSCCONbits.IRCF =0b110;
    OSCCONbits.OSTS= 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;
    INTCONbits.GIE = 1;
    //INTCONbits.PEIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 1;
    //INTCONbits.TMR0IE = 1;
    //INTCONbits.TMR0IF = 0;
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.T0SE = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS = 0b000;
    TMR0 = 3;
    OPTION_REGbits.nRBPU =1;
    OPTION_REGbits.INTEDG = 0;
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
//PARTE 1 CONTADOR DE 8 BITS SIN INTERRUPTOR     
   while (1){
        //Antirebote
        if (PORTBbits.RB1 == 0 && PORTBbits.RB0 == 0){
            antirebote = 1;
            __delay_ms (1);
        }
        if(PORTBbits.RB0 == 1 && antirebote ==1 && contador<=8){
            antirebote=0;
            contador++;
            if(contador == 9){
                contador = 8;
            }
 //           variable = array[contador];
//            PORTA = variable;
 //           pot();
 //           conec ();
//            return;
        }
        if(PORTBbits.RB1 == 1 && antirebote ==1 && contador<=8){
            antirebote= 0;
            contador--;
            if(contador <=0){
                contador = 0;
            }
//            variable = array[contador];
//            PORTA = variable; 
//            pot();
 //           conec ();
 //           return;
        }
        variable = array[contador];
        PORTA = variable;
        numero1 =0;
        numero2 =0;
        sino=0;
        conec();
        pot();
//        return;
    }
//    return;
}
/*
void split (void){
    numero1 = ( (valana & 0x0F)<<4 );
    numero2 = ((valana & 0xF0)>>4 );
    return;
}*/
void pot(){
    while(1){
        __delay_ms(1);
        ADCON0bits.ADON =1;
        if (ADCON0bits.GO_DONE ==0){
            ADCON0bits.GO_DONE = 1;
        }
        valana = ADRESH;
        numero1 = ((valana & 0x0F));
        numero2 = ((valana & 0xF0)>>4 );
        PORTC = 0;
        PORTDbits.RD0 = 0;
        PORTDbits.RD1 = 0;
        segme();
        return;
    }
}
    
void conec (void){
    while(1){
        if((valana) >= (variable)){
            PORTDbits.RD7 = 1;          
        }
       if ((valana) <= (variable)){
            PORTDbits.RD7 = 0;    
        }
        return;
    }
}

void segme (void){
    if (sino == 1){
        PORTDbits.RD0 = 1;
        PORTDbits.RD1 = 0;
        PORTC = array2[numero1];
        return;
    }
    if (sino == 0){
        PORTDbits.RD0 = 0;
        PORTDbits.RD1 = 1;
        PORTC = array2[numero2];
        return;
    }
//   return;
}

void change (void){
    if (sino==1){
        sino = 0;
    }
    else{
        sino =1;
    }
}