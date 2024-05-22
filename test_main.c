/*
 * Used for testing Precision_Notation_C library
 */

#include <stdio.h>
#include "Precision_Notation.h"

int main()
{
  // Create testing precision numbers
  Precise a; // -123E11
  a.significandSign = 100;
  a.significand = {0, 0, 0, 0, 0, 123};
  a.exponentSign = 0;
  a.exponent = 11;
  Precise b = {0, {0, 0, 0, 0, 0, 9999999999999999999}, 0, 10}; // 9999 99999 99999 99999 E10
  Precise c = {0, {0, 0, 0, 0, 0, 0}, 0, 0}; // 0E0
  Precise d = {0, {2222222222222222222, 0, 0, 0, 0, 0}, 0, 255}; // 22222 22222 22222 22222 E255 TOO BIG

  // test check_precise with normal and overflow numbers
  int error = check_precise(&a);
  error += check_precise(&b); // should overflow but not error
  error += check_precise(&c);
  error += check_precise(&d); // should error

  // test add_precise with various numbers
  Precise sum;
  error += add_precise(a, b, &sum); // should be 99...8769 E10
  error += add_precise(a, c, &sum); // should be a
  error += add_precise(a, d, &sum); // should error out with no change to sum
    
  return 0;
}
