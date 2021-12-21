#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5

typedef char SElemType;
typedef int Status;

/*
 * 存储结构
 */
typedef struct
{
    SElemType *base; //栈尾指针
    SElemType *top;  //栈顶指针
    int size;        //栈的大小
} SqStack;

/*
 * 初始化栈
 */
Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType));
    if (!S->base)
    {
        exit(OVERFLOW);
    }
    S->top = S->base;
    S->size = INIT_SIZE;
    return OK;
}

/*
 * 销毁栈
 */
Status DestroyStack(SqStack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->size = 0;
    return OK;
}

/*
 * 清空栈
 */
Status ClearStack(SqStack *S)
{
    S->top = S->base;
    return OK;
}

/*
 * 判断栈是否为空
 */
Status IsEmpty(SqStack S)
{
    if (S.top == S.base)
    {
        return TRUE;
    }
    else
        return FALSE;
}

/*
 * 获取栈的长度
 */
int GetLength(SqStack S)
{
    return S.top - S.base;
}

/*
 * 获取栈顶元素
 */
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top > S.base)
    {
        *e = *(--S.top);
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*
 * 压栈
 */
Status Push(SqStack *S, SElemType e)
{
    if ((S->top - S->base) / sizeof(SElemType) >= S->size)
    {
        S->base = (SElemType *)realloc(S->base, (S->size + INCREMENT_SIZE) * sizeof(SElemType));
        if (!S->base)
        {
            exit(OVERFLOW);
        }
        S->top = S->base + S->size;
        S->size += INCREMENT_SIZE;
    }
    *S->top = e;
    S->top++;
    return OK;
}

/*
 * 退栈
 */
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == S->base)
    {
        return ERROR;
    }
    S->top--;
    *e = *S->top;
    return OK;
}

/*
 * 访问元素
 */
void visit(SElemType e)
{
    printf("%c", e);
}

/*
 * 遍历栈
 */
Status TraverseStack(SqStack S, void (*visit)(SElemType))
{
    while (S.top > S.base)
    {
        visit(*S.base);
        S.base++;
    }
    return OK;
}

int main()
{
    char str[200];
    while (gets(str) != NULL && str[0] != '\0')
    {
        SqStack S;
        InitStack(&S);
        int i = 0;
        SElemType* temp;
        while (str[i] != '\0')
        {
            switch (str[i])
            {
            case '#':
                Pop(&S,&str[i]);
                break;
            case '@':
                ClearStack(&S);
                break;
            default:
                Push(&S,str[i]);
                break;
            }
            i++;
        }
        TraverseStack(S,visit);
        ClearStack(&S);
        printf("\n");
        DestroyStack(&S);
    }
}