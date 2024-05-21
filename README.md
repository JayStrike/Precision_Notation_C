# Precision_Notation_C
Using scientific notation as the base, precision notation is about being able to do math with up to 100 digits of precision.


Numbers are stored as below:
Significand Sign, Whole Integer Significand, Exponent Sign, Whole Integer Exponent

This shows up as the struct "Precise":
typedef struct Precise {
  uint1_t significandSign;
  uint333_t significand;
  uint1_t exponentSign;
  uint7_t exponent;
} Precise;

Example:
Precise myNum = {0, 123456789, 1, 4}; // +123457689 * 10^(-4) = 123456.789


Math works with included functions:
Precise newNum;
newNum = add_precise(myNum, (Precise){0, 2, 0, 0}); // 123456.789 + 2 = 123458.789
newNum = sub_precise(myNum, (Precise){0, 2, 0, 0}); // 123456.789 - 2 = 123454.789
newNum = mult_precise(myNum, (Precise){0, 2, 0, 0}); // 123456.789 * 2 = 246913.578
newNum = div_precise(myNum, (Precise){0, 2, 0, 0}); // 123456.789 / 2 = 61728.3945
newNum = exp_precise(myNum, (Precise){0, 2, 0, 0}); // 123456.789 ^ 2 = 15241578750.190521

If any math function results in a repeating decimal, the number is truncated to 100 digits of precision.
  newNum = div_precise((Precise){0, 5, 0, 0}, (Precise){0, 3, 0, 0});
  5 / 3 = 1.3(repeating) = (Precise){0, 1333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333, 1, 99}
