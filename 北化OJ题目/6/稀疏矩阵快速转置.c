#include <stdio.h>
#include <stdlib.h>

#define MaxSize 12500
#define zero 0
typedef int ElemType;

typedef struct term
{
    int col, row; //所在列，所在行
    ElemType value;
} Term;
typedef struct sparseMatrix
{
    int m, n, t;         //行数，列数。非零元素个数
    Term table[MaxSize]; //三元组表
} SparseMatrix;

void inPutSMatrix(SparseMatrix *sMatrix, int row, int col)
{
    int value;
    sMatrix->m = row;
    sMatrix->n = col;
    sMatrix->t = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &value);
            if (value != 0)
            {
                sMatrix->table[sMatrix->t].row = i;
                sMatrix->table[sMatrix->t].col = j;
                sMatrix->table[sMatrix->t].value = value;
                //printf("this value:%d\n", sMatrix->table[sMatrix->t].value);
                ++(sMatrix->t);
            }
        }
    }
}

ElemType matchValue(SparseMatrix *sMatrix, int i, int j)
{
    for (int k = 0; k < sMatrix->t; k++)
    {
        if (i == sMatrix->table[k].row && j == sMatrix->table[k].col)
        {
            return sMatrix->table[k].value;
        }
    }
    return zero;
}

void outPutSMatrix(SparseMatrix *sMatrix)
{
    for (int i = 0; i < sMatrix->m; i++)
    {
        for (int j = 0; j < sMatrix->n; j++)
        {
            printf("%d ", matchValue(sMatrix, i, j));
        }
        printf("\n");
    }
}

//普通转置
void TransposeSMatrix(SparseMatrix M, SparseMatrix *T)
{
    int p, q, col;
    T->m = M.n;
    T->n = M.m;
    T->t = M.t;
    if (T->t)
    {
        // q = 1;
        // for (col = 0; col < M.n; col++)
        // {
        //     for (p = 0; p < M.t; p++)
        //     {
        //         if (M.table[p].col == col)
        //         {
        //             T->table[q].row = M.table[p].col;
        //             T->table[q].col = M.table[p].row;
        //             T->table[q].value = M.table[p].value;
        //             ++q;
        //         }
        //     }
        // }
        for (int i = 0; i < T->t; i++)
        {
            T->table[i].row = M.table[i].col;
            T->table[i].col = M.table[i].row;
            T->table[i].value = M.table[i].value;
        }
    }
}

//快速转置
void FastTransposeSMatrix(SparseMatrix M, SparseMatrix *T)
{
    int num[MaxSize], k[MaxSize];
    T->m = M.n;
    T->n = M.m;
    T->t = M.t;
    if (T->t)
    {
        for (int j = 0; j < M.n; j++)
        {
            num[j] = 0;
        }
        for (int i = 0; i < M.t; i++)
        {
            num[M.table[i].col]++;
        }
        for (int j = 0; j < M.n; j++)
        {
            k[j] = 0;
        }
        for (int j = 1; j < M.n; j++)
        {
            k[j] = k[j - 1] + num[j - 1];
        }
        for (int i = 0; i < M.t; i++)
        {
            int index = k[M.table[i].col]++;
            T->table[index].col = M.table[i].row;
            T->table[index].row = M.table[i].col;
            T->table[index].value = M.table[i].value;
        }
        }
}

int main()
{
    int row, col;
    SparseMatrix sMatrix1, sMatrix2;
    scanf("%d", &row);
    scanf("%d", &col);
    inPutSMatrix(&sMatrix1, row, col);
    FastTransposeSMatrix(sMatrix1, &sMatrix2);
    outPutSMatrix(&sMatrix2);
}