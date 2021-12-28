#include <stdio.h>
#include <stdlib.h>

#define MaxSize 200
#define zero 0
typedef int ElemType;

int main()
{
    int row1, col1, row2, col2;
    ElemType matrix1[MaxSize][MaxSize], matrix2[MaxSize][MaxSize], matrix3[MaxSize][MaxSize];
    scanf("%d", &row1);
    scanf("%d", &col1);
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    scanf("%d", &row2);
    scanf("%d", &col2);
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (col1 == row2)
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                matrix3[i][j] = 0;
                for (int k = 0; k < col1; k++)
                {
                    matrix3[i][j] += (matrix1[i][k] * matrix2[k][j]);
                }
            }
        }
    
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}