#include "Precision_Notation.h"

// Checks precise number for overflows and adjusts accordingly
void check_precise(Precise* num)
{
  // significand overflow check
  for (int i = 0; i < 6; i++)
  
  return;
}

// Adds two precise numbers, avoiding over- or under-flow
void add_precise(Precise a, Precise b, Precise* result)
{
  // check for over- and under-flow

  // add a and b
  Precise sum;

  // transfer sum to result (so result can be initial address of a or b)
  result->significandSign = sum.significandSign;
  for (int i = 0; i < 6; i++)
  {
    result->significand[i] = sum.significand[i];
  }
  result->exponentSign = sum.exponentSign;
  result->exponent = sum.exponent;

  return;
}
