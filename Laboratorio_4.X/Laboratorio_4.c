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
#include <stdio.h>
#include <pic16f887.h>


#define SS TRISAbits.TRISA5
#define SCK TRISCbits.TRISC3
#define SDO TRISCbits.TRISC5
#define SDI TRISCbits.TRISC4

#define 

void SPI_MASTER_INIT(void){
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 0;
    SSPCONbits.WCOL = 1
    SSPCONbits.CKP = 1;
    SSPCONbits.SSPM0 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM2 = 0;
    SSPCONbits.SSPM3 = 0;
    
    SDO = 0;
    SCK = 0;
    SS = 1;
    
    SSPCONbits.SSPEN = 1;
}

void SPI_SLAVE_INIT(){
    SSPSTATbits.SMP = 0;
    SSPCONbits.CKP = 0;
    SSPCONbits.SSPM0 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM2 = 1;
    SSPCONbits.SSPM3 = 0;
    SSPSTATbits.CKE = 0;
    
    SDO = 0;
    SCK = 1;
    
    SSPCONbits.SSPEN = 1;
}



void main(void) {
    
    SPI_MASTER_INIT();
    
    
    return;
}
