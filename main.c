/*******************************************************************************
  MPLAB Harmony Project Main Source File

  Company:
    Microchip Technology Inc.
  
  File Name:
    main.c

  Summary:
    This file contains the "main" function for an MPLAB Harmony project.

  Description:
    This file contains the "main" function for an MPLAB Harmony project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state 
    machines of all MPLAB Harmony modules in the system and it calls the 
    "SYS_Tasks" function from within a system-wide "super" loop to maintain 
    their correct operation. These two functions are implemented in 
    configuration-specific files (usually "system_init.c" and "system_tasks.c")
    in a configuration-specific folder under the "src/system_config" folder 
    within this project's top-level folder.  An MPLAB Harmony project may have
    more than one configuration, each contained within it's own folder under
    the "system_config" folder.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

//Microchip licenses to you the right to use, modify, copy and distribute
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
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
 
#define _SUPPRESS_PLIB_WARNING 1

//#include <plib.h>
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "system/common/sys_module.h"   // SYS function prototypes
#include "peripheral/ports/plib_ports.h"
#include "peripheral/ports/processor/ports_p32mx570f512l.h"
#include "guitutar.h"


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

void wait4next(bool timeMode, RollAvg *raPtr, int fretNum) {
    //bool currVal = true;
    if (timeMode){
        if (raPtr->total != 0){
            initRollAvg(raPtr);
        }
        int i;
        for (i = 0; i < CONST_WAIT_TIME; i++){}
    } else {
        while(isAvgOn(raPtr) || isFretPressed(fretNum)){
            addToAvg(raPtr, SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_5));
            //currVal = SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_5);
        }
        while(!isAvgOn(raPtr) || !isFretPressed(fretNum)){
            addToAvg(raPtr, SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_5));
            //currVal = SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_5);
        }
//        while(!isNoteBeingPlayed(fretNum)){}
//        while(isNoteBeingPlayed(fretNum)){}
    }   
}

void basicSong() {
    RollAvg rollAvg = newRollAvg();
    displayNote(16,10);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 10);

    displayNote(32,10);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 10);

    displayNote(64,10);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 10);
    
    displayNote(16,9);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 9);
    
    displayNote(32,9);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 9);
    
    displayNote(64,9);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 9);
    
    displayNote(16,11);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 11);
    
    displayNote(32,12);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 12);
    
    displayNote(64,11);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 11);
    
    displayNote(64,10);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 10);
    
    displayNote(64,12);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 12);
    
    displayNote(64,3);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 3);
    
    displayNote(64,13);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9), &rollAvg, 13);
}

void smokeonthewater() {
    RollAvg rollAvg = newRollAvg();
    displayNote(48, 0);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 0);
    
    displayNote(48, 3);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 3);
    
    displayNote(48, 5);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 5);
    
    displayNote(48, 0);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 0);
    
    displayNote(48, 3);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 3);
    
    displayNote(48, 6);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 6);
    
    displayNote(48, 5);
    wait4next(SYS_PORTS_PinRead(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_1), &rollAvg, 5);
}

int main ( void )
{
    /* Initialize all MPLAB Harmony modules, including application(s). */
    SYS_Initialize ( NULL );
    SYS_PORTS_Initialize();

    shiftRegClear();
    clockPin(PORT_CHANNEL_D, PORTS_BIT_POS_8);
    
    //RollAvg rollAvg = newRollAvg();
//    Chord testChord;
//    clearChord(&testChord);
//    Note note;
//    note.noteByte = 107;
//    addNote(&testChord, note);
//    while(true){
//        displayChord(testChord);
//    }
//    runTestSong();
//    runDemo();
    //Chord chord;
    //clearChord(&chord);

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
       basicSong();
        
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

//#define SYS_FREQ 			(80000000L)
//#define SHORT_DELAY (500*80)
//
//char bitmap[14] = {
//    0x01,
//    0x02,
//    0x04,
//    0x08,
//    0x10,
//    0x20,
//    0x40,
//    0x80,
//    0x40,
//    0x20,
//    0x10,
//    0x08,
//    0x04,
//    0x02,
//};
//
//int main(void)
//{
//	int i, j, k;
//
//    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	// Configure the device for maximum performance but do not change the PBDIV
//	// Given the options, this function will change the flash wait states, RAM
//	// wait state and enable prefetch cache but will not change the PBDIV.
//	// The PBDIV value is already set via the pragma FPBDIV option above..
//	SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
//
//	// Explorer16 LEDs are on lower 8-bits of PORTA and to use all LEDs, JTAG port must be disabled.
//	mJTAGPortEnable(DEBUG_JTAGPORT_OFF);
//
//	// Make all lower 8-bits of PORTA as output. Turn them off before changing
//	// direction so that we don't have unexpected flashes
//	mPORTAClearBits(BIT_7 | BIT_6 | BIT_5 | BIT_5 | BIT_4 | \
//							 BIT_3 | BIT_2 | BIT_1 | BIT_0 );
//
//	mPORTASetPinsDigitalOut( BIT_7 | BIT_6 | BIT_5 | BIT_5 | BIT_4 | \
//							 BIT_3 | BIT_2 | BIT_1 | BIT_0 );
//    
//    // Start timer1, Fpb/256, max period
//    OpenTimer1(T1_ON | T1_PS_1_256 | T1_SOURCE_INT, 0xFFFF);
// 
//
//	// Now blink all LEDs ON/OFF forever.
//    
//	while(1)
//	{
////		mPORTAToggleBits(BIT_7 | BIT_6 | BIT_5 | BIT_5 | BIT_4 | \
////							 BIT_3 | BIT_2 | BIT_1 | BIT_0 );
//        
////        for(j = 0; j < 14; ++j) {
////            PORTA = bitmap[j];
////            
////            // Short pause
////            WriteTimer1(0);
////            while ( TMR1 < SHORT_DELAY);
////        }
//        char x = 0x01;
//        for(j = 0; j < 8; ++j) {
//            for(k = 0; k < j; ++k) {
//                x = x << 1;
//                PORTA = x;
//                // Short pause
//                WriteTimer1(0);
//                while ( TMR1 < SHORT_DELAY);
//            }
//            for(k = j; k > 0; --k) {
//                x = x >> 1;
//                PORTA = x;
//                // Short pause
//                WriteTimer1(0);
//                while ( TMR1 < SHORT_DELAY);
//            }
//        }
//	}
//}

/*******************************************************************************
 End of File
*/

