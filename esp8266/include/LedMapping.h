
#ifndef LedMapping_H
#define LedMapping_H

#include "LedWord.h"

const LedWord PREFIX_SONO = LedWord(0, 0, 4); // SONO
const LedWord PREFIX_LE = LedWord(5, 0, 2);   // LE
const LedWord PREFIX_E = LedWord(0, 1, 1);    // È
const LedWord PREFIX_L = LedWord(2, 1, 1);    // L'

const LedWord BEFORE_MENO = LedWord(7, 6, 4); // MENO
const LedWord AFTER_E = LedWord(8, 6, 1);     // E

const LedWord MINUTE_FIVE = LedWord(5, 8, 6);           // CINQUE
const LedWord MINUTE_TEN = LedWord(0, 10, 5);           // DIECI
const LedWord MINUTE_QUARTER_INFIX = LedWord(2, 7, 2);  // UN
const LedWord MINUTE_QUARTER_SUFFIX = LedWord(5, 7, 5); // QUARTO
const LedWord MINUTE_TWENTY = LedWord(0, 8, 5);         // VENTI
const LedWord MINUTE_HALF = LedWord(6, 9, 5);           // MEZZA

const LedWord HOURS[] = {
    LedWord(3, 1, 3), // UNA
    LedWord(7, 1, 3), // DUE
    LedWord(0, 2, 3), // TRE
    LedWord(0, 5, 7), // QUATTRO
    LedWord(5, 6, 5), // CINQUE
    LedWord(8, 5, 3), // SEI
    LedWord(6, 4, 5), // SETTE
    LedWord(3, 2, 4), // OTTO
    LedWord(7, 2, 4), // NOVE
    LedWord(0, 3, 5), // DIECI
    LedWord(5, 3, 6), // UNDICI
    LedWord(0, 4, 6)  // DODICI
};

#endif /* LedMapping_H */
