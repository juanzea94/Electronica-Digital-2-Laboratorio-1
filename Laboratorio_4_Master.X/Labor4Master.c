
#include <xc.h>
#include "Labor4Master.h"
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000


//**************************************************************************//
//**********************************UART************************************//
//**************************************************************************//

void UARTR (void){
        while(1){
            if(RCIF == 1){
            PORTB = UART_Read();
            __delay_ms(100);
        }
//    do{
//        if(!(UART_Data_Ready()))
//        PORTB = UART_Read();
//        __delay_ms(10);
//    }while(1);
}
}

void UARTW (void){
    do{
        UART_Write(7);
        __delay_ms(10000);
    }while(1);
}

char UART_Init(const long int baudrate){

	  SPBRG = 25;
      //SPBRGH = 0;
	  SYNC = 0;
	  SPEN = 1;
      TX = 1;
      RX = 0;
      CREN = 1;
      TXEN = 1;
      BRGH = 1;
      //TX9 = 0;
      RX9 = 0;
      BRG16 = 0;
      __delay_ms(80);
////	  return 1;
////	}
////	return 0;
}

char UART_TX_Empty(){
    return TRMT;
}

char UART_Data_Ready(){
    return RCIF;
}
char UART_Read(){
    while(!RCIF);
    return RCREG;
}

void UART_Read_Text(char *Output, unsigned int length){
    unsigned int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}

void UART_Write(char data){
    while(!TRMT);
    if (PIR1bits.TXIF == 1){
    TXREG = data;
    }
}

void UART_Write_Text(char *text){
    int i;
    for(i=0;text[i]!='\0';i++)
        UART_Write(text[i]);
}

//**************************************************************************//
//************************************SPI***********************************//
//**************************************************************************//

void spiMasterInit(void){
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 0;
    //SSPCONbits.WCOL = 1;
    SSPCONbits.CKP = 1;
    SSPCONbits.SSPM = 0b0000;
    SSPCONbits.SSPEN = 1;
    SDO = 0;
    SCK = 0;
//    SS = 1;
    
    
}

void spiFunctionReadSlave (void){
                

        while( (!SSPSTATbits.BF));
            __delay_ms(1);
            masterIn = spiRead();
            //SSPCONbits.SSPOV = 0;
            __delay_ms(1);
            SSPSTATbits.BF =0;
//            PORTAbits.RA4 = 0;       //Slave Deselect 
            __delay_ms(1);
         
        
//        return;
    
}

void spiFunctionWriteSlave (void){
//        PORTAbits.RA4 = 1;       //Slave Select
        __delay_ms(1);
        spiWrite(0);
//        SSPCONbits.SSPOV = 0;
        
//        __delay_ms(1);
//        PORTAbits.RA4 = 0;       //Slave Deselect 
        __delay_ms(100);
}

void spiWrite(char dat){
    SSPBUF = dat;  //Write data to SPI bus
}

unsigned spiDataReady(){
    if(SSPSTATbits.BF) //Check whether the data is ready to read
        return 1;
    else
        return 0;
}

char spiRead(){
    while (!SSPSTATbits.BF);        // wait until the all bits receive
    return(SSPBUF); // read the received data from the buffer
}