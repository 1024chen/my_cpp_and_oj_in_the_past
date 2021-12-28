//该程序未完成
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

void multSMatrix(SparseMatrix a,SparseMatrix b,SparseMatrix* c)
{
    if (a.t == 0 || b.t == 0)
    {
        return;
    }
    c->m = a.m;
    c->n = b.n;
    c->t = 0;
    int multsum;
    for (int i = 0; i < a.t; i++)
    {
        multsum = 0;
        for (int j = 0; j < b.t; j++)
        {
            //未完成
        }
        
    }
    

}

int main()
{
    int row1, col1,row2,col2;
    SparseMatrix sMatrix1, sMatrix2,sMatrix3;
    scanf("%d", &row1);
    scanf("%d", &col1);
    inPutSMatrix(&sMatrix1, row1, col1);
    scanf("%d", &row2);
    scanf("%d", &col2);
    if (col1 == row2)
    {
        inPutSMatrix(&sMatrix2, row2, col2);
    }
    multSMatrix(sMatrix1, sMatrix2, &sMatrix3);
    outPutSMatrix(&sMatrix3);
}