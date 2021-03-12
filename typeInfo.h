//
// Created by Timur on 04.03.2021.
//

#ifndef RECT_MATRIX_MATRIX_INFO_H

#define RECT_MATRIX_MATRIX_INFO_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <CException.h>

typedef struct TypeInfo
{
    size_t elemSize;
    void* zero;
    void* one;
    void* (*sum)(void *, void *);
    void* (*mult)(void *, void *);
} TypeInfo;

TypeInfo *CreateTypeInfo (size_t, void *, void *, void *(*)(void *, void *), void *(*)(void *, void *));

TypeInfo *CopyTypeInfo (TypeInfo *);

int CompareTypes (TypeInfo *, TypeInfo *);

void DeleteTypeInfo (TypeInfo *);

#endif //RECT_MATRIX_MATRIX_INFO_H
