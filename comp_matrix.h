//
// Created by Timur on 20.02.2021.
//

#ifndef LAB1_1_CompMatrix_H
#define LAB1_1_CompMatrix_H

#include "complex.h"
#include "void_matrix.h"


void *czero;

void *cone;

void *csum (void *, void *);

void *cmult (void *, void *);

TypeInfo *compInfo;

Matrix *newCMatrix (size_t, size_t);

void printCMatrix (Matrix *);

Matrix *sumCMatrix (int, int, int, int, int *);

Matrix *multCMatrix (int, int, int, int, int *);

#endif //LAB1_1_CompMatrix_H