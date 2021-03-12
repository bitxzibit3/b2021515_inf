#ifndef LAB1_1_COMPLEX_H
#define LAB1_1_COMPLEX_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct complex
{
    float real, imagine;
} complex;


complex make_complex (float , float );

complex enter_complex ();

void print_complex (complex );

complex complex_conj (complex );

complex complex_mult (complex , complex );

complex complex_sum (complex , complex );

complex complex_sub (complex, complex);

complex complex_div (complex , complex );

int isequal_cmp (complex , complex);

#endif //LAB1_1_COMPLEX_H
