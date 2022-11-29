
#ifndef LedMapping_H
#define LedMapping_H

#include "LedWord.h"

const LedWord PREFIX_IT = LedWord(0, 5, 1); // ES
const LedWord PREFIX_IS = LedWord(0, 5, 1); // IST

const LedWord INFIX_BEFORE = LedWord(0, 5, 1); // VOR
const LedWord INFIX_AFTER = LedWord(0, 5, 1);  // NACH

const LedWord SUFFIX_OCLOCK = LedWord(0, 5, 1); // UHR

const LedWord MINUTE_FIVE = LedWord(0, 5, 1);         // FÜNF
const LedWord MINUTE_TEN = LedWord(0, 5, 1);          // ZEHN
const LedWord MINUTE_QUARTER = LedWord(0, 5, 1);      // VIERTEL
const LedWord MINUTE_TWENTY = LedWord(0, 5, 1);       // ZWANZIG
const LedWord MINUTE_HALF = LedWord(0, 5, 1);         // HALB
const LedWord MINUTE_THREEQUARTER = LedWord(0, 5, 1); // THREEVIERTEL

const LedWord HOURS[] = {
    LedWord(0, 5, 1), // EINS
    LedWord(0, 5, 1), // ZWEI
    LedWord(0, 5, 1), // DREI
    LedWord(0, 5, 1), // VIER
    LedWord(0, 5, 1), // FÜNF
    LedWord(0, 5, 1), // SECHS
    LedWord(0, 5, 1), // SIEBEN
    LedWord(0, 5, 1), // ACHT
    LedWord(0, 5, 1), // NEUN
    LedWord(0, 5, 1), // ZEHN
    LedWord(0, 5, 1), // ELF
    LedWord(0, 5, 1)  // ZWÖLF
};

const LedWord WORD_FUNK = LedWord(0, 5, 1);

#endif /* LedMapping_H */
