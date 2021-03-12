//
// Created by Timur on 20.02.2021.
//

#include "comp_matrix.h"

void *csum (void *a, void *b)
{
    complex *c = (complex *)a;
    complex *d = (complex *)b;
    complex *rez = malloc (sizeof(complex));
    *rez = complex_sum(*c, *d);
    return (void *)rez;
}

void *cmult (void *a, void *b)
{
    complex *c = (complex *)a;
    complex *d = (complex *)b;
    complex *rez = malloc (sizeof(complex));
    *rez = complex_mult(*c, *d);
    return (void *)rez;
}

Matrix *newCMatrix (size_t lines, size_t columns)
{
    if (!compInfo)
    {
        czero = malloc (sizeof(complex));
        *((complex *)(czero)) = make_complex(0, 0);
        cone = malloc (sizeof(complex));
        *((complex *)(cone)) = make_complex(1, 0);
        compInfo = CreateTypeInfo(sizeof(complex), czero, cone, csum, cmult);
    }
    TypeInfo *tmp = CopyTypeInfo(compInfo);
    MatrixInfo *newMatrixInfo = NewMatrixInfo(tmp, lines, columns);
    complex **data = (complex **) calloc (lines, sizeof (complex *));
    for (size_t i = 0; i < lines; i++)
    {
        data[i] = (complex *) calloc (columns, sizeof (complex));
        for (size_t j = 0; j < columns; j++)
        {
            float real, imagine;
            scanf ("%f %f", &real, &imagine);
            *(data[i] + j) = make_complex(real, imagine);
        }
    }
    Matrix *matrix = CreateFromValues(newMatrixInfo, (void **)data);
    for (size_t i = 0; i < lines; i++)
        free (data[i]);
    free (data);
    deleteMatrixInfo(newMatrixInfo);
    return matrix;
}

Matrix *multCMatrix (int lin1, int col1, int lin2, int col2, int *errorCode)
{
    Matrix *first = newCMatrix(lin1, col1);
    puts ("Enter second matrix :");
    Matrix *second = newCMatrix(lin2, col2);
    Matrix *rez = matrixMult(first, second, errorCode);
    deleteMatrix(first);
    deleteMatrix(second);
    return rez;
}

Matrix *sumCMatrix (int lin1, int col1, int lin2, int col2, int *errorCode)
{
    Matrix *first = newCMatrix(lin1, col1);
    puts ("Enter second matrix :");
    Matrix *second = newCMatrix(lin2, col2);
    Matrix *rez = sumMatrix(first, second, errorCode);
    deleteMatrix(first);
    deleteMatrix(second);
    return rez;
}

void printCMatrix (Matrix *matrix)
{
    complex **data = (complex **)matrix->data;
    for (size_t i = 0; i < matrix->info->lines; i++)
    {
        complex *tmp = (complex *)(data[i]);
        for (size_t j = 0; j < matrix->info->columns; j++)
            print_complex(tmp[j]);
        printf ("\n");
    }
    printf ("\n");
}