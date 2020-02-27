
#include "Labor5_Slave1.h"

//*****************************************************************************
// Función para inicializar I2C Esclavo
//*****************************************************************************
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

void adcInit (void){
    ADCON1bits.ADFM =0;
    ADCON1bits.VCFG0 =0;
    ADCON1bits.VCFG1 =0;
    ADCON0bits.ADCS0 =1;
    ADCON0bits.ADCS1 =0;
    ADCON0bits.ADON = 1;
    return;
}

//Función encargada de imprimir el valor del voltaje en la LCD con un corrimiento 
//de bits y lectura del valor analógico del ADC
void print(void){
        __delay_ms(10);
        ADCON0bits.GO_DONE=1;
        while(ADCON0bits.GO_DONE);
        valana=ADRESH;
        __delay_ms(10);
        return;
}

void setup(void){
    ANSEL = 0b00000001;  //defino los puertos analogicos
    ANSELH = 0b00000000;
    
    TRISA = 0b00000001;
    TRISB = 0b00000000;  
    TRISC = 0b00011000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;
    
    PORTA = 0b00000000;    
    PORTB = 0b00000000;      
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;
    //I2C_Slave_Init(0x30);  

}

//////////////////////////////MASTER////////////////////////

//void float2int (float valor){
//    
//    valanapot1 = valor;
//    valanapot2 = (valor-valanapot1)*10;
//    valanapot3 = (((valor-valanapot1) *10)-valanapot2) *10;
//    return;
//}

//////////////////////////////MASTER//////////////////////////////