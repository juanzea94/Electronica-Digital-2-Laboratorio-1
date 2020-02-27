/*
 * File:   Laboratorio_5_Master.c
 * Author: juanz
 *
 * Created on February 24, 2020, 12:37 AM
 */

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
// Use project enums instead of #define for ON and OFF.

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#include "Labor5_Master.h"
#define _XTAL_FREQ  4000000

void main(void) {
    setup();
    lcd_ini();
    lcd_com(LCD_BORRAR);
    lcd_msg (" ADCv CONT DIST ");
    __delay_ms(20);
    
    while(1){
        //ESTO LE ESCRIBE EL MASTER PARA COMUNICARSE CON LOS SLAVES
        I2C_Master_Init(100000);
        
        I2C_Master_Start();
        I2C_Master_Write(0x30);
        I2C_Master_Write(desecho); //VARIABLE SIN IMPORTANCIA
        I2C_Master_Stop();
        __delay_ms(100);
       
        //ESTO LEE EL SLAVE MODIFICANDO LA DIRECCION DE CADA UNO
        
        I2C_Master_Start();
        I2C_Master_Write(0x31); // BANDERA PARA QUE EL SLAVE LE MANDE ALGO
        valana = I2C_Master_Read(0); //LO QUE MANDA EL SLAVE
        I2C_Master_Stop();
        __delay_ms(100);
        desecho++;
        PORTA = valana;
        
        voltaje=(valana*5.0)/255.0;
        __delay_ms(5);
        float2int(voltaje);
        __delay_ms(5);
        lcd_com(193);
        itoa(valana1,valanapot1,10);
        itoa(valana2,valanapot2,10);
        itoa(valana3,valanapot3,10);
        lcd_msg (valana1);
        lcd_com(194);
        lcd_msg (".");
        lcd_com(195);
        lcd_msg (valana2);
        lcd_com(196);
        lcd_msg (valana3);
        voltaje = 0;
        valana=0;
        
        I2C_Master_Start();
        I2C_Master_Write(0x40);
        I2C_Master_Write(desecho); //VARIABLE SIN IMPORTANCIA
        I2C_Master_Stop();
        __delay_ms(200);
       
        //ESTO LEE EL SLAVE MODIFICANDO LA DIRECCION DE CADA UNO
        contador = 0;
        I2C_Master_Start();
        I2C_Master_Write(0x41); // BANDERA PARA QUE EL SLAVE LE MANDE ALGO
        contador = I2C_Master_Read(0); //LO QUE MANDA EL SLAVE
        I2C_Master_Stop();
        __delay_ms(200);
        desecho++;
        PORTA = contador;
        
//        voltaje=(*5.0)/255.0;
//        __delay_ms(5);
//        float2int(voltaje);
//        __delay_ms(5);
        lcd_com(198);
        itoa(contador1,contador,10);
//        itoa(valana2,valanapot2,10);
//        itoa(valana3,valanapot3,10);
        lcd_msg (contador1);
//        lcd_com(194);
//        lcd_msg (".");
//        lcd_com(195);
//        lcd_msg (valana2);
//        lcd_com(196);
//        lcd_msg (valana3);
//        voltaje = 0;
        //contador=0;
        
        
        I2C_Master_Start();
        I2C_Master_Write(0x50);
        I2C_Master_Write(desecho); //VARIABLE SIN IMPORTANCIA
        I2C_Master_Stop();
        __delay_ms(200);
       
        //ESTO LEE EL SLAVE MODIFICANDO LA DIRECCION DE CADA UNO
        contador = 0;
        I2C_Master_Start();
        I2C_Master_Write(0x51); // BANDERA PARA QUE EL SLAVE LE MANDE ALGO
        distancia = I2C_Master_Read(0); //LO QUE MANDA EL SLAVE
        I2C_Master_Stop();
        __delay_ms(200);
        desecho++;
        //PORTA = contador;
        
//        voltaje=(*5.0)/255.0;
//        __delay_ms(5);
//        float2int(voltaje);
//        __delay_ms(5);
        lcd_com(203);
        itoa(distancia1,distancia,10);
//        itoa(valana2,valanapot2,10);
//        itoa(valana3,valanapot3,10);
        lcd_msg (distancia1);
        lcd_com(206);
        lcd_msg ("mm");
//        lcd_com(194);
//        lcd_msg (".");
//        lcd_com(195);
//        lcd_msg (valana2);
//        lcd_com(196);
//        lcd_msg (valana3);
//        voltaje = 0;
        //contador=0;
    
    }
    return;
}
