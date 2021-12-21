#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef int bool;

#define true 1
#define false 0
#define MaxSize 1000
typedef struct seqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *S)
{
    S->top = -1;
}

bool IsEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack *S, ElemType x)
{
    if (S->top >= MaxSize - 1)
    {
        return false;
    }
    S->data[++S->top] = x;
    return true;
}

bool Pop(SqStack *S, ElemType *x)
{
    if (S->top < 0)
    {
        return false;
    }
    *x = S->data[S->top--];
    return true;
}

bool GetTop(SqStack S, ElemType *x)
{
    if (S.top = -1)
    {
        return false;
    }
    *x = S.data[S.top];
    return true;
}

//进制转换函数
void conversion(int Num)
{
    ElemType e;
    SqStack S;
    InitStack(&S);
    while (Num)
    {
        Push(&S, Num % 8);
        Num /= 8;
    }
    while (!IsEmpty(S))
    {
        Pop(&S,&e);
        printf("%d",e);
    }
    printf("\n");
}

int main()
{
    int Num;
    while (scanf("%d",&Num)!=EOF)
    {
        conversion(Num);
    }
    
    return 0;
}