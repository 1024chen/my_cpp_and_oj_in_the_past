#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define overflow -2
#define INIT_SIZE 500
#define INCREMENT_SIZE 10

typedef int ElemType;
typedef int bool;

/**
 * 存储结构
*/
typedef struct Stack
{
    ElemType *base; //栈尾指针
    ElemType *top;  //栈顶指针
    int size;       //栈大小
} SqStack;

bool InitStack(SqStack *S)
{
    S->base = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (!S->base)
    {
        exit(overflow);
    }
    S->top = S->base;
    S->size = INIT_SIZE;
    return true;
}

/**
 * 销毁栈
*/
bool DestoryStack(SqStack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->size = 0;
    return true;
}

/**
 * 清空栈
*/
bool ClearStack(SqStack *S)
{
    S->top = S->base;
    return true;
}

/**
 * 判断栈是否为空
*/
bool IsEmpty(SqStack S)
{
    if (S.top == S.base)
    {
        return true;
    }
    else
        return false;
}

/**
 * 获取栈长度
*/
int GetLength(SqStack S)
{
    return S.top - S.base;
}

/**
 * 获取栈元素
*/
bool GetTop(SqStack S, ElemType *e)
{
    if (S.top > S.base)
    {
        *e = *(--S.top);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * 压栈
*/
bool Push(SqStack *S, ElemType e)
{
    if ((S->top - S->base) / sizeof(ElemType) >= S->size)
    {
        S->base = (ElemType *)realloc(S->base, (S->size + INIT_SIZE) * sizeof(ElemType));
        if (!S->base)
        {
            exit(overflow);
        }
        S->top = S->base + S->size;
        S->size += INCREMENT_SIZE;
    }
    *S->top = e;
    S->top++;
    return true;
}

/**
 * 出栈
*/
bool Pop(SqStack *S, ElemType *e)
{
    if (S->top == S->base)
    {
        return false;
    }
    S->top--;
    *e = *S->top;
    return true;
}

/**
 * 访问元素
*/
void visit(ElemType e)
{
    printf("%d ", e);
}

bool TraverseStack(SqStack S, void (*visit)(ElemType))
{
    while (S.top > S.base)
    {
        visit(*S.base);
        S.base++;
    }
    printf("\n");
    return true;
}

// int main()
// {
//     char opterSerial[1001];
//     while (scanf("%s", &opterSerial) != EOF)
//     {
//         SqStack S;
//         InitStack(&S);
//         int iter = 0;
//         ElemType PushNum = 1;
//         ElemType PopNum = -1;
//         bool status = true;
//         while (opterSerial[iter]!='\0')
//         {
//             if (opterSerial[iter]== 'P')
//             {
//                 status = Push(&S,PushNum);
//                 PushNum++;
//             }else if (opterSerial[iter]=='Q')
//             {
//                 status = Pop(&S,&PopNum);
//                 if (status == false)
//                 {
//                     printf("false");
//                     break;
//                 }
//                 visit(PopNum);
//             }
//             iter++;
//         }
//         // if (PopNum == -1)
//         // {
//         //     printf("\n");
//         // }
//         printf("\n");
//         DestoryStack(&S);
//     }
// }

int main()
{
    SqStack S;
    ElemType x;
    int i;

    InitStack(&S);
    for ( i = 0; i < 10; i++)
    {
        Push(&S,i);
    }
    TraverseStack(S,visit);
    Pop(&S,&x);
    printf("Now this element (%d) has been popped up\n",x);
    TraverseStack(S,visit);
    DestoryStack(&S);
    return 0;
}