#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
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

typedef struct Chord_t {
    Note E;
    Note A;
    Note D;
    Note G;
    Note B;
    Note e;
} Chord;

typedef struct Song_t {
    int size;
    int bpm;
    Note* notes;
} Song;

Note createNote(int fretNum, String string);
void displayNote(uint8_t fret, int fretNum);
Chord createChord(Note E, Note A, Note D, Note G, Note B, Note e);
void displayChord(Chord chord);

void emptyFretboard(uint8_t* fretboardArray, int numFrets);

PORTS_CHANNEL getChannelFretSerial(int fretNum);
PORTS_CHANNEL getChannelFretInputClk(int fretNum);
PORTS_CHANNEL getChannelFretOutputClk(int fretNum);
PORTS_BIT_POS getBitPosFretSerial(int fretNum);
PORTS_BIT_POS getBitPosFretInputClk(int fretNum);
PORTS_BIT_POS getBitPosFretOutputClk(int fretNum);

void clockPin(PORTS_CHANNEL channel, PORTS_BIT_POS bitPos);



    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
