//
// Created by Timur on 04.03.2021.
//

#ifndef RECT_MATRIX_VOID_MATRIX_H

#define RECT_MATRIX_VOID_MATRIX_H

#include "MatrixInfo.h"
#include <stdio.h>

typedef struct matrix
{
    void **data;
    MatrixInfo *info;
} Matrix;

Matrix *CreateZeroMatrix (MatrixInfo *);

Matrix *CreateOneMatrix (MatrixInfo *);

Matrix *CreateFromValues (MatrixInfo *, void **);

Matrix *CopyMatrix (Matrix *);

void *getElem (Matrix *, size_t, size_t);

void setElem (Matrix *, void *, size_t, size_t);

Matrix *sumMatrix (Matrix *, Matrix *, int *);

Matrix *scalarMult (Matrix *, void *);

Matrix *matrixMult (Matrix *, Matrix *, int *);

Matrix *matrixTranspose (Matrix *);

void deleteMatrix (Matrix *);

#endif //RECT_MATRIX_VOID_MATRIX_H
