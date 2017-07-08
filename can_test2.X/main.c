/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.1
        Device            :  PIC18F45K80
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 1;

    IO_RC0_SetDigitalOutput();
    IO_RC0_SetLow();
    
    LED_1_SetDigitalOutput();
    LED_1_SetLow();
    
    analog_1_SetAnalogMode();
    
    
    while (1)
    {
        uint16_t data = ADC_GetConversion(analog_1);
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
        
//        for(int i = 0; i<10; ++i);
        // Add your application code
    }
}
/**
 End of File
*/