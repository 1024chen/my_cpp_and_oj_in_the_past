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
    if (S.top == -1)
    {
        return false;
    }
    *x = S.data[S.top];
    return true;
}

int main()
{
    char str[101];
    ElemType x;
    while (gets(str) != NULL && str[0] != '\0')
    {
        SqStack S;
        InitStack(&S);
        int i = 0;

        bool status = true;

        while (str[i] != '\0')
        {
            if (status == false)
            {
                break;
            }
            if (str[i] == '(')
            {
                Push(&S, str[i]);
            }
            else if (str[i] == ')')
            {
                status = Pop(&S, &x);
            }
            i++;
        }
        if (status == true)
        {
            status = !GetTop(S, &x);
        }
        if (status == true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}