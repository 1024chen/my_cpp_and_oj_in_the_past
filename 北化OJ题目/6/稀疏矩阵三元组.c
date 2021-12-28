#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define false 0
typedef int ElemType;

typedef struct term
{
    int col, row; //所在行，所在列
    ElemType value;
} Term;
typedef struct sparseMatrix
{
    int m, n, t;         //行数，列数。非零元素个数
    Term table[MaxSize]; //三元组表
} SparseMatrix;

// void lenConversion(char a[], char b[], int len)
// {
//     int i;
//     for (i = 2; a[i] != '\0' && i < len; i++)
//     {
//         b[i - 2] = a[i];
//     }
//     b[i - 2] = '\0';
// }

void constructSMatrix(SparseMatrix *sMatrix, int m, int n, int t)
{
    sMatrix->m = m;
    sMatrix->n = n;
    sMatrix->t = t;
    for (int i = 0; i < sMatrix->t; i++)
    {
        scanf("%d %d %d", &(sMatrix->table[i].col), &(sMatrix->table[i].row), &(sMatrix->table[i].value));
    }
}

void clearSMatrix(SparseMatrix *sMatrix)
{
    for (int i = 0; i < sMatrix->t; i++)
    {
        sMatrix->table[i].col = -1;
        sMatrix->table[i].row = -1;
        sMatrix->table[i].value = 0;
    }
    sMatrix->m = 0;
    sMatrix->n = 0;
    sMatrix->t = 0;
}

ElemType matchValue(SparseMatrix *sMatrix, int i, int j)
{
    for (int k = 0; k < sMatrix->t; k++)
    {
        if (i == sMatrix->table[k].col && j == sMatrix->table[k].row)
        {
            return sMatrix->table[k].value;
        }
    }
    return false;
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

void numMatch(char a[], char b[])
{
    int i = 0, j = 0;
    while (a[i]!='\0')
    {
        if (a[i]>='0'&&a[i]<='9')
        {
            b[j] = a[i];
            j++;
        }
        i++;
    }
    b[j] = '\0';
}

int main()
{
    int col, row, value;
    int m, n, t;
    char s1[6], s2[6], sa[8];
    char s3[4], s4[4], sb[6];

    SparseMatrix sMatrix;

    gets(s1);
    numMatch(s1, s3);
    m = atoi(s3);
    gets(s2);
    numMatch(s2, s4);
    n = atoi(s4);
    gets(sa);
    numMatch(sa, sb);
    t = atoi(sb);
    //printf("%d %d %d", m, n, t);

    constructSMatrix(&sMatrix, m, n, t);
    outPutSMatrix(&sMatrix);
    clearSMatrix(&sMatrix);
    return 0;
}