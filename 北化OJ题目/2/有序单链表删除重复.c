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

//初始化表
void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!L)
    {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
}

//销毁链表
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

//访问
void visit(ElemType e)
{
    printf("%d ", e);
}

//遍历1
void TraverList(LinkList L, void (*visit)(ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
}

//遍历2，针对输出格式
void TraverList_1(LinkList L, void (*visit)(ElemType))
{
    LinkList p = L->next;
    while (p->next)
    {
        visit(p->data);
        p = p->next;
    }
    printf("%d",p->data);
}

ElemType FindMax(LinkList L)
{
    LinkList p = L->next;
    int max = p->data;
    while (p)
    {
        if (max < p->data)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

//删除重复元素
void DeleteRepeat(LinkList h, int max)
{
    LinkList p = h, r;
    int *q, m;
    q = (int *)malloc(sizeof(int) * (max + 1)); //此处申请n+1个位置的辅助空间
    for (int i = 0; i < max + 1; i++)           //辅助数组置0
    {
        *(q + i) = 0;
    }
    while (p->next != NULL)
    {
        m = p->next->data;
        if (*(q + m) == 0) //首次出现
        {
            *(q + m) = 1;
            p = p->next;
        }
        else //重复出现释放
        {
            r = p->next;
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}

int main()
{
    LinkList L;
    int i, elem,max;
    while (scanf("%d", &i) != EOF && i >= 0)
    {
        InitList(&L);
        if (i == 0)
        {
            printf("list is empty");
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                scanf("%d", &elem);
                InsertElem(L, j + 1, elem);
            }

            //输出
            TraverList(L, visit);
            printf("\n");
            max = FindMax(L)+1;
            DeleteRepeat(L,max);

            TraverList_1(L, visit);
            printf("\n");
        }

        DestroyList(&L);
    }

    return 0;
}
