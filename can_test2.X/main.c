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
/*    
    cmd(CMD_LOGO);
    cmd_exec();
    while(rd16(REG_CMD_WRITE) != 0){}
    cmd_wait();

    wait3secs();
    
    cmd(CMD_DLSTART);
    cmd(CLEAR_COLOR_RGB(255,0,0));
    cmd(CLEAR(1,1,1));
    cmd_text(240, 136, 27, OPT_CENTER, "Please tap the dots to calibrate the display");
    cmd_calibrate();
    cmd_exec();
    cmd_wait();
    
    wait3secs();
    
    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1)); // clear screen
    cmd_button(10, 10, 140, 100, 31, 0, "Press!");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_text(10, 10, 31, 0, "Hello ceci est un test!");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_button(10, 10, 50, 25, 26, 0, "One");
    cmd_button(10, 40, 50, 25, 26, 0, "Two");
    cmd_button(10, 70, 50, 25, 26, 0, "Three");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_keys(2, 2, 156, 21, 20, OPT_CENTER, "qwertyuiop");
    cmd_keys(2, 26, 156, 21, 20, OPT_CENTER, "asdfghijkl");
    cmd_keys(2, 50, 156, 21, 20, OPT_CENTER, "zxcvbnm");
    cmd_button(2, 74, 156, 21, 20, 0, "");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_keys(22, 1, 116, 28, 29, 0, "789");
    cmd_keys(22, 31, 116, 28, 29, 0, "456");
    cmd_keys(22, 61, 116, 28, 29, 0, "123");
    cmd_keys(22, 91, 116, 28, 29, 0, "0.");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_clock(80, 60, 50, 0, 8, 15, 0, 0);
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_gauge(80, 60, 50, 0, 5, 4, 30, 100);
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_gradient(0, 0, 0x0000ff, 160, 0, 0xff0000);
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd(SCISSOR_XY(20, 40));
    cmd(SCISSOR_SIZE(120, 32));
    cmd_gradient(20, 0, 0x606060, 140, 0, 0x404080);
    cmd_text(23, 40, 29, 0, "Heading 1");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();
*/
    LCD_PD_SetLow();
    
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