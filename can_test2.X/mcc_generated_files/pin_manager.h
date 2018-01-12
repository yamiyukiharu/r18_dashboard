/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.3
        Device            :  PIC18F46K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set warning_1 aliases
#define warning_1_TRIS               TRISAbits.TRISA0
#define warning_1_LAT                LATAbits.LATA0
#define warning_1_PORT               PORTAbits.RA0
#define warning_1_ANS                ANCON0bits.ANSEL0
#define warning_1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define warning_1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define warning_1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define warning_1_GetValue()           PORTAbits.RA0
#define warning_1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define warning_1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define warning_1_SetAnalogMode()  do { ANCON0bits.ANSEL0 = 1; } while(0)
#define warning_1_SetDigitalMode() do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set up_shift aliases
#define up_shift_TRIS               TRISAbits.TRISA1
#define up_shift_LAT                LATAbits.LATA1
#define up_shift_PORT               PORTAbits.RA1
#define up_shift_ANS                ANCON0bits.ANSEL1
#define up_shift_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define up_shift_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define up_shift_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define up_shift_GetValue()           PORTAbits.RA1
#define up_shift_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define up_shift_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define up_shift_SetAnalogMode()  do { ANCON0bits.ANSEL1 = 1; } while(0)
#define up_shift_SetDigitalMode() do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()    do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()   do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()   do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()         PORTBbits.RB2
#define RB2_SetDigitalInput()   do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()  do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()     do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()   do { WPUBbits.WPUB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()    do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()   do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()   do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()         PORTBbits.RB3
#define RB3_SetDigitalInput()   do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()  do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()     do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()   do { WPUBbits.WPUB3 = 0; } while(0)

// get/set LCD_INT aliases
#define LCD_INT_TRIS               TRISBbits.TRISB4
#define LCD_INT_LAT                LATBbits.LATB4
#define LCD_INT_PORT               PORTBbits.RB4
#define LCD_INT_WPU                WPUBbits.WPUB4
#define LCD_INT_ANS                ANCON1bits.ANSEL9
#define LCD_INT_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LCD_INT_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LCD_INT_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LCD_INT_GetValue()           PORTBbits.RB4
#define LCD_INT_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LCD_INT_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LCD_INT_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define LCD_INT_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define LCD_INT_SetAnalogMode()  do { ANCON1bits.ANSEL9 = 1; } while(0)
#define LCD_INT_SetDigitalMode() do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set warning_2 aliases
#define warning_2_TRIS               TRISBbits.TRISB5
#define warning_2_LAT                LATBbits.LATB5
#define warning_2_PORT               PORTBbits.RB5
#define warning_2_WPU                WPUBbits.WPUB5
#define warning_2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define warning_2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define warning_2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define warning_2_GetValue()           PORTBbits.RB5
#define warning_2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define warning_2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define warning_2_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define warning_2_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)

// get/set LCD_PD aliases
#define LCD_PD_TRIS               TRISCbits.TRISC1
#define LCD_PD_LAT                LATCbits.LATC1
#define LCD_PD_PORT               PORTCbits.RC1
#define LCD_PD_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LCD_PD_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LCD_PD_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LCD_PD_GetValue()           PORTCbits.RC1
#define LCD_PD_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LCD_PD_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()    do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()   do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()  do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()    do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()   do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()   do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()         PORTCbits.RC5
#define RC5_SetDigitalInput()   do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()  do { TRISCbits.TRISC5 = 0; } while(0)

// get/set LCD_CS aliases
#define LCD_CS_TRIS               TRISDbits.TRISD0
#define LCD_CS_LAT                LATDbits.LATD0
#define LCD_CS_PORT               PORTDbits.RD0
#define LCD_CS_ANS                ANCON1bits.ANSEL11
#define LCD_CS_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCD_CS_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCD_CS_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCD_CS_GetValue()           PORTDbits.RD0
#define LCD_CS_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCD_CS_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCD_CS_SetAnalogMode()  do { ANCON1bits.ANSEL11 = 1; } while(0)
#define LCD_CS_SetDigitalMode() do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set SD_CS aliases
#define SD_CS_TRIS               TRISDbits.TRISD1
#define SD_CS_LAT                LATDbits.LATD1
#define SD_CS_PORT               PORTDbits.RD1
#define SD_CS_ANS                ANCON1bits.ANSEL12
#define SD_CS_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SD_CS_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SD_CS_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SD_CS_GetValue()           PORTDbits.RD1
#define SD_CS_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SD_CS_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SD_CS_SetAnalogMode()  do { ANCON1bits.ANSEL12 = 1; } while(0)
#define SD_CS_SetDigitalMode() do { ANCON1bits.ANSEL12 = 0; } while(0)

// get/set warning_4 aliases
#define warning_4_TRIS               TRISDbits.TRISD3
#define warning_4_LAT                LATDbits.LATD3
#define warning_4_PORT               PORTDbits.RD3
#define warning_4_ANS                ANCON1bits.ANSEL14
#define warning_4_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define warning_4_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define warning_4_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define warning_4_GetValue()           PORTDbits.RD3
#define warning_4_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define warning_4_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define warning_4_SetAnalogMode()  do { ANCON1bits.ANSEL14 = 1; } while(0)
#define warning_4_SetDigitalMode() do { ANCON1bits.ANSEL14 = 0; } while(0)

// get/set down_shift aliases
#define down_shift_TRIS               TRISDbits.TRISD4
#define down_shift_LAT                LATDbits.LATD4
#define down_shift_PORT               PORTDbits.RD4
#define down_shift_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define down_shift_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define down_shift_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define down_shift_GetValue()           PORTDbits.RD4
#define down_shift_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define down_shift_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set warning_3 aliases
#define warning_3_TRIS               TRISDbits.TRISD5
#define warning_3_LAT                LATDbits.LATD5
#define warning_3_PORT               PORTDbits.RD5
#define warning_3_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define warning_3_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define warning_3_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define warning_3_GetValue()           PORTDbits.RD5
#define warning_3_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define warning_3_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/