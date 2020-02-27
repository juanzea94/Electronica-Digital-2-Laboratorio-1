
#include "Labor5_Master.h"

//Funci�n encargada de inicializar con los comandos la LCD
void lcd_ini(void){
    __delay_ms(30);
    lcd_com(LCD_FUNCION_8BITS);
    lcd_com(LCD_APAGAR_CURSOR_ENCENDER_DISPLAY);
    lcd_com(LCD_BORRAR);
    lcd_com(LCD_MODO_INGRESO);
    lcd_com(LCD_PRIMERA_FILA);
}
//Aplica el enable y su respectivo delay para ser llamado entre comandos.
void enable (void){
    EN = 0;
    __delay_ms(15);
    EN = 1;
}
//Funci�n encargada de procesar los datos del comando mandado en la funci�n
//lcd_ini().
void lcd_com(uint8_t dato){
    LCD = 0xFF;
    LCD = 0x14;  
    LCD &= 0x80;
    RS = 0;
    RW = 1;
    enable();
    if (LCD == 0x80){
        enable();
    } 
    LCD = dato;
    RS = 0;
    RW = 0;
    enable();
    __delay_ms(5);
    return;
}

void lcd_ready(void) {
    LCD = 0xFF;
    LCD &= 0x80;
    RS = 0;
    RW = 1;
    EN = 0;
    __delay_ms(30);
    EN = 1;
    if (LCD == 0x80){
    EN = 0;
    __delay_ms(30);
    EN = 1;  
    }
    else{   
    }    
}

void lcd_dwr(unsigned char x){
    lcd_ready();
    LCD = x;
    RS = 1;
    RW = 0;
    enable(); 
}

void lcd_msg(unsigned char *c){
    while(*c != 0)
        lcd_dwr(*c++);
}

void float2int (float valor){
    
    valanapot1 = valor;
    valanapot2 = (valor-valanapot1)*10;
    valanapot3 = (((valor-valanapot1) *10)-valanapot2) *10;
    return;
}


void setup(void){
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;
    
    TRISA = 0b00000000;
    TRISB = 0b00000000;    
    TRISC = 0b00011000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;
    
    PORTA = 0b00000000;   
    PORTB = 0b00000000;    
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;
    //I2C_Master_Init(100000);        // Inicializar Comuncaci�n I2C
}

void I2C_Master_Init(const unsigned long c)
{
    SSPCON = 0b00101000;
    SSPCON2 = 0;
    SSPADD = (_XTAL_FREQ/(4*c))-1;
    SSPSTAT = 0;
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
    return;
}
//*****************************************************************************
// Funci�n de espera: mientras se est� iniciada una comunicaci�n,
// est� habilitado una recepci�n, est� habilitado una parada
// est� habilitado un reinicio de la comunicaci�n, est� iniciada
// una comunicaci�n o se este transmitiendo, el IC2 PIC se esperar�
// antes de realizar alg�n trabajo
//*****************************************************************************
void I2C_Master_Wait()
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}
//*****************************************************************************
// Funci�n de inicio de la comunicaci�n I2C PIC
//*****************************************************************************
void I2C_Master_Start()
{
    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
    SSPCON2bits.SEN = 1;    //inicia la comunicaci�n i2c
}
//*****************************************************************************
// Funci�n de reinicio de la comunicaci�n I2C PIC
//*****************************************************************************
void I2C_Master_RepeatedStart()
{
    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
    SSPCON2bits.RSEN = 1;   //reinicia la comunicaci�n i2c
}
//*****************************************************************************
// Funci�n de parada de la comunicaci�n I2C PIC
//*****************************************************************************
void I2C_Master_Stop()
{
    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
    SSPCON2bits.PEN = 1;    //detener la comunicaci�n i2c
}
//*****************************************************************************
//Funci�n de transmisi�n de datos del maestro al esclavo
//esta funci�n devolver� un 0 si el esclavo a recibido
//el dato
//*****************************************************************************
void I2C_Master_Write(unsigned d)
{
    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
    SSPBUF = d;             
}
//*****************************************************************************
//Funci�n de recepci�n de datos enviados por el esclavo al maestro
//esta funci�n es para leer los datos que est�n en el esclavo
//*****************************************************************************
unsigned short I2C_Master_Read(unsigned short a)
{
    unsigned short temp;
    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
    SSPCON2bits.RCEN = 1;
    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
    temp = SSPBUF;
    I2C_Master_Wait();
    ACKDT = (a)?0:1;
    ACKEN = 1;
    return temp;
//    I2C_Master_Wait();      //espera que se cumplan las condiciones adecuadas
//    if(a == 1){
//        SSPCON2bits.ACKDT = 0;
//    }else{
//        SSPCON2bits.ACKDT = 1;
//    }
//    SSPCON2bits.ACKEN = 1;          // Iniciar sequencia de Acknowledge
//    return temp;                    // Regresar valor del dato le�do
}
//*****************************************************************************
// Funci�n para inicializar I2C Esclavo
//*****************************************************************************
//void I2C_Slave_Init(uint8_t address)
//{ 
//    SSPADD = address;
//    SSPCON = 0x36;      // 0b00110110
//    SSPSTAT = 0x80;     // 0b10000000
//    SSPCON2 = 0x01;     // 0b00000001
//    SCL = 1;
//    SDA = 1;
//    GIE = 1;
//    PEIE = 1;
//    SSPIF = 0;
//    SSPIE = 1;
//}
//*****************************************************************************
