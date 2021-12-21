#include <stdio.h>

//数据结构配置
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
    if (S->top < 0) //栈空，报错
    {
        return false;
    }
    *x = S->data[S->top--]; //先出栈，指针再减一
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

// int main()
// {
//     int length;
//     ElemType num[MaxSize];
//     while (scanf("%d", &length) != EOF)
//     {
//         SqStack S;
//         InitStack(&S);
//         int i;
//         int iter;
//         iter = 1;
//         Push(&S,0);

//         for (i = 0; i < length; i++)
//         {
//             scanf("%d", &num[i]);
//         }
//         for (i = 0; i < length; i++)
//         {
//             int temp = num[i];
//             S.top++;
//             while (S.data[S.top - 1] < temp)
//             {
//                 S.data[S.top] = iter;
//                 iter++;
//                 S.top++;
//                 printf("P");
//             }
//             S.top--;
//             if (S.data[S.top] == temp)
//             {
//                 printf("Q");
//                 S.top--;
//             }
//             else if (S.data[S.top] > temp)
//             {
//                 printf(" error");
//                 break;
//             }
//         }
//         printf("\n");
//     }
// }

int main()
{
    int length;
    ElemType num[MaxSize];
    while (scanf("%d", &length) != EOF)
    {
        SqStack S;
        int i;
        int iter;

        iter = 1;
        InitStack(&S);
        Push(&S, 0);

        for (i = 0; i < length; i++)
        {
            scanf("%d", &num[i]);
        }
        for (i = 0; i < length; i++)
        {
            int temp = num[i];
            S.top++;//这里++的原因是因为需要步进一次防止数组非法访问
            while (S.data[S.top - 1] < temp)
            {
                S.data[S.top] = iter;//这里不调用Push是因为上面的top++，并且要对数组进行连续赋值
                iter++;
                S.top++;
                printf("P");
            }
            S.top--;//这里针对上面的++进行了恢复
            if (S.data[S.top] == temp)
            {
                printf("Q");
                S.top--;//不用出栈，指针步减就行
            }
            else if (S.data[S.top] > temp)
            {
                printf(" error");
                break;
            }
        }
        printf("\n");
    }
}