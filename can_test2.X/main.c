#include<xc.h>
#include "mcc_generated_files/mcc.h"
#include "FT800.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 1;
  
    LED_1_SetDigitalOutput();
    LED_1_SetLow(); 
    
    while (1)
    {
        /*uint16_t data = ADC_GetConversion(analog_1);
        // succeeded
        uCAN_MSG test;
        test.frame.idType=dSTANDARD_CAN_MSG_ID_2_0B;
        test.frame.id=0x120;
        test.frame.dlc=8;
        test.frame.data0= (data >> 8);
        test.frame.data1= (data & 0xFF);
        test.frame.data2=0xDC;
        test.frame.data3=0xCB;
        test.frame.data4=0xBC;
        test.frame.data5=0xCD;
        test.frame.data6=0xDE;
        test.frame.data7=0xFF;
        
        CAN_transmit(&test);
        */
    }
}
/**
 End of File
*/