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
    // Initialize the device
    SYSTEM_Initialize();
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 1;
  
    LED_1_SetDigitalOutput();
  
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
    
    wr32(RAM_DL + 0, CLEAR(1, 1, 1)); // clear screen
    wr32(RAM_DL + 4, BEGIN(BITMAPS)); // start drawing bitmaps
    wr32(RAM_DL + 8, VERTEX2II(220, 110, 31, 'F')); // ascii F in font 31
    wr32(RAM_DL + 12, VERTEX2II(244, 110, 31, 'T')); // ascii T
    wr32(RAM_DL + 16, VERTEX2II(270, 110, 31, 'D')); // ascii D
    wr32(RAM_DL + 20, VERTEX2II(299, 110, 31, 'I')); // ascii I
    wr32(RAM_DL + 24, END());
    wr32(RAM_DL + 28, COLOR_RGB(160, 22, 22)); // change color to red
    wr32(RAM_DL + 32, POINT_SIZE(320)); // set point size to 20 pixels in radius
    wr32(RAM_DL + 36, BEGIN(POINTS)); // start drawing points
    wr32(RAM_DL + 40, VERTEX2II(192, 133, 0, 0)); // red point
    wr32(RAM_DL + 44, END());
    wr32(RAM_DL + 48, DISPLAY()); // display the image
    
    /*
    wr8(REG_DITHER, 0); // output number of bits
    wr16(REG_OUTBITS, 0x01B6); // output bits resolution
    //wr8(REG_RENDERMODE, 0); // 0 normal, 1 write, 2 read
    
    //wr32(REG_FREQUENCY, 48000000); // main clock frequency
    wr8(REG_ROTATE, 0); // rotate display 180 degrees: 1 - rotate enable, 0 - rotate disable

    wr8(REG_GPIO_DIR,0x80 | rd8(REG_GPIO_DIR));
    wr8(REG_GPIO,0x080 | rd8(REG_GPIO));//enable display bit
    //wr8(REG_GPIO,0x80);
    wr8(REG_GPIO_DIR, 0xfc);
    wr8(REG_GPIO, 0xff);

    cmd_wait();
    */
    
    
    
    LED_1_SetLow();
    
    while (1)
{ // LOGO test
        /*
        cmd(CMD_DLSTART);
        cmd(CLEAR_COLOR_RGB(255, 0, 0));
        cmd(CLEAR(1, 1, 1));
        cmd_text(240, 136, 27, OPT_CENTER, "Please tap the dots to calibrate the display");
        cmd_exec();
        cmd_wait();
        */
        //host_command(FT_CLKEXT);
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