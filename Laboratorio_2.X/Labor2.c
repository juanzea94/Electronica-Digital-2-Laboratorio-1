#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 4000000
#include "Labor2.h"

//Función que permite el multiplexado de los 7 segmentos
void segme (void){
    if (sino == 1){
        PORTDbits.RD0 = 1;
        PORTDbits.RD1 = 0;
        PORTC = array2[numero1];
        return;
    }
    if (sino == 0){
        PORTDbits.RD0 = 0;
        PORTDbits.RD1 = 1;
        PORTC = array2[numero2];
        return;
    }
}

//Contador de los leds y manda a llamar funciones del ADC para el Pot.
void loop(void){    
   while (1){
        //Antirebote
        if (PORTBbits.RB1 == 0 && PORTBbits.RB0 == 0){
            antirebote = 1;
            __delay_ms (1);
        }
        if(PORTBbits.RB0 == 1 && antirebote ==1 && contador<=254){
            antirebote=0;
               contador++; 
//            if(contador == 9){
//                contador = 8;
//            }
        }
        if(PORTBbits.RB1 == 1 && antirebote ==1 && contador>=0){
            antirebote= 0;
            contador--;
//            if(contador <=0){
//                contador = 0;
//            }
        }
        __delay_ms(1);
        if (ADCON0bits.GO_DONE ==0){
            ADCON0bits.GO_DONE = 1;
        }
        valana = ADRESH;
//        variable = array[contador];
        PORTA = contador;
//        PORTA = variable;
        numero1 =valana;
        numero2 =valana;
        conec();
        split();
        segme();
    }
}
//Funcion encargada de comparar la salida del contador con la salida del ADC y encender la bandera de alerta si se pasan los valores.    
void conec (void){
    while(1){
        if((valana) >= (contador)){
            PORTDbits.RD7 = 1;          
        }
       if ((valana) <= (contador)){
            PORTDbits.RD7 = 0;    
        }
        return;
    }
}

//Funcion que permite la separación de bits de un valore de 8 bits.
void split(void){
    numero1 = ((valana & 0x0F));
    numero2 = ((valana & 0xF0)>>4 );
    return;
}

//Funcion que reinicia el overfloat
void change (void){
    if (sino==0){
        sino = 1;
        return;
    }
    else{
        sino =0;
        return;
    }
}
