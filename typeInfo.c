//
// Created by Timur on 04.03.2021.
//

#include "typeInfo.h"

TypeInfo *CreateTypeInfo (size_t size, void *zero, void *one, void *(*sum)(void *, void *), void *(*mult)(void *, void *))
{
    TypeInfo *TypeInform = (TypeInfo *)malloc(sizeof(TypeInfo));
    TypeInform->elemSize = size;
    TypeInform->one = one;
    TypeInform->zero = zero;
    TypeInform->mult = mult;
    TypeInform->sum = sum;
    return TypeInform;
}

TypeInfo *CopyTypeInfo (TypeInfo *oldTypeInfo)
{
    TypeInfo *newTypeInfo = (TypeInfo *) malloc (sizeof(TypeInfo));
    newTypeInfo->mult = oldTypeInfo->mult;
    newTypeInfo->sum = oldTypeInfo->sum;
    newTypeInfo->elemSize = oldTypeInfo->elemSize;
    newTypeInfo->one = oldTypeInfo->one;
    newTypeInfo->zero = oldTypeInfo->zero;
    return newTypeInfo;
}

int CompareTypes (TypeInfo *TypeInfo1, TypeInfo *TypeInfo2)
{
    if ((TypeInfo1->elemSize == TypeInfo2->elemSize) &&
        (TypeInfo1->sum == TypeInfo2->sum) &&
        (TypeInfo1->mult == TypeInfo2->mult) &&
        (TypeInfo1->one == TypeInfo2->one) &&
        (TypeInfo1->zero == TypeInfo2->zero))
            return 1;
    return 0;
}

void DeleteTypeInfo (TypeInfo *info) {
    free(info);
}