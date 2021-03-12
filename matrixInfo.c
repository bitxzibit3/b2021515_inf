//
// Created by Timur on 04.03.2021.
//

#include "matrixInfo.h"

MatrixInfo *NewMatrixInfo (TypeInfo *type, size_t lines, size_t columns)
{
    MatrixInfo *newInfo = (MatrixInfo *) malloc (sizeof (MatrixInfo));
    newInfo->typeInfo = CopyTypeInfo(type);
    newInfo->lines = lines;
    newInfo->columns = columns;
    return newInfo;
}

MatrixInfo *CopyMatrixInfo (MatrixInfo *oldInfo)
{
    MatrixInfo *newInfo = (MatrixInfo *) malloc (sizeof (MatrixInfo));
    newInfo->lines = oldInfo->lines;
    newInfo->columns = oldInfo->columns;
    newInfo->typeInfo = CopyTypeInfo(oldInfo->typeInfo);
    return newInfo;
}

int CompareMatrix (MatrixInfo *m1, MatrixInfo *m2)
{
    if (!CompareTypes(m1->typeInfo, m2->typeInfo)) //Нер-во типов.
        return 0;
    if ((m1->lines == m2->lines) && (m1->columns == m2->columns) && (m1->lines == m1->columns)) // Квадратная матрица
        return 3;
    if ((m1->lines == m2->lines) && (m1->columns == m2->columns))// Для сложения.
        return 1;
    if (m1->columns == m2->lines) // Для умножения матрицы на матрицу.
        return 2;
    return 4; // Типы равны, но ни для умножения, ни для сложение матрицы не годятся.
}

void deleteMatrixInfo (MatrixInfo *info)
{
    DeleteTypeInfo(info->typeInfo);
    free (info);
}