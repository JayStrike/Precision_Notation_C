#include "Precision_Notation.h"

// Checks precise number for overflows and adjusts accordingly
// Returns 1 on overflow error, 0 if fine
uint8_t check_precise(Precise* num) {
  // make signs 1 or 0 for safety
  if (num->significandSign != 0) num->significandSign == 1;
  if (num->exponentSign != 0) num->exponentSign == 1;
  
  uint8_t overflow = 0;
  
  // significand overflow check
  for (int i = 5; i >= 0; i--) {
    // add overflow from previous
    if (overflow) {
      num->significand[i] += overflow;
      overflow = 0;
    }

    // overflow at 10^18
    if (num->significand[i] >= 1000000000000000000) {
      overflow = num->significand[i] / 1000000000000000000;
      num->significand[i] -= 1000000000000000000 * overflow;
    }
  }

  // exponent zero check (zero should be positive)
  if (num->exponent == 0 && num->exponentSign != 0) num->exponentSign = 0;
  
  // overflow on greatest significand check
  if (overflow) {
    // return error one if exponent is at positive maximum
    if (num->exponentSign == 0 && num->exponent == 255) return 1;
    
    // increase exponent (add if positive, sub if negative, flip at 0)
    if (num->exponentSign == 0) // add if positive {
      num->exponent += 1;
    }
    else // sub if negative {
      num->exponent -= 1;

      if (num->exponent == 0) // flip if zero {
        num->exponentSign = 0;
      }
    }

    // downshift significand by factor of 10
    for (int i = 0; i < 6; i++) {
      num->significand[i] = num->significand[i] / 10; // right shift 1 base 10
      if (i != 5) num->significand[i] += (num->significand[i+1] % 10) * 100000000000000000; // 10^17 to fill 18th slot
    }
  }

  // return no error 0
  return 0;
}

// Adds two precise numbers, avoiding over- or under-flow
// Returns 1 on overflow error, 0 if fine
int add_precise(Precise a, Precise b, Precise* result) {
  // return error 1 if inputs are bad
  if (check_precise(&a) + check_precise(&b) != 0) return 1;
  
  // check for over- and under-flow

  // if a or b are too small to change the other, return the other
  //TODO: Figure out how to add properly
  
  // add a and b
  Precise sum;
  

  // transfer sum to result (so result can be initial address of a or b)
  result->significandSign = sum.significandSign;
  for (int i = 0; i < 6; i++) {
    result->significand[i] = sum.significand[i];
  }
  result->exponentSign = sum.exponentSign;
  result->exponent = sum.exponent;

  // no error 0 return
  return 0;
}
