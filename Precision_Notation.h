/*
 * Header file for Precision_Notation.c
 */

#ifndef PRECISION_NOTATION_H_
#define PRECISION_NOTATION_H_

#include <inttypes.h> // formatting fixed width integers for print and scan
#include <stdint.h> // fixed width integers


// Base struct for precision functionality
typedef struct Precise {
    uint8_t significandSign; // 0+ 1-
    uint64_t significand[6]; // 0 - 3.94E115 total, 0 - 1.84E19 each
    uint8_t exponentSign; // 0+ 1-
    uint8_t exponent; // 0 - 255
} Precise;


// --- Function Prototypes ---

// Basic Operators
Precise* add_precise(Precise* a, Precise* b);
Precise* sub_precise(Precise* a, Precise* b);
Precise* mult_precise(Precise* a, Precise* b);
Precise* div_precise(Precise* a, Precise* b);
//Precise* exp_precise(Precise* a, Precise* b);


#endif // PRECISION_NOTATION_H_
