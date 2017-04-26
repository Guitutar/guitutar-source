#include <stdint.h>
#include "peripheral/ports/plib_ports.h"
#include "peripheral/ports/processor/ports_p32mx570f512l.h"
#include "guitutar.h"

PORTS_CHANNEL getChannelFretSerial(int fretNum) {
//    return PORT_CHANNEL_A;
    switch(fretNum){
        // PCB 1 Decoding
        case 0:
            return PORT_CHANNEL_E;
        case 1:
            return PORT_CHANNEL_E;
        case 2:
            return PORT_CHANNEL_E;
        case 3:
            return PORT_CHANNEL_G;
        // PCB 2 Decoding
        case 4:
            return PORT_CHANNEL_C;
        case 5:
            return PORT_CHANNEL_C;
        case 6:
            return PORT_CHANNEL_D;
        // PCB 3 Decoding
        case 7:
            return PORT_CHANNEL_D;
        case 8:
            return PORT_CHANNEL_D;
        case 9:
            return PORT_CHANNEL_A;
        case 10:
            return PORT_CHANNEL_A;
        // PCB 4 Decoding
        case 11:
            return PORT_CHANNEL_F;
        case 12:
            return PORT_CHANNEL_A;
        case 13:
            return PORT_CHANNEL_A;
        case 14:
            return PORT_CHANNEL_F;
        case 15:
            return PORT_CHANNEL_F;
    }
}

PORTS_CHANNEL getChannelFretInputClk(int fretNum) {
    return PORT_CHANNEL_A;
}

PORTS_CHANNEL getChannelFretOutputClk(int fretNum) {
    return PORT_CHANNEL_D;
}

PORTS_BIT_POS getBitPosFretSerial(int fretNum) {
//    return PORTS_BIT_POS_4;
    switch(fretNum){
        // PCB 1 Decoding
        case 0:
            return PORTS_BIT_POS_4;
        case 1:
            return PORTS_BIT_POS_3;
        case 2:
            return PORTS_BIT_POS_2;
        case 3:
            return PORTS_BIT_POS_13;
        // PCB 2 Decoding
        case 4:
            return PORTS_BIT_POS_14;
        case 5:
            return PORTS_BIT_POS_13;
        case 6:
            return PORTS_BIT_POS_0;
        // PCB 3 Decoding
        case 7:
            return PORTS_BIT_POS_11;
        case 8:
            return PORTS_BIT_POS_10;
        case 9:
            return PORTS_BIT_POS_5;
        case 10:
            return PORTS_BIT_POS_4;
        // PCB 4 Decoding
        case 11:
            return PORTS_BIT_POS_3;
        case 12:
            return PORTS_BIT_POS_2;
        case 13:
            return PORTS_BIT_POS_3;
        case 14:
            return PORTS_BIT_POS_8;
        case 15:
            return PORTS_BIT_POS_2;
    }
}

PORTS_BIT_POS getBitPosFretInputClk(int fretNum) {
    return PORTS_BIT_POS_15;
}

PORTS_BIT_POS getBitPosFretOutputClk(int fretNum) {
    return PORTS_BIT_POS_8;
}

Note createNote(int fretNum, String string) {
    Note note;
    note.fret = fretNum;
    note.string = string;
    return note;
}

void displayNote(uint8_t fret, int fretNum) {
    PORTS_CHANNEL serialChannel = getChannelFretSerial(fretNum);
    PORTS_CHANNEL inputClockChannel = getChannelFretInputClk(fretNum);
    PORTS_CHANNEL outputClockChannel = getChannelFretOutputClk(fretNum);
    
    PORTS_BIT_POS serialBitPos = getBitPosFretSerial(fretNum);
    PORTS_BIT_POS inputClockBitPos = getBitPosFretInputClk(fretNum);
    PORTS_BIT_POS outputClockBitPos = getBitPosFretOutputClk(fretNum);
    
    int i;
    for(i = 0; i < 8; ++i) {
        bool serialVal = fret & 1;
        SYS_PORTS_PinWrite(PORTS_ID_0, serialChannel, serialBitPos, serialVal);
        clockPin(inputClockChannel, inputClockBitPos);
        
        fret = fret >> 1;
    }
    clockPin(outputClockChannel, outputClockBitPos);
}

void clockPin(PORTS_CHANNEL channel, PORTS_BIT_POS bitPos) {
    SYS_PORTS_PinWrite(PORTS_ID_0, channel, bitPos, true); // input serial values
    SYS_PORTS_PinWrite(PORTS_ID_0, channel, bitPos, false);
}

void shiftRegClear() {
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_14, true);
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_14, false);
    SYS_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_14, true);
}

void emptyFretboard(uint8_t* fretboardArray, int numFrets) {
    int i;
    for(i = 0; i < numFrets; ++i)
        fretboardArray[i] = 0;
}

void updateFretboard(uint8_t* fretboardArray, Note note) {
    fretboardArray[note.fret] ^= (1 << note.string);
}

void displayFretboard(uint8_t* fretboardArray) {
    
}