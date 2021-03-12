//
// Created by Timur on 04.03.2021.
//

#ifndef RECT_MATRIX_MATRIXINFO_H
#define RECT_MATRIX_MATRIXINFO_H

#include "typeInfo.h"

typedef struct MatrixInfo
{
    size_t lines;
    size_t columns;
    TypeInfo *typeInfo;
} MatrixInfo;

MatrixInfo *NewMatrixInfo (TypeInfo *, size_t, size_t);

MatrixInfo *CopyMatrixInfo (MatrixInfo *);

int CompareMatrix (MatrixInfo *, MatrixInfo *);

void deleteMatrixInfo (MatrixInfo *);

#endif //RECT_MATRIX_MATRIXINFO_H
