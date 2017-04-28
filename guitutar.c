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

PORTS_CHANNEL getChannelFretSwitch(int fretNum) {
    switch(fretNum){
        // PCB 1 Decoding
        case 1:
            return PORT_CHANNEL_E;
        case 2:
            return PORT_CHANNEL_A;
        case 3:
            return PORT_CHANNEL_A;
        // PCB 2 Decoding
        case 4:
            return PORT_CHANNEL_G;
        case 5:
            return PORT_CHANNEL_A;
        case 6:
            return PORT_CHANNEL_E;
        // PCB 3 Decoding
        case 7:
            return PORT_CHANNEL_E;
        case 8:
            return PORT_CHANNEL_B;
        case 9:
            return PORT_CHANNEL_B;
        case 10:
            return PORT_CHANNEL_B;
        // PCB 4 Decoding
        case 11:
            return PORT_CHANNEL_B;
        case 12:
            return PORT_CHANNEL_B;
        case 13:
            return PORT_CHANNEL_B;
        case 14:
            return PORT_CHANNEL_A;
        case 15:
            return PORT_CHANNEL_A;
    }
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

PORTS_BIT_POS getBitPosFretSwitch(int fretNum) {
    switch(fretNum){
        // PCB 1 Decoding
        case 1:
            return PORTS_BIT_POS_0;
        case 2:
            return PORTS_BIT_POS_7;
        case 3:
            return PORTS_BIT_POS_6;
        // PCB 2 Decoding
        case 4:
            return PORTS_BIT_POS_0;
        case 5:
            return PORTS_BIT_POS_0;
        case 6:
            return PORTS_BIT_POS_8;
        // PCB 3 Decoding
        case 7:
            return PORTS_BIT_POS_9;
        case 8:
            return PORTS_BIT_POS_5;
        case 9:
            return PORTS_BIT_POS_4;
        case 10:
            return PORTS_BIT_POS_3;
        // PCB 4 Decoding
        case 11:
            return PORTS_BIT_POS_2;
        case 12:
            return PORTS_BIT_POS_6;
        case 13:
            return PORTS_BIT_POS_7;
        case 14:
            return PORTS_BIT_POS_9;
        case 15:
            return PORTS_BIT_POS_10;
    }
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

void runDemo() {
    int i, j, k;
    while(true) {
        for(i = 7; i < 11; ++i) { // frets 0-15
//        i = 8;    
            for(j = 128; j >= 4; j /= 2) {
//            j = 128;
                shiftRegClear();
                clockPin(PORT_CHANNEL_D, PORTS_BIT_POS_8);
                //for (k = 0; k < CONST_WAIT_TIME; k++){}
                displayNote(j, i);
                for (k = 0; k < CONST_WAIT_TIME; k++){}
//                shiftRegClear();
//                displayNote(j*2, i);
//                for (k = 0; k < CONST_WAIT_TIME; k++){}
//                shiftRegClear();
//                displayNote(j*4, i);
//                for (k = 0; k < CONST_WAIT_TIME; k++){}
//                shiftRegClear();
//                displayNote(j*8, i);
//                for (k = 0; k < CONST_WAIT_TIME; k++){}
//                shiftRegClear();
//                displayNote(j*16, i);
//                for (k = 0; k < CONST_WAIT_TIME; k++){}
//                shiftRegClear();
//                displayNote(j*32, i);
//                for (k = 0; k < CONST_WAIT_TIME; k++){}
            }
        }
    }
}

bool isNoteBeingPlayed(int fretNum) {
    PORTS_CHANNEL noteChannel = getChannelFretSwitch(fretNum);
    PORTS_BIT_POS noteBitPos = getBitPosFretSwitch(fretNum);
    
    return !(SYS_PORTS_PinRead(PORTS_ID_0, noteChannel, noteBitPos));
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

RollAvg newRollAvg(){
    RollAvg result;
    result.edge = 0;
    initRollAvg(&result);
    return result;
}
void initRollAvg(RollAvg *raPtr){
    int i;
    for (i = 0; i < AVG_SAMPLE_SIZE; i++){
        raPtr->samples[i] = false;
    }
    raPtr->total = 0;
}
void addToAvg(RollAvg *raPtr, bool value){
    if(raPtr->samples[raPtr->edge] && !value){
        raPtr->total--;
        raPtr->samples[raPtr->edge] = value;
    }
    else if (!raPtr->samples[raPtr->edge] && value){
        raPtr->total++;
        raPtr->samples[raPtr->edge] = value;
    }
    raPtr->edge = ++raPtr->edge % AVG_SAMPLE_SIZE;
}
bool isAvgOn(RollAvg *raPtr){
    return (raPtr->total >= AVG_THRESHOLD);
}

//COLE
//Chord *newChord(){
    
//}