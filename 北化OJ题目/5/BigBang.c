#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 100
#define INCREMENT 10

typedef int Status;
typedef char *Elemtype;

typedef struct
{
    Elemtype *elem;
    int length;
    int size;
} SqList;

//初始化
Status InitList(SqList *L)
{
    L->elem = (Elemtype *)malloc(INIT_SIZE * sizeof(Elemtype));
    if (!L->elem)
    {
        return ERROR;
    }

    //指针置空
    // for (int i = 0; i < ; i++)
    // {
    //     /* code */
    // }
    
    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}

//销毁
Status DestroyList(SqList *L)
{
    free(L->elem);
    L->length = 0;
    L->size = 0;
    return OK;
}

//根据位置获取元素（第几位）
Status GetElem(const SqList L, int i, Elemtype *e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.elem[i - 1];
    return OK;
}

//比较两个元素，看起来像废话，其实就是冗余代码，嘿嘿
Status compare(Elemtype e1, Elemtype e2)
{
    return strcmp(e1, e2); //相等则返回0,前者大返回1，后者大返回负
}

//查找元素,查找位于第几位
Status FindElem(const SqList L, Elemtype e, Status (*compare)(Elemtype, Elemtype))
{
    int i = 0;
    for (i = 0; i < L.length; i++)
    {
        if (!(*compare)(L.elem[i], e))
        {
            return i + 1;
        }
    }
    if (i >= L.length)
    {
        return ERROR;
    }
}
Status Insert(SqList *L)
{
    int status = 1;
    int a = -1;
    Elemtype name;
    Elemtype *new;
    name = (char *)malloc(sizeof(char) * (30 + 1));

    scanf("%d", &a);
    scanf("%s", name);

    if (a < 1 || a > L->length + 1)
    {
        return ERROR;
    }

    //表长到了最大长度
    if (L->length >= L->size)
    {
        new = (Elemtype *)realloc(L->elem, (L->size + INCREMENT) * sizeof(Elemtype));
        if (!new)
        {
            return ERROR;
        }
        L->elem = new;
        L->size += INCREMENT;
    }
    // L->elem[a - 1] = name;
    // printf("a-1: %s", L->elem[a - 1]);

    if (!FindElem(*L, name, *compare)) //没找到或空表,插入
    {
        if (L->elem[a-1] ==NULL)
        {
            free(L->elem[a-1]);
        }
        L->elem[a - 1] = name;
        ++L->length;
        //printf("a-1: %s", L->elem[a - 1]);
    }
    else
    {
        //找到了，哦，那没事了
    }
    //free(name);
    return status;
}

void visit(Elemtype e)
{
    printf("%s ", e);
}

Status TraverseList(const SqList L, void (*visit)(Elemtype))
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        visit(L.elem[i]);
    }
    return OK;
}

Status Instruct(char *instruct, SqList *L)
{
    int a = -1, status = 1;
    char *name;
    if (!strcmp("insert", instruct))
    {
        //printf("%s",instruct);
        status = Insert(L);
        TraverseList(*L, visit);
    }
    else if (!strcmp("delete", instruct))
    {
    }
    else if (!strcmp("show", instruct))
    {
    }
    else if (!strcmp("search", instruct))
    {
    }
    else
    {
        status = ERROR;
    }

    return status;
}

int main()
{
    SqList L;
    char instruct[6];
    int status = 1;
    InitList(&L);
    while (scanf("%s", instruct) != EOF && status == 1)
    {
        status = Instruct(instruct, &L);
    }

    DestroyList(&L);
    // L.elem[0] = "anna";
    // printf("%s",L.elem[0]);
}
