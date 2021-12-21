#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MaxSize 200

typedef int ElemType;
typedef int status;

typedef struct
{
    int n;
    int MaxLength;
    ElemType *element;
} SeqList;

status Init(SeqList *L, int mSize)
{
    L->MaxLength = mSize;
    L->n = 0;
    L->element = (ElemType *)malloc(sizeof(ElemType) * mSize);
    if (!L->element)
    {
        return ERROR;
    }
    return OK;
}

status AddElem(SeqList *L, int e)
{
    L->element[L->n] = e;
    L->n++;
    return OK;
}

//表打印
status OutPut(SeqList *L)
{
    printf("%d", L->element[0]);
    for (int i = 1; i < L->n; i++)
    {
        printf(" %d", L->element[i]);
    }
    return OK;
}

//联合操作
status ElemPut(SeqList *A, SeqList *B, SeqList *C)
{
    int i = 0, j = 0, k = 0;
    while (i < A->n && j < B->n)
    {
        if (A->element[i] < B->element[j])
        {
            AddElem(C, A->element[i]);
            i++;
            k++;
        }
        else
        {
            AddElem(C, B->element[j]);
            j++;
            k++;
        }
    }
    while (i < A->n)
    {
        AddElem(C, A->element[i]);
        i++;
        k++;
    }
    while (j < B->n)
    {
        AddElem(C, B->element[j]);
        j++;
        k++;
    }

    OutPut(C);
    return OK;
}

//清空表
status Destory(SeqList *L)
{
    L->n = 0;
    L->MaxLength = 0;
    free(L->element);
    return OK;
}

int main()
{
    SeqList A, B, C;
    int lineA, lineB, elem;
    while (scanf("%d", &lineA) != EOF)
    {
        Init(&A, MaxSize);
        Init(&B, MaxSize);
        Init(&C, 2 * MaxSize);
        for (int i = 0; i < lineA; i++)
        {
            scanf("%d", &elem);
            AddElem(&A, elem);
        }

        scanf("%d", &lineB);
        for (int i = 0; i < lineB; i++)
        {
            scanf("%d", &elem);
            AddElem(&B, elem);
        }
        ElemPut(&A, &B, &C);
        Destory(&A);
        Destory(&B);
    }

    return 0;
}