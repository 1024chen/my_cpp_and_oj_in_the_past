#include <stdio.h>


typedef int ElemType;
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
    if (S->top < 0) //ջ�գ�����
    {
        return false;
    }
    *x = S->data[S->top--]; //�ȳ�ջ��ָ���ټ�һ
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

bool TraversalStack(SqStack S)
{
    for (int i = 0; i <= S.top; i++)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
    return true;
}

int main()
{
    SqStack S;
    char opterSerial[MaxSize + 1];
    int iter;
    int PushIter;
    int PopIter;
    char opterCode;
    bool status = true;
    ElemType x = -1;
    while (scanf("%s", &opterSerial) != EOF)
    {
        InitStack(&S);
        iter = 0;
        PushIter = 0;
        PopIter = 0;
        while (opterSerial[iter] != '\0')
        {
            opterCode = opterSerial[iter];
            iter++;
            if (opterCode == 'P')
            {
                ++PushIter;
                status = Push(&S, PushIter);
            }
            else if (opterCode == 'Q')
            {
                ++PopIter;
                status = Pop(&S, &x);
                if (status == false)
                {
                    printf("error");
                    break;
                }
                printf("%d ", x);
            }
        }
        
        if (PopIter == 0)
        {
            printf("\n");
        }
    }
    return 0;
}

// int main()
// {
//     SqStack S;
//     ElemType x;
//     int i;

//     InitStack(&S);
//     for ( i = 0; i < 10; i++)
//     {
//         Push(&S,i);
//     }
//     TraversalStack(S);
//     Pop(&S,&x);
//     printf("Now this element (%d) has been popped up\n",x);
//     TraversalStack(S);

//     return 0;
// }