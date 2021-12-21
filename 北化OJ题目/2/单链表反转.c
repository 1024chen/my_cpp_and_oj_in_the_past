#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MaxSize 200

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!L)
    {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
}

void DestroyList(LinkList *L)
{
    LinkList temp;
    while (*L)
    {
        temp = (*L)->next;
        free(*L);
        *L = temp;
    }
}

int GetLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

ElemType GetElem(LinkList L, int i)
{
    ElemType e;
    int j = 1;
    LinkList p = L->next;
    while (p && j < i)
    {
        j++;
        p = p->next;
    }
    e = p->data;
    return e;
}

Status InsertElem(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList s, p = L;
    while (p && j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

void visit(ElemType e)
{
    printf("%d ", e);
}

void TraverList(LinkList L, void (*visit)(ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
}

void DestoryList(LinkList *L)
{
    LinkList temp;
    while (*L)
    {
        temp = (*L)->next;
        free(*L);
        *L = temp;
    }
}

int main()
{
    LinkList L, M;

    ElemType e;

    int num, elem;
    while (scanf("%d", &num) != EOF && num >= 0)
    {
        InitList(&L);
        InitList(&M);
        if (num == 0)
        {
            printf("list is empty");
        }
        else
        {
            for (int i = 0; i < num; i++)
            {
                scanf("%d", &elem);
                InsertElem(L, i + 1, elem);
            }
            for (int i = 0; i < num; i++)
            {
                InsertElem(M, i + 1, GetElem(L, num - i));
            }

            for (int i = 1; i <= num; i++)
            {
                visit(GetElem(L, i));
            }
            printf("\n");
            for (int i = 1; i < num; i++)
            {
                visit(GetElem(M, i));
            }
            printf("%d",GetElem(M,num));
            printf("\n");
        }
        DestoryList(&L);
        DestoryList(&M);
    }

    return 0;
}
