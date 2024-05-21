# Precision_Notation_C
Using scientific notation as the base, precision notation is about being able to do math with up to 114 digits of precision.

\
Numbers are stored as below:\
Significand Sign, Whole Integer Significand, Exponent Sign, Whole Integer Exponent

This shows up as the type struct "Precise_t":
```C
typedef struct Precise {
    uint8_t significandSign; // 0+ 1-
    uint64_t significand[6]; // 0 - 3.94E115 total, 0 - 1.84E19 each
    uint8_t exponentSign; // 0+ 1-
    uint8_t exponent; // 0 - 255
} Precise;
```

Example:
```C
Precise myNum = {0, 123456789, 1, 4}; // +123457689 * 10^(-4) = 123456.789
```

\
Math works with included functions:
```C
Precise newNum;
newNum = add_precise(myNum, (Precise){0, {0, 0, 0, 0, 0, 2}, 0, 0}); // 123456.789 + 2 = 123458.789
newNum = sub_precise(myNum, (Precise){0, {0, 0, 0, 0, 0, 2}, 0, 0}); // 123456.789 - 2 = 123454.789
newNum = mult_precise(myNum, (Precise){0, {0, 0, 0, 0, 0, 2}, 0, 0}); // 123456.789 * 2 = 246913.578
newNum = div_precise(myNum, (Precise){0, {0, 0, 0, 0, 0, 2}, 0, 0}); // 123456.789 / 2 = 61728.3945
newNum = exp_precise(myNum, (Precise){0, {0, 0, 0, 0, 0, 2}, 0, 0}); // 123456.789 ^ 2 = 15241578750.190521
```

If any math function results in a repeating decimal, the number is truncated to 115 digits of precision.
```C
newNum = div_precise((Precise){0, {0, 0, 0, 0, 0, 5}, 0, 0}, (Precise){0, {0, 0, 0, 0, 0, 3}, 0, 0});
// 5 / 3
// 1.3(repeating)
// (Precise){0, {1333333333333333333, 3333333333333333333, 3333333333333333333, 3333333333333333333, 3333333333333333333, 3333333333333333333}, 1, 113}
```
