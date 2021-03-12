#include "complex.h"

complex make_complex (float a, float b)
{
    complex rez;
    rez.real = a;
    rez.imagine = b;
    return rez;
}

complex enter_complex ()
{
    float real, imagine;
    scanf ("%f %f", &real, &imagine);
    return make_complex(real, imagine);
}

void print_complex (complex a)
{
    if (a.real * a.real + a.imagine * a.imagine == 0)
        printf ("0\t");
    else if (a.real == 0)
        printf ("%fi\t", a.imagine);
    else if (a.imagine > 0)
        printf ("%f + %fi\t", a.real, a.imagine);
    else if (a.imagine == 0)
        printf ("%f\t", a.real);
    else if (a.imagine == -1)
        printf ("%f - i\t", a.real);
    else if (a.imagine == 1)
        printf ("%f + i\t", a.real);
    else if (a.imagine < 0)
        printf ("%f - %fi\t", a.real, (-1) *a.imagine);
}

complex complex_conj (complex a)
{
    return (make_complex(a.real, (-1) * a.imagine));
}

complex complex_mult (complex a, complex b)
{
    complex rez;
    rez.real = a.real * b.real - a.imagine * b.imagine;
    rez.imagine = a.imagine * b.real + b.imagine * a.real;
    return rez;
}

complex complex_sum (complex a, complex b)
{
    complex rez;
    rez.real = a.real + b.real;
    rez.imagine = a.imagine + b.imagine;
    return rez;
}

complex complex_sub (complex a, complex b)
{
    complex rez;
    rez.real = a.real - b.real;
    rez.imagine = a.imagine - b.imagine;
    return rez;
}

complex complex_div (complex a, complex b)
{
    if (b.real * b.real + b.imagine * b.imagine == 0)
    {
        printf ("Division by zero!\n");
        exit(1);
    }
    complex tmp = complex_mult (a, complex_conj(b));
    return (complex_mult(tmp, make_complex(1.0 / (b.real * b.real + b.imagine * b.imagine), 0)));
}

int isequal_cmp (complex a, complex b)
{
    if ((a.real == b.real) && (a.imagine == b.imagine))
        return 1;
    return 0;
}
