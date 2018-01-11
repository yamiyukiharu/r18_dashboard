#include<xc.h>
#include "mcc_generated_files/mcc.h"
#include "Gue/FT800.h"
#include "display.h"
#include "mcc_generated_files/ecan.h"

#define FT_ACTIVE  0x00
#define FT_STANDBY 0x41
#define FT_SLEEP   0x42
#define FT_PWRDOWN 0x50
#define FT_CLKEXT  0x44
#define FT_CLK48M  0x62
#define FT_CLK36M  0x61
#define FT_CORERST 0x68

unsigned long convertStandardCANid(unsigned char tempRXBn_SIDH, unsigned char tempRXBn_SIDL);

uCAN_MSG tempCanMsg;


void interrupt can_bus(void) {
    if(PIR5bits.RXB0IF) { //check if its CAN interrupt
        PIE5bits.RXB0IE = 0; //disable CAN interrupt
//        if(!RXB0CONbits.FILHIT2) { //Filter 3, ID=0x642
//            
//        } else if(RXB0CONbits.FILHIT2 & !RXB0CONbits.FILHIT0) { //Filter 4, ID=0x640
//            
//        } else if(RXB0CONbits.FILHIT2 & RXB0CONbits.FILHIT0) { //Filter 3, ID=0x641
//            
//        }
        tempCanMsg.frame.idType = (unsigned char) dSTANDARD_CAN_MSG_ID_2_0B;
        tempCanMsg.frame.id = convertStandardCANid(RXB0SIDH, RXB0SIDL);
        tempCanMsg.frame.dlc = RXB0DLC;
        tempCanMsg.frame.data0 = RXB0D0;
        tempCanMsg.frame.data1 = RXB0D1;
        tempCanMsg.frame.data2 = RXB0D2;
        tempCanMsg.frame.data3 = RXB0D3;
        tempCanMsg.frame.data4 = RXB0D4;
        tempCanMsg.frame.data5 = RXB0D5;
        tempCanMsg.frame.data6 = RXB0D6;
        tempCanMsg.frame.data7 = RXB0D7;
        RXB0CONbits.RXFUL = 0; //indicate that message is read
        PIE5bits.RXB0IE = 1; //enable CAN interrupt
    }
    
}

unsigned long convertStandardCANid(unsigned char tempRXBn_SIDH, unsigned char tempRXBn_SIDL) {
    unsigned long returnValue = 0;
    unsigned long ConvertedID;
    //if standard message (11 bits)
    //EIDH = 0 + EIDL = 0 + SIDH + upper three bits SIDL (3rd bit needs to be clear)
    //1111 1111 111
    ConvertedID = (tempRXBn_SIDH << 3);
    ConvertedID = ConvertedID + (tempRXBn_SIDL >> 5);
    returnValue = ConvertedID;
    return (returnValue);
}

void wait2secs(){
    __delay_ms(2000);
}

void main(void)
{   
    uCAN_MSG canMessage;
    int rpm = 0, oilP = 0, fuelP = 0, tp = 0, speed = 0, gear = 0, engTemp = 0, oilTemp = 0, battVolts = 0,
            brakeP_F = 0, brakeP_R = 0, radio_sw = 0;
    wait2secs(); 
    
    int y_start = 0;

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
    PIE5bits.RXB0IE = 1;
    
    // CAN FILTER CONFIG
    RXF5SIDH = 0xC8;
    RXF5SIDL = 0x00; //Filter for ID 0x640
    RXF4SIDH = 0xC8;
    RXF4SIDL = 0x20; //Filter for ID 0x641
    RXF3SIDH = 0xC8;
    RXF3SIDL = 0x40; //Filter for ID 0x642
    
    // SPI Configuration for LCD
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;
    SSPCON1bits.SSPEN = 1;
    SSPCON1bits.CKP = 1;
    SSPCON1bits.SSPM = 0b0000;     
    FT800_Init();
    
    EUSART1_Initialize();
 
    wait2secs(); 

    up_shift_SetLow();
    down_shift_SetLow();
    warning_1_SetLow();
    warning_2_SetHigh();
    warning_3_SetLow();
    warning_4_SetHigh();
    IO_RC2_SetHigh();
    
    display(rpm, oilP, fuelP, tp, speed, gear, engTemp, oilTemp, battVolts);
    
    while (1) {  
        if(CAN_receive(&canMessage)) {
            if(canMessage.frame.id == 0x640) {
                rpm = ((canMessage.frame.data0 << 8) | canMessage.frame.data1);
                oilP = ((canMessage.frame.data2 << 8) | canMessage.frame.data3)/10;
                fuelP = ((canMessage.frame.data0 << 4) | canMessage.frame.data5);
                tp = canMessage.frame.data6;
                speed = canMessage.frame.data7;
                warning_3_SetHigh();
                __delay_ms(200);
            } else if(canMessage.frame.id == 0x641) {
                brakeP_F = canMessage.frame.data0;
                brakeP_R = canMessage.frame.data1;
                gear = canMessage.frame.data6;
                radio_sw = canMessage.frame.data7 >> 7;
                warning_2_SetHigh();
                __delay_ms(200);
            } else if(canMessage.frame.id == 0x642) {
                engTemp = canMessage.frame.data0;
                oilTemp = canMessage.frame.data1;
                battVolts = canMessage.frame.data2;
            } else if(canMessage.frame.id == 0x643) {
                
                warning_1_SetHigh();
                __delay_ms(200);
            }
        //display(rpm, oilP, fuelP, tp, speed, gear, engTemp, oilTemp, battVolts); 
        display(rpm, oilP, fuelP, tp, radio_sw, gear, engTemp, oilTemp, battVolts); 
        
        up_shift_SetLow();
        down_shift_SetLow();
        warning_1_SetLow();
        warning_2_SetLow();
        warning_3_SetLow();
        warning_4_SetLow();
        }
        //__delay_ms(50);
    //    EUSART1_Write(0x53);    
    //-    up_shift_SetLow();
        //__delay_ms(50);        
    }
}


/**
 End of File
*/