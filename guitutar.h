#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
#ifndef CONST_WAIT_TIME
#define CONST_WAIT_TIME 10000000
#endif
    
#ifndef AVG_SAMPLE_SIZE
#define AVG_SAMPLE_SIZE 10000
#endif
    
#ifndef AVG_THRESHOLD
#define AVG_THRESHOLD AVG_SAMPLE_SIZE/10000
#endif
    
typedef enum String_t {
    E = 0,
    A = 1,
    D = 2,
    G = 3,
    B = 4,
    e = 5
} String;

typedef union Note_t {
    uint8_t noteByte;
    struct {
        uint8_t string : 3;
        uint8_t fret   : 5;
    };
} Note;

// COLE
/*typedef struct Delay_t{
    Note time;
    Note *next;
} Delay;*/

typedef struct Chord_t {
    Note E;
    Note A;
    Note D;
    Note G;
    Note B;
    Note e;
    // Delay delay; COLE
} Chord;

typedef struct Song_t {
    int size;
    int bpm;
    Note* notes;
} Song;

typedef struct RollAvg_t{
    int edge;
    bool samples[AVG_SAMPLE_SIZE];
    int total;
} RollAvg;

RollAvg newRollAvg();
void initRollAvg(RollAvg *raPtr);
void addToAvg(RollAvg *raPtr, bool value);
bool isAvgOn(RollAvg *raPtr);

Note createNote(int fretNum, String string);
void displayNote(uint8_t fret, int fretNum);
Chord createChord(Note E, Note A, Note D, Note G, Note B, Note e);
void displayChord(Chord chord);
//Chord *newChord();
//int addNote(Chord *cPtr);
//int addDelay(Chord *cPtr);

void emptyFretboard(uint8_t* fretboardArray, int numFrets);

PORTS_CHANNEL getChannelFretSerial(int fretNum);
PORTS_CHANNEL getChannelFretInputClk(int fretNum);
PORTS_CHANNEL getChannelFretOutputClk(int fretNum);
PORTS_BIT_POS getBitPosFretSerial(int fretNum);
PORTS_BIT_POS getBitPosFretInputClk(int fretNum);
PORTS_BIT_POS getBitPosFretOutputClk(int fretNum);

void clockPin(PORTS_CHANNEL channel, PORTS_BIT_POS bitPos);

bool isNoteCorrect(int fretNum);



    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
