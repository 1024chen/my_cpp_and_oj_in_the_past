#ifndef seqStack_FILE
#define seqStack_FILE

#include <stdio.h>

typedef int ElemType;
typedef int Status;

#define TRUE 1
#define FALSE 0
#define MaxSize 1000
typedef struct seqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack *S)
{
    S->top = -1;
}

//判空
Status IsEmpty(SqStack* S)
{
    return S->top == -1;
}

//进栈
Status Push(SqStack *S, ElemType x)
{
    if (S->top >= MaxSize - 1) //栈满
    {
        return FALSE;
    }
    S->data[++S->top] = x;
    return TRUE;
}

//出栈
Status Pop(SqStack *S, ElemType *x)
{
    if (S->top < 0) //栈空
    {
        return FALSE;
    }
    *x = S->data[S->top--];
    return TRUE;
}

//获取栈顶元素
Status GetTop(SqStack S, ElemType *x)
{
    if (S.top = -1)
    {
        return FALSE;
    }
    *x = S.data[S.top];
    return TRUE;
}

//遍历栈
Status TraversalStack(SqStack S)
{
    for (int i = 0; i <= S.top; i++)
    {
        printf("%d ", S.data[i]);
    }
    printf("\n");
    return TRUE;
}

#endif