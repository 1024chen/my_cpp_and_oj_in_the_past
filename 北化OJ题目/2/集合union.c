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
    printf("%d",L->element[0]);
    for (int i = 1; i < L->n; i++)
    {
        printf(" %d", L->element[i]);
    }
    printf("\n");
    return OK;
}

//联合操作
status ElemPut(SeqList *A, SeqList *B)
{
    OutPut(A);
    OutPut(B);

    //从B中取出元素插入到A尾部
    for (int i = 0; i < B->n; i++)
    {
        int flag = 1; //标记是否插入，1插入，0不插入
        for (int j = 0; j < A->n; j++)
        {
            if (B->element[i] == A->element[j])
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            AddElem(A, B->element[i]);
        }
        OutPut(A);
    }

    return OK;
}

//清空表
status Destory(SeqList* L){
    L->n = 0;
    L->MaxLength = 0;
    free(L->element);
    return OK;
}

int main()
{
    SeqList A, B;

    int lineA, lineB, elem;
    while (scanf("%d", &lineA) != EOF)
    {
        Init(&A, MaxSize);
        Init(&B, MaxSize);
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
        ElemPut(&A,&B);
        //每组空行隔开
        printf("\n");
        Destory(&A);
        Destory(&B);
    }

    return 0;
}