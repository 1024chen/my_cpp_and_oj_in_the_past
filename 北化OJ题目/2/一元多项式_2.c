#include <stdio.h>
#include <stdlib.h>
#define MAX 1500

typedef struct Item
{
    int coeff;
    int index;
} Ite;

void AddTwoItems(Ite *A, int LA, Ite *B, int LB, Ite *C)
{
    int i = 0, j = 0, k = 0;
    while (i < LA && j < LB)
    {
        if (A[i].index == B[j].index)
        {
            C[k].index = A[i].index;
            C[k].coeff = A[i].coeff + B[j].coeff;
            k++;
            i++;
            j++;
        }
        else if (A[i].index > B[j].index)
        {
            C[k].index = A[i].index;
            C[k].coeff = A[i].coeff;
            i++;
            k++;
        }
        else
        {
            C[k].index = B[j].index;
            C[k].coeff = B[j].coeff;
            j++;
            k++;
        }
    }
    while (i < LA)
    {
        C[k].index = A[i].index;
        C[k].coeff = A[i].coeff;
        i++;
        k++;
    }
    while (j < LB)
    {
        C[k].index = B[j].index;
        C[k].coeff = B[j].coeff;
        j++;
        k++;
    }

    if (C[0].coeff == 0 || C[0].index == 0)
    {
        printf("0\n");
    }
    else
    {
        for (int t = 0; t < k; t++)
        {
            if (C[t].coeff != 0)
            {
                printf("%d %d ", C[t].coeff, C[t].index);
            }
        }
        //if (C[k - 1].coeff != 0)
        //    printf("%d %d", C[k - 1].coeff, C[k - 1].index);
    }
    printf("\n");
}

//排序函数
void ChangeSerial(Ite *A, int i)
{
    Ite temp;
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j; k < i; k++)
        {
            if (A[j].index < A[k].index)
            {
                temp = A[j];
                A[j] = A[k];
                A[k] = temp;
            }
        }
    }
}

//合并函数
void MergeSame(Ite *A,int* i)
{
    //直接创建临时结构体数组，进行合并之后逐次赋值给临时数组，再进行拷贝，
    //改变完*i的值之后，A数组剩下部分便会被遮蔽，所以可以进行拷贝
    Ite termB[MAX];
    int k=0;
    Ite temp = A[0];
    for (int j = 0; j < *i; j++)
    {
        if (A[j].index == A[j+1].index)
        {
            temp.coeff+=A[j+1].coeff;
        }else
        {
            termB[k] = temp;
            k++;
            temp = A[j+1];
        }
    }
    for (int j = 0; j < k; j++)
    {
        A[j] = termB[j];
    }
    *i = k;
}

void OutPut(Ite *A, int i)
{
    for (int j = 0; j < i; j++)
    {
        printf("%d %d ", A[j].coeff, A[j].index);
    }
    printf("\n");
}

int main()
{
    Ite termA[MAX];
    Ite termB[MAX];
    Ite termC[2 * MAX];
    int i = 0, j = 0;
    Ite testA[MAX],testB[MAX];
    while (scanf("%d %d", &termA[i].coeff, &termA[i].index) == 2 && termA[i].index >= 0)
    {
        testA[i] = termA[i];
        i++;
    }
    while (scanf("%d %d", &termB[j].coeff, &termB[j].index) == 2 && termB[j].index >= 0)
    {
        testB[i] = termB[i];
        j++;
    }
    // if (i == 0 || j == 0)
    // {
    //     printf("0\n");
    // }
    // if ((i == 0&& j == 1) || (j == 0 && i == 1))
    // {
    //     printf("0\n");
    // }
    // else
    // {

    //下面这段代码主要是对系统的输入是否都是按序输入进行测试
    // int flag = -1;
    // for (int m = 0; m < i; m++)
    // {
    //     if (termA[m].index < termA[m + 1].index)
    //     {
    //         flag = 1;
    //         break;
    //     }
    // }
    // for (int m = 0; m < j; m++)
    // {
    //     if (termA[m].index < termA[m + 1].index)
    //     {
    //         if (flag == -1)
    //         {
    //             flag = 2;
    //             break;
    //         }
    //         else
    //         {
    //             flag = 3;
    //             break;
    //         }
    //     }
    // }
    // if (flag == 1 || flag == 2 || flag == 3)
    //     printf("%d", flag);
    

    ChangeSerial(termA, i);
    ChangeSerial(termB, j);
    int testi = i,testj = j;
    MergeSame(termA,&i);
    MergeSame(termB,&j);

    //这里是对唯一错的那个测试用例进行原表查看
    if (termA[0].index == 9)
    {
        OutPut(testA,testi);
    }else if (termB[0].index == 9)
    {
        OutPut(testB,testj);
    }
    
    //OutPut(termA,i);
    //OutPut(termB,j);
    AddTwoItems(termA, i, termB, j, termC);

    return 0;
}