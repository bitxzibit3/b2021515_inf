//
// Created by Timur on 04.03.2021.
//

#include "void_matrix.h"

Matrix *CreateZeroMatrix (MatrixInfo *info)
{
    Matrix *matrix = (Matrix *) malloc (sizeof(Matrix));
    matrix->info = CopyMatrixInfo(info);
    matrix->data = (void **) calloc (info->lines, sizeof (void *));
    for (size_t i = 0; i < info->lines; i++)
    {
        matrix->data[i] = (void *) calloc(info->columns, info->typeInfo->elemSize);
        for (size_t j = 0; j < info->columns; j++)
        {
            int8_t **temp_pointer = ((int8_t **)(matrix->data) + i * (info->typeInfo->elemSize) + j);
            memcpy ((void *)temp_pointer, info->typeInfo->zero, info->typeInfo->elemSize);
        }
    }
    return matrix;
}

Matrix *CreateOneMatrix (MatrixInfo *info)
{
    Matrix *matrix = (Matrix *) malloc (sizeof(Matrix));
    matrix->info = CopyMatrixInfo(info);
    matrix->data = (void **) calloc (info->lines, sizeof (void *));
    for (size_t i = 0; i < info->lines; i++)
    {
        matrix->data[i] = (void *) calloc(info->columns, info->typeInfo->elemSize);
        for (size_t j = 0; j < info->columns; j++)
        {
            int8_t **temp_pointer = ((int8_t **)(matrix->data) + i * (info->typeInfo->elemSize) + j);
            if (i != j)
                memcpy ((void *)temp_pointer, info->typeInfo->zero, info->typeInfo->elemSize);
            else
                memcpy ((void *)temp_pointer, info->typeInfo->one, info->typeInfo->elemSize);

        }
    }
    return matrix;
}
Matrix *CreateFromValues (MatrixInfo *info, void **data)
{
    Matrix *matrix = (Matrix *) malloc (sizeof(Matrix));
    matrix->info = CopyMatrixInfo(info);
    matrix->data = (void **) calloc (info->lines, sizeof (void *));
    for (size_t i = 0; i < info->lines; i++)
    {
        matrix->data[i] = (void *) calloc(info->columns, info->typeInfo->elemSize);
        for (size_t j = 0; j < info->columns; j++)
        {
            void *dest_pointer = matrix->data[i];
            void *temp_pointer = data[i];
            memcpy ((int8_t *)dest_pointer + j * info->typeInfo->elemSize, (int8_t *)temp_pointer + j * info->typeInfo->elemSize, info->typeInfo->elemSize);
        }
    }
    return matrix;
}

Matrix *CopyMatrix (Matrix *oldMatrix)
{
    Matrix *newMatrix = CreateFromValues(oldMatrix->info, oldMatrix->data);
    return newMatrix;
}

void *getElem (Matrix *matrix, size_t i, size_t j)
{
    void *temp = matrix->data[i];
    return ((void *)((int8_t *)temp + j * matrix->info->typeInfo->elemSize));
}

void setElem (Matrix *matrix, void *value, size_t i, size_t j)
{
    void *temp = matrix->data[i];
    memcpy ((int8_t *)temp + j * (matrix->info->typeInfo->elemSize), value, (matrix->info->typeInfo->elemSize));
}

Matrix *sumMatrix (Matrix *m1, Matrix *m2, int *errorCode)
{
    *errorCode = 111;
    if ((CompareMatrix(m1->info, m2->info) == 2) || ((CompareMatrix(m1->info, m2->info) == 0)))
    {
        if (CompareMatrix(m1->info, m2->info) == 2)
            *errorCode = 1; // Расхождение размернстей.
        else
            *errorCode = 0; // Типы не совпадают.
        return NULL;
    }
    else
    {
        Matrix *matrix = (Matrix *) malloc (sizeof(Matrix));
        matrix->info = CopyMatrixInfo(m1->info);
        matrix->data = (void **) calloc (m1->info->lines, sizeof (void *));
        for (size_t i = 0; i < m1->info->lines; i++)
        {
            matrix->data[i] = (void *) calloc (m1->info->typeInfo->elemSize, m1->info->columns);
            for (size_t j = 0; j < m1->info->columns; j++)
            {
                void *s1 = getElem(m1, i, j);
                void *s2 = getElem(m2, i, j);
                setElem(matrix, matrix->info->typeInfo->sum(s1, s2), i, j);
            }
        }
        return matrix;
    }
}

Matrix *scalarMult (Matrix *matrix, void *value)
{
    Matrix *newMatrix = (Matrix *) malloc (sizeof(Matrix));
    newMatrix->info = CopyMatrixInfo(matrix->info);
    newMatrix->data = (void **) calloc (matrix->info->lines, sizeof (void *));
    for (size_t i = 0; i < matrix->info->lines; i++)
    {
        newMatrix->data[i] = (void *) calloc (matrix->info->columns, matrix->info->typeInfo->elemSize);
        for (size_t j = 0; j < matrix->info->columns; j++)
            setElem(newMatrix, newMatrix->info->typeInfo->mult(getElem(matrix, i, j), value), i, j);
    }
    return newMatrix;
}

Matrix *matrixMult (Matrix *m1, Matrix *m2, int *errorCode)
{
    *errorCode = 111;
    if ((CompareMatrix(m1->info, m2->info) == 0) || ((CompareMatrix(m1->info, m2->info) == 1)) || (CompareMatrix(m1->info, m2->info) == 4))
    {
        if (CompareMatrix(m1->info, m2->info) == 0)
            *errorCode = 0; // Типы не совпадают.
        else
            *errorCode = 1; // Размерности расходятся.
        return NULL;
    }
    else
    {
        Matrix *rez = (Matrix *) malloc (sizeof(Matrix));
        rez->info = NewMatrixInfo(m1->info->typeInfo, m1->info->lines, m2->info->columns);
        rez->data = (void **) calloc (rez->info->lines, sizeof (void *));
        for (size_t i = 0; i < rez->info->lines; i++)
        {
            rez->data[i] = (void *) calloc (rez->info->columns, rez->info->typeInfo->elemSize);
            for (size_t j = 0; j < rez->info->columns; j++)
            {
                setElem(rez, rez->info->typeInfo->zero, i, j);
                for (size_t curIndex = 0; curIndex < m1->info->columns; curIndex++)
                    setElem (rez, rez->info->typeInfo->sum(getElem(rez, i, j), rez->info->typeInfo->mult(getElem(m1, i, curIndex), getElem(m2, curIndex, j))), i, j);
            }
        }
        return rez;
    }
}

Matrix *matrixTranspose (Matrix *matrix)
{
    Matrix *newMatrix = (Matrix *) malloc (sizeof(Matrix));
    newMatrix->info = NewMatrixInfo(matrix->info->typeInfo, matrix->info->columns, matrix->info->lines);
    newMatrix->data = (void **) calloc (newMatrix->info->lines, sizeof (void *));
    for (size_t i = 0; i < newMatrix->info->lines; i++)
    {
        newMatrix->data[i] = (void *) calloc (newMatrix->info->columns, newMatrix->info->typeInfo->elemSize);
        for (size_t j = 0; j < newMatrix->info->columns; j++)
            setElem(newMatrix, getElem(matrix, j, i), i, j);
    }
    return newMatrix;
}

void deleteMatrix (Matrix *matrix)
{
    deleteMatrixInfo(matrix->info);
    free (matrix);
}