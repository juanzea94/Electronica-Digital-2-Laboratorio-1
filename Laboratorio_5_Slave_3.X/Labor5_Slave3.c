
#include "Labor5_Slave3.h"

void i2cInit(short address) {
    SSPSTAT = 0x80;    
    SSPADD = address; //Setting address
    SSPCON = 0x36;    //As a slave device
    SSPCON2 = 0x01;
    SCL = 1;       //Setting as input as given in datasheet
    SDA = 1;       //Setting as input as given in datasheet
    GIE = 1;          //Global interrupt enable
    PEIE = 1;         //Peripheral interrupt enable
    SSPIF = 0;        //Clear interrupt flag
    SSPIE = 1;        //Synchronous serial port interrupt enable
}

void __interrupt() i2cSlaveRead(void){
    if(SSPIF == 1){
        CKP = 0;
        if ((SSPOV) || (WCOL)){ //If overflow or collision
            z = SSPBUF; // Read the previous value to clear the buffer
            SSPOV = 0; // Clear the overflow flag
            WCOL = 0; // Clear the collision bit
            CKP = 1;
        }
        if(!DnA && !RnW){ //If last byte was Address + Write
            z = SSPBUF;
            while(!BF);
            PORTD = SSPBUF;
            CKP = 1;
            __delay_us(250);
        }
        else if(!DnA && RnW){ //If last byte was Address + Read
            z = SSPBUF;
            BF = 0;
            SSPBUF = PORTB ;
            CKP = 1;
            __delay_us(250);
            while(BF);
        }
        SSPIF = 0;
    }
}



