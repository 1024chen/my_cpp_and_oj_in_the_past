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

int main()
{
    SqStack S;
    int length;
    ElemType num[10001];
    while (scanf("%d", &length) != EOF)
    {
        int i;
        int iter = 1;
        ElemType x;

        InitStack(&S);
        Push(&S, 0);

        for (i = 0; i < length; i++)
        {
            scanf("%d", &num[i]);
        }
        for (i = 0; i < length; i++)
        {
            GetTop(S, &x);
            while (x < num[i])
            {
                Push(&S, iter);
                iter++;
                GetTop(S, &x);
                printf("P");
            }
            if (x == num[i])
            {
                printf("Q");
                Pop(&S, &x);
            }
            else if (x > num[i])
            {
                printf(" error");
                break;
            }
        }
        printf("\n");
        DestoryStack(&S);
    }
    return 0;
}