//
// Created by Timur on 20.02.2021.
//

#include "int_matrix.h"

void *sum (void *a, void *b)
{
    int *c = (int *)a;
    int *d = (int *)b;
    int *rez = malloc (sizeof(int));
    *rez = *c + *d;
    return (void *)rez;
}

void *mult (void *a, void *b)
{
    int *c = (int *)a;
    int *d = (int *)b;
    int *rez = malloc (sizeof(int));
    *rez = (*c) * (*d);
    return (void *)rez;
}

Matrix *newIntMatrixValue (size_t lines, size_t columns)
{
    if (!intInfo)
    {
        zero = malloc (sizeof(int));
        *((int *)(zero)) = 0;
        one = malloc (sizeof(int));
        *((int *)(one)) = 1;
        intInfo = CreateTypeInfo(sizeof(int), zero, one, sum, mult);
    }
    TypeInfo *tmp = CopyTypeInfo(intInfo);
    MatrixInfo *newMatrixInfo = NewMatrixInfo(tmp, lines, columns);
    int **data = (int **) calloc (lines, sizeof (int *));
    for (size_t i = 0; i < lines; i++)
    {
        data[i] = (int *) calloc (columns, sizeof (int));
        for (size_t j = 0; j < columns; j++)
            scanf ("%d", data[i] + j);
    }
    Matrix *matrix = CreateFromValues(newMatrixInfo, (void **)data);
    for (size_t i = 0; i < lines; i++)
        free (data[i]);
    free (data);
    deleteMatrixInfo(newMatrixInfo);
    return matrix;
}

Matrix *sumIntMatrix (int lin1, int col1, int lin2, int col2, int *errorCode)
{
    Matrix *first = newIntMatrixValue(lin1, col1);
    puts ("Enter second matrix :");
    Matrix *second = newIntMatrixValue(lin2, col2);
    Matrix *rez = sumMatrix(first, second, errorCode);
    deleteMatrix(first);
    deleteMatrix(second);
    return rez;
}

Matrix *multIntMatrix (int lin1, int col1, int lin2, int col2, int *errorCode)
{
    Matrix *first = newIntMatrixValue(lin1, col1);
    puts ("Enter second matrix :");
    Matrix *second = newIntMatrixValue(lin2, col2);
    Matrix *rez = matrixMult(first, second, errorCode);
    deleteMatrix(first);
    deleteMatrix(second);
    return rez;
}

void printIntMatrix (Matrix *matrix)
{
    int **data = (int **)matrix->data;
    for (size_t i = 0; i < matrix->info->lines; i++)
    {
        int *temp = (int *)data[i];
        for (size_t j = 0; j < matrix->info->columns; j++)
            printf ("%d  ", temp[j]);
        printf ("\n");
    }
}