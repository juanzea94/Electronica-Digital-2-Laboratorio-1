
#include <xc.h>
#include "Labor4Slave.h"
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000

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

void ADC (void){
    ADCON1bits.ADFM =0;
    ADCON1bits.VCFG0 =0;
    ADCON1bits.VCFG1 =0;
    ADCON0bits.ADCS0 =1;
    ADCON0bits.ADCS1 =0;
    ADCON0bits.CHS = 0;
    ADCON0bits.ADON = 1;
    ANSEL = 0b01000011;  //defino los puertos analogicos
    ANSELH = 0b00000000;
}

void POT (uint8_t m){
    __delay_ms(10);
    ADCON0bits.CHS = m;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE);
    valana=ADRESH;
}

void IntToString (float number){
    if (number <= 9.999 & number >=1.000){
        num1 = number;
        num2 = 10*(number - num1);
        num3 = 100*(number - num1 - (num2*10));
        printf (65);
    }    
}

static void spiReceiveWait()
{
    while ( !SSPSTATbits.BF ); // Wait for Data Receive complete
}

void spiWrite(char dat)  //Write data to SPI bus
{
    SSPBUF = dat;
}

unsigned spiDataReady() //Check whether the data is ready to read
{
    if(SSPSTATbits.BF)
        return 1;
    else
        return 0;
}

char spiRead() //REad the received data
{
    spiReceiveWait();        // wait until the all bits receive
    return(SSPBUF); // read the received data from the buffer
}
