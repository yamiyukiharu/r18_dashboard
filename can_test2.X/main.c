#include<xc.h>
#include "mcc_generated_files/mcc.h"
#include "Gue/FT800.h"

#define FT_ACTIVE  0x00
#define FT_STANDBY 0x41
#define FT_SLEEP   0x42
#define FT_PWRDOWN 0x50
#define FT_CLKEXT  0x44
#define FT_CLK48M  0x62
#define FT_CLK36M  0x61
#define FT_CORERST 0x68

void wait3secs(){
    __delay_ms(3000);
}

void main(void)
{
    uCAN_MSG test;
    // Initialize the device
    SYSTEM_Initialize();
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 1;
  
    RXB0CONbits.RXM0 = 1;
    RXB0CONbits.RXM1 = 0;
    RXB0CONbits.RB0DBEN = 0;
    RXB0CONbits.FILHIT0 = 0;
    
    
    LED_1_SetDigitalOutput();
    
    
    IO_RC0_SetDigitalOutput();
    IO_RC0_SetLow();
  
    CS_SetDigitalMode();
    PD_SetDigitalMode();
    CS_SetDigitalOutput();
    PD_SetDigitalOutput();
    
    TRISC5 = 0;
    TRISC3 = 0;
    TRISA5 = 1;
    
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;
    SSPCON1bits.SSPEN = 1;
    SSPCON1bits.CKP = 1;
    SSPCON1bits.SSPM = 0b0000;
    
    FT800_Init();
  
    
    LED_1_SetHigh();
    
    while (1)
{       
        int data0 = 222;
        int data1 = 222;
        if(CAN_receive(&test)) {
            if(test.frame.id == 0x640) {
                data0 = test.frame.data0;
                data1 = test.frame.data1;
                LED_1_SetLow();
                __delay_ms(20);
            }
        } else {
            LED_1_SetHigh();
        }

        test.frame.idType=dSTANDARD_CAN_MSG_ID_2_0B;
        test.frame.id=0x120;
        test.frame.dlc=8;
        test.frame.data0= data0;
        test.frame.data1= data1;
        
        CAN_transmit(&test);
        
    }
}
/**
 End of File
*/