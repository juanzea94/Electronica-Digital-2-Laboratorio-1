
#include <xc.h>
#include "Labor4Slave.h"
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000

//****************************************************************************//
//**********************************ADC/POTS**********************************//
//****************************************************************************//

void adcInit (void){
    ANSEL = 0b01000111;  //defino los puertos analogicos
    ANSELH = 0b00000000;
    ADCON1bits.ADFM =0;
    ADCON1bits.VCFG0 =0;
    ADCON1bits.VCFG1 =0;
    ADCON0bits.ADCS0 =1;
    ADCON0bits.ADCS1 =0;
    ADCON0bits.CHS = 0;
    ADCON0bits.ADON = 1;
}

void POT (uint8_t m){        
    slaveOut =0;
    __delay_ms(10);
    ADCON0bits.CHS = m;
    ADCON0bits.ADON =1;
    __delay_ms(1);
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE);
        slaveOut = ADRESH;
//        PORTB=ADRESH;
        //valana = PORTB;
        //slaveOut=valana*5.0/255.0;
        //slaveOut = valana;
        __delay_ms(5);

    return;
}

//void IntToString (float number){
//    if (number <= 9.999 & number >=1.000){
//        num1 = number;
//        num2 = 10*(number - num1);
//        num3 = 100*(number - num1 - (num2*10));
//        printf (65);
//    }    
//}

//***************************************************************************//
//***********************************SPI*************************************//
//***************************************************************************//

void spiSlaveInit(){
    SSPSTATbits.SMP = 0;
    SSPCONbits.CKP = 1;
    SSPSTATbits.CKE = 0;
    SSPCONbits.SSPM = 0b0101;
    SSPCONbits.SSPEN = 1;
    
    SDO = 0;
    SCK = 1;
}

void spiFunctionReadMaster (void){
    while(1){
        if(SSPSTATbits.BF ==1){
 //       if (spiDataReady()){
            __delay_ms(10);
            slaveIn = SSPBUF;
            SSPSTATbits.BF=0;
            //slaveIn = spiRead();
            //SSPCONbits.SSPOV = 0;
            __delay_ms(20);
            break;
        }
//    return;
    }
}

void spiFunctionWriteMaster(uint8_t bande){
    __delay_ms(5);
    spiWrite(bande);
    //SSPCONbits.SSPOV = 0;
    __delay_ms(5);
}

void spiWrite(char dat)  {
//    PORTAbits.RA5 = 1;       //Slave Select
    SSPBUF = dat;//Write data to SPI bus
//    PORTAbits.RA5 = 0;       //Slave DeSelect
}

unsigned spiDataReady() {
    if(SSPSTATbits.BF)//Check whether the data is ready to read
        return 1;
    else
        return 0;
}

char spiRead(){
    while (!SSPSTATbits.BF);        // wait until the all bits receive
    return(SSPBUF); // read the received data from the buffer
}
