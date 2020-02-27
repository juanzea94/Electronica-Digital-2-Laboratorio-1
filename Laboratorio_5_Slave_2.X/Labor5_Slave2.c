
#include "Labor5_Slave2.h"

void I2C_Slave_Init(uint8_t address)
{ 
    SSPADD = address;
    SSPCON = 0x36;      // 0b00110110
    SSPSTAT = 0x80;     // 0b10000000
    SSPCON2 = 0x01;     // 0b00000001
    SCL = 1;
    SDA = 1;
    GIE = 1;
    PEIE = 1;
    SSPIF = 0;
    SSPIE = 1;
}
//*****************************************************************************

void setup(void){
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;
    
    TRISA = 0b00000000;
    TRISB = 0b00000000;  
    TRISC = 0b00011000;
    TRISD = 0b00001100;
    TRISE = 0b00000000;
    
    PORTA = 0b00000000;    
    PORTB = 0b00000000;      
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;
    //I2C_Slave_Init(0x30);  
    return;
}
void loop(void){
    contador = 0;
   while (1){
       if (contador >=255){
           contador = 0;
       }
        //Antirebote
        if (PORTDbits.RD3 == 0 && PORTDbits.RD2 == 0){
            antirebote = 1;
            __delay_ms (1);
        }
        if(PORTDbits.RD3 == 1 && antirebote ==1 && contador<=255 && contador>=0){
            antirebote=0;
            if (contador >= 255){
                contador = 0;
                return;
            }
               contador++;
               
//            if(contador == 9){
//                contador = 8;
//            }
        }
        if(PORTDbits.RD2 == 1 && antirebote ==1 && contador<=255){
            antirebote= 0;
            if (contador >= 255){
                contador = 0;
                return;
            }
            contador--;
            
//            if(contador <=0){
//                contador = 0;
//            }
        }
        PORTB = contador;
        I2C_Slave_Init(0x40);
   }
    return;
}
