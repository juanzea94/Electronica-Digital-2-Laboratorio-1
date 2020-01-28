/*
 * File:   Laboratorio_1.c
 * Author: juanz
 *
 * Created on January 22, 2020, 2:41 PM
 */


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
#define _XTAL_FREQ 4000000

//Se definen las funciones y variables a utilizar
int Boton = 0;
void funcion ();
int B1 = 0;
int B2 = 0;
int m=0;
int n=0;
int p=0;
int q=0;
int r=0;

//Inicia el Programa principal, donde se efectua el funcionamiento del semáforo y la cuenta regresiva de la carrera
void main(void){
    //Se declaran los botones y valores iniciales de los pines
    OSCCON = 0b110;
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 1;
    ANSEL = 0b00000000;
    ANSELH = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
//Inicia el loop principal del semaforo y cuenta regresiva.
while (1){
  //Anti rebote para evitar que no funcione bien o se trabe en algun lugar al iniciar el juego
  if (PORTEbits.RE3 == 1){
        Boton = 1;
    }
  //Inicia el semaforo y la cuenta regresiva del inicio de la carrera
  if (PORTEbits.RE3 == 1 && Boton == 1){
      Boton = 0;
      PORTDbits.RD4 = 1;
      PORTCbits.RC3 = 1;
      PORTCbits.RC2 = 1;
      PORTCbits.RC6 = 1;
      PORTCbits.RC0 = 1;
      PORTCbits.RC1 = 1;
      __delay_ms(5);
      PORTDbits.RD4 = 0;
      PORTCbits.RC3 = 0;
      PORTCbits.RC2 = 0;
      PORTCbits.RC6 = 0;
      PORTCbits.RC0 = 0;
      PORTCbits.RC1 = 0;
      __delay_ms(5);
      PORTDbits.RD3 = 1;
      PORTCbits.RC3 = 1;
      PORTCbits.RC4 = 1;
      PORTCbits.RC6 = 1;
      PORTCbits.RC0 = 1;
      PORTCbits.RC1 = 1;
      __delay_ms(5);
      PORTDbits.RD3 = 0;
      PORTCbits.RC3 = 0;
      PORTCbits.RC4 = 0;
      PORTCbits.RC6 = 0;
      PORTCbits.RC0 = 0;
      PORTCbits.RC1 = 0;
      __delay_ms(5);
      PORTDbits.RD2 = 1;
      PORTCbits.RC2 = 1;
      PORTCbits.RC1 = 1;
      __delay_ms(5);
      PORTDbits.RD2 = 1;
      PORTDbits.RD3 = 1;
      PORTDbits.RD4 = 1;
      PORTCbits.RC2 = 1;
      PORTCbits.RC1 = 1;
      PORTCbits.RC3 = 1;
      PORTCbits.RC4 = 1;
      PORTCbits.RC5 = 1;
      PORTCbits.RC0 = 1;
      // Se manda a llamar de afuera la funcion llamada funcion() 
      funcion();
  }  
}
}
//Salimos del loop y de la funcion principal "main" y se realiza la funcion del conteo de los 8 bits.
void funcion (){
while (1){
    //Verifica si el jugador numero 2 ya gano y bloquea al jugador 1 para que solo exista un ganador  
    if (PORTBbits.RB7 == 1 && m==0 && PORTAbits.RA0 == 0){
        m=1;
        PORTDbits.RD3 = 0;
        PORTDbits.RD4 = 0;
        PORTCbits.RC3 = 1;
        PORTCbits.RC4 = 1;
        PORTCbits.RC5 = 0;
        PORTCbits.RC0 = 1;
        PORTCbits.RC6 = 1;
        PORTDbits.RD2 = 0;
        PORTCbits.RC2 = 0;
        PORTCbits.RC1 = 1;
        PORTAbits.RA6 = 0;
        PORTAbits.RA7 = 0;
        PORTAbits.RA5 = 0;
        PORTAbits.RA4 = 0;
        PORTAbits.RA3 = 0;
        PORTAbits.RA2 = 0;
        PORTAbits.RA1 = 0;
        PORTAbits.RA0 = 0;
        PORTDbits.RD0 = 0;
        PORTDbits.RD7 = 1;
        __delay_ms (1);
        PORTDbits.RD7 = 0;
        PORTCbits.RC3 = 0;
        PORTCbits.RC1 = 0;
        PORTCbits.RC4 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC0 = 0;
        __delay_ms (1);
        PORTDbits.RD7 = 1;
        PORTCbits.RC3 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC4 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC0 = 1;
        __delay_ms (1);
        PORTDbits.RD7 = 0;
        PORTCbits.RC3 = 0;
        PORTCbits.RC1 = 0;
        PORTCbits.RC4 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC0 = 0;
        __delay_ms (1);
        PORTDbits.RD7 = 1;
        PORTCbits.RC3 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC4 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC0 = 1;
        __delay_ms (1);
        PORTDbits.RD7 = 0;
        PORTCbits.RC3 = 0;
        PORTCbits.RC1 = 0;
        PORTCbits.RC4 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC0 = 0;
        __delay_ms (1);
        PORTDbits.RD7 = 1;
        PORTCbits.RC3 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC4 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC0 = 1;
        __delay_ms (1);
        PORTDbits.RD7 = 0;
        PORTCbits.RC3 = 0;
        PORTCbits.RC1 = 0;
        PORTCbits.RC4 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC0 = 0;
        __delay_ms (1);
        PORTDbits.RD7 = 1;
        PORTCbits.RC3 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC4 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC0 = 1;
        __delay_ms (1);
        PORTDbits.RD7 = 0;
        PORTCbits.RC3 = 0;
        PORTCbits.RC1 = 0;
        PORTCbits.RC4 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC0 = 0;
        __delay_ms (1);
        PORTDbits.RD7 = 1;
        PORTCbits.RC3 = 1;
        PORTCbits.RC1 = 1;
        PORTCbits.RC4 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC0 = 1;
    }
        //Reinicio de los valores iniciales para reiniciar el juego cuando el jugador oprima el boton de inicio
        if (PORTEbits.RE3== 1 && PORTDbits.RD7 == 1){
            PORTA = 0;
            PORTB = 0;
            PORTC = 0;
            PORTD = 0;
            PORTE = 0;
            Boton = 0;
            m = 0;
            n = 0;
            q = 0;
            p = 0;
            B1 = 0;
            B2 = 0;
            return;
        }
        //Inicia la secuencia de 8 bits del segundo jugador cuando oprime el boton
        if (PORTEbits.RE2 == 0){
            p=1;
        }
        //COntador y verificador que el segundo jugador esta oprimiendo el boton
      if (PORTEbits.RE2 == 1&& PORTDbits.RD2 == 1 && p==1){
            B2=B2+1;
            __delay_ms(1);
      //Inicia la secuencia de ifs para encender LED por LED      
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB0 == 0 && B2==1){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 0;
          PORTBbits.RB2 = 0;
          PORTBbits.RB3 = 0;
          PORTBbits.RB4 = 0;
          PORTBbits.RB5 = 0;
          PORTBbits.RB6 = 0;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB0 == 1 && B2 == 2){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 0;
          PORTBbits.RB3 = 0;
          PORTBbits.RB4 = 0;
          PORTBbits.RB5 = 0;
          PORTBbits.RB6 = 0;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB1 == 1 && B2 == 3){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 1;
          PORTBbits.RB3 = 0;
          PORTBbits.RB4 = 0;
          PORTBbits.RB5 = 0;
          PORTBbits.RB6 = 0;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB2 == 1 && B2 == 4){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 1;
          PORTBbits.RB3 = 1;
          PORTBbits.RB4 = 0;
          PORTBbits.RB5 = 0;
          PORTBbits.RB6 = 0;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB3 == 1 && B2 == 5){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 1;
          PORTBbits.RB3 = 1;
          PORTBbits.RB4 = 1;
          PORTBbits.RB5 = 0;
          PORTBbits.RB6 = 0;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB4 == 1 && B2 == 6){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 1;
          PORTBbits.RB3 = 1;
          PORTBbits.RB4 = 1;
          PORTBbits.RB5 = 1;
          PORTBbits.RB6 = 0;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB5 == 1 && B2 == 7){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 1;
          PORTBbits.RB3 = 1;
          PORTBbits.RB4 = 1;
          PORTBbits.RB5 = 1;
          PORTBbits.RB6 = 1;
          PORTBbits.RB7 = 0;
          p=0;
      }
      if (PORTDbits.RD2 == 1 && PORTBbits.RB7 == 0 && PORTBbits.RB1 == 1 && B2 == 8){
          PORTBbits.RB0 = 1;
          PORTBbits.RB1 = 1;
          PORTBbits.RB2 = 1;
          PORTBbits.RB3 = 1;
          PORTBbits.RB4 = 1;
          PORTBbits.RB5 = 1;
          PORTBbits.RB6 = 1;
          PORTBbits.RB7 = 1;
          PORTDbits.RD7 = 1;
          p=0;
          
      }
    }
    //Comprueba y bloquea al segundo jugador si el primer jugador optiene la victoria primero.
    if (PORTAbits.RA0 == 1 && n==0 && PORTBbits.RB7 == 0){
        n=1;
        PORTDbits.RD3 = 0;
        PORTDbits.RD4 = 0;
        PORTCbits.RC3 = 0;
        PORTCbits.RC4 = 0;
        PORTCbits.RC5 = 0;
        PORTCbits.RC0 = 0;
        PORTCbits.RC6 = 0;
        PORTDbits.RD2 = 0;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 1;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 0;
        PORTBbits.RB5 = 0;
        PORTBbits.RB4 = 0;
        PORTBbits.RB3 = 0;
        PORTBbits.RB2 = 0;
        PORTBbits.RB1 = 0;
        PORTBbits.RB0 = 0;
        PORTDbits.RD0 = 0;
        PORTDbits.RD0 = 1;
        __delay_ms (1);
        PORTDbits.RD0 = 0;
        PORTCbits.RC2 = 0;
        PORTCbits.RC1 = 0;
        __delay_ms (1);
        PORTDbits.RD0 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 1;
        __delay_ms (1);
        PORTDbits.RD0 = 0;
        PORTCbits.RC2 = 0;
        PORTCbits.RC1 = 0;
        __delay_ms (1);
        PORTDbits.RD0 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 1;
        __delay_ms (1);
        PORTDbits.RD0 = 0;
        PORTCbits.RC2 = 0;
        PORTCbits.RC1 = 0;
        __delay_ms (1);
        PORTDbits.RD0 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 1;
        __delay_ms (1);
        PORTDbits.RD0 = 0;
        PORTCbits.RC2 = 0;
        PORTCbits.RC1 = 0;
        __delay_ms (1);
        PORTDbits.RD0 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 1;
        __delay_ms (1);
        PORTDbits.RD0 = 0;
        PORTCbits.RC2 = 0;
        PORTCbits.RC1 = 0;
        __delay_ms (1);
        PORTDbits.RD0 = 1;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 1;
    }
        //Realiza el reiniciado de los valores si el primer jugador gana y reinicia el sistema si se oprime el boton de inicio
        if (PORTEbits.RE3== 1 && PORTDbits.RD0 == 1){
            PORTA = 0;
            PORTB = 0;
            PORTC = 0;
            PORTD = 0;
            PORTE = 0;
            Boton = 0;
            m = 0;
            n = 0;
            q = 0;
            p = 0;
            B1 = 0;
            B2 = 0;
            return;
        }
        //Inicia los verificadores y contadores del primer jugador que realizan el encendido de cada led 8 bits
        if (PORTEbits.RE1 == 0){
            q=1;
    }
        //Inicia contador y utiliza el if anterior como antirebote para operar la secuencia de los LEDS del primer jugador
        if (PORTEbits.RE1 == 1&& PORTDbits.RD2 == 1 && q==1){
            B1=B1+1;
            __delay_ms(1);
      //Inicia la secuencia de 8 bits del primer jugador.      
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA6 == 0 && B1==1){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 0;
          PORTAbits.RA5 = 0;
          PORTAbits.RA4 = 0;
          PORTAbits.RA3 = 0;
          PORTAbits.RA2 = 0;
          PORTAbits.RA1 = 0;
          PORTAbits.RA0 = 0;
          q=0;
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA6 == 1 && B1 == 2){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 0;
          PORTAbits.RA4 = 0;
          PORTAbits.RA3 = 0;
          PORTAbits.RA2 = 0;
          PORTAbits.RA1 = 0;
          PORTAbits.RA0 = 0;
          q=0;
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA7 == 1 && B1 == 3){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 1;
          PORTAbits.RA4 = 0;
          PORTAbits.RA3 = 0;
          PORTAbits.RA2 = 0;
          PORTAbits.RA1 = 0;
          PORTAbits.RA0 = 0;
          q=0;
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA5 == 1 && B1 ==4){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 1;
          PORTAbits.RA4 = 1;
          PORTAbits.RA3 = 0;
          PORTAbits.RA2 = 0;
          PORTAbits.RA1 = 0;
          PORTAbits.RA0 = 0;
          q=0;
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA4 == 1 && B1 == 5){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 1;
          PORTAbits.RA4 = 1;
          PORTAbits.RA3 = 1;
          PORTAbits.RA2 = 0;
          PORTAbits.RA1 = 0;
          PORTAbits.RA0 = 0;
          q=0;
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA3 == 1 && B1 == 6){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 1;
          PORTAbits.RA4 = 1;
          PORTAbits.RA3 = 1;
          PORTAbits.RA2 = 1;
          PORTAbits.RA1 = 0;
          PORTAbits.RA0 = 0;
          q=0;
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA2 == 1 && B1 == 7){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 1;
          PORTAbits.RA4 = 1;
          PORTAbits.RA3 = 1;
          PORTAbits.RA2 = 1;
          PORTAbits.RA1 = 1;
          PORTAbits.RA0 = 0;
          q=0;
          reset();
      }
      if (PORTDbits.RD2 == 1 && PORTAbits.RA0 == 0 && PORTAbits.RA1 == 1 && B1 == 8){
          PORTAbits.RA6 = 1;
          PORTAbits.RA7 = 1;
          PORTAbits.RA5 = 1;
          PORTAbits.RA4 = 1;
          PORTAbits.RA3 = 1;
          PORTAbits.RA2 = 1;
          PORTAbits.RA1 = 1;
          PORTAbits.RA0 = 1;
          PORTDbits.RD0 = 1;
          q=0;
      }
        }
  }
return;
}
