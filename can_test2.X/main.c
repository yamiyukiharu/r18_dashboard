#include<xc.h>
#include "mcc_generated_files/mcc.h"
#include "Gue/FT800.h"
#include "display.h"

#define FT_ACTIVE  0x00
#define FT_STANDBY 0x41
#define FT_SLEEP   0x42
#define FT_PWRDOWN 0x50
#define FT_CLKEXT  0x44
#define FT_CLK48M  0x62
#define FT_CLK36M  0x61
#define FT_CORERST 0x68

void wait2secs(){
    __delay_ms(2000);
}

void main(void)
{    
    int y_start = 0;
    uCAN_MSG test;
    // Initialize the device
    SYSTEM_Initialize();
    
    // CAN Configuration
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 1; 
    RXB0CONbits.RXM0 = 1;
    RXB0CONbits.RXM1 = 0;
    RXB0CONbits.RB0DBEN = 0;
    RXB0CONbits.FILHIT0 = 0;
    
    // SPI Configuration for LCD
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;
    SSPCON1bits.SSPEN = 1;
    SSPCON1bits.CKP = 1;
    SSPCON1bits.SSPM = 0b0000;     
    FT800_Init();
    
    EUSART1_Initialize();

    wait2secs();
    
    display_start();
    display_labels();
    display_gear(2);
    display_rpm(2000);
    display_end();
    
    while (1) {  
        up_shift_SetHigh();
        __delay_ms(50);
        EUSART1_Write(0xAA);    
        up_shift_SetLow();
        __delay_ms(50);        
    }
}
/**
 End of File
*/