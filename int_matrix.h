//
// Created by Timur on 20.02.2021.
//

#ifndef LAB1_1_INT_MATRIX_H
#define LAB1_1_INT_MATRIX_H

#include <stdio.h>
#include "void_matrix.h"

void *one;

void *zero;

TypeInfo *intInfo;

void *int_sum (void *, void *);

void *int_mult (void *, void *);

Matrix *newIntMatrixValue (size_t, size_t);

Matrix *sumIntMatrix (int, int, int, int, int *);

Matrix *multIntMatrix (int, int, int, int, int *);

Matrix *intTranspose (Matrix *);

void printIntMatrix (Matrix *);

#endif //LAB1_1_INT_MATRIX_H

