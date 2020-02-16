
#include <xc.h>
#include "Labor4Master.h"
#include <stdio.h>
#include <stdint.h>
#include <pic16f887.h>
#include <stdlib.h>
#include <string.h>
#define _XTAL_FREQ  4000000

void SPI_MASTER_INIT(void){
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 0;
    SSPCONbits.WCOL = 1
    SSPCONbits.CKP = 1;
    SSPCONbits.SSPM0 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM2 = 0;
    SSPCONbits.SSPM3 = 0;
    
    SDO = 0;
    SCK = 0;
    SS = 1;
    
    SSPCONbits.SSPEN = 1;
}

