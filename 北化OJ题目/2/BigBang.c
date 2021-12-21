#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10     //初始化表长
#define INCREMENT_SIZE 5 //分配增量

typedef int Status;
typedef char *Elemtype;

/*
 * 存储结构
 */
typedef struct
{
    Elemtype *elem; //存储空间基址
    int length;     //当前长度
    int size;       //当前分配的表长大小
} SqList;

/*
 * 初始化一个空的线性表
 */
Status InitList(SqList *L)
{
	int i;
    L->elem = (Elemtype *)malloc(INIT_SIZE * sizeof(Elemtype));
    for (i = 0; i < INIT_SIZE; i++)
    {
        L->elem[i] = (char *)malloc(sizeof(char) * (30 + 1));
    }

    if (!L->elem)
    {
        return ERROR;
    }
    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}

/*
 * 销毁线性表
 */
Status DestroyList(SqList *L)
{
	int i;
    for (i = 0; i < L->size; i++)
    {
        free(L->elem[i]);
    }
    free(L->elem);
    L->length = 0;
    L->size = 0;
    return OK;
}

/*
 * 清空线性表
 */
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

/*
 * 判断线性表是否为空
 */
Status isEmpty(const SqList L)
{
    return 0 == L.length;
}

/*
 * 获取长度
 */
Status getLength(const SqList L)
{
    return L.length;
}

/*
 * 根据位置获取元素
 */
Status GetElem(const SqList L, int i, Elemtype *e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.elem[i - 1];
    return OK;
}

/*
 * 比较两个元素是否相等
 */
Status compare(Elemtype e1, Elemtype e2)
{
    return strcmp(e1, e2);
}

/*
 * 查找元素
 */
Status FindElem(const SqList L, Elemtype e, Status (*compare)(Elemtype, Elemtype))
{
    int i;
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

/*
 * 插入元素
 */
Status InsertElem(SqList *L, int i, Elemtype e)
{
    Elemtype *new;
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    if (L->length >= L->size) //长度达到容量上限
    {
        new = (Elemtype *)realloc(L->elem, (L->size + INCREMENT_SIZE) * sizeof(Elemtype));
        if (!new)
        {
            return ERROR;
        }
        L->elem = new;
        L->size += INCREMENT_SIZE;
    }
    Elemtype *p = &L->elem[i - 1];
    Elemtype *q = &L->elem[L->length - 1];
    for (; q >= p; q--)
    {
        strcpy(*(q+1),*q);
        //*(q + 1) = *q;
    }
    //*p = e;
    strcpy(*p,e);
    ++L->length;
    return OK;
}

/*
 * 删除元素并返回其值
 */
Status DeleteElem(SqList *L, int i, Elemtype *e)
{
    if (i < 1 || i > L->length)
    {
        return ERROR;
    }
    Elemtype *p = &L->elem[i - 1];
    *e = *p;
    for (; p < &L->elem[L->length]; p++)
    {
        strcpy(*(p),*(p+1));
        //*(p) = *(p + 1);
    }
    --L->length;
    return OK;
}

/*
 * 访问元素
 */
void visit(Elemtype e)
{
    printf("%s ", e);
}

/*
 * 遍历线性表
 */
Status TraverseList(const SqList L, void (*visit)(Elemtype))
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        visit(L.elem[i]);
    }
    return OK;
}

int main()
{
    SqList L;
    char instruct[6];
    int status = 1;
    InitList(&L);
    
    while (scanf("%s", instruct) != EOF && status == 1)
    {
        int a = -1;
        Elemtype name;
        Elemtype e;
        name = (char *)malloc(sizeof(char) * (30 + 1));
        e = (char *)malloc(sizeof(char) * (30 + 1));
        if (!strcmp("insert", instruct)) //insert指令,insert a name
        {
            scanf("%d %s", &a, name);
            int locate = FindElem(L, name, *compare);
            if (!locate) //没找到
            {
                InsertElem(&L, a, name);
            }
            // TraverseList(L, visit);
        }
        else if (!strcmp("delete", instruct)) //delete指令 delete name
        {
            scanf("%s", name);
            int locate = FindElem(L, name, *compare);
            if (locate)
            {
                DeleteElem(&L, locate, &e);
            }
        }
        else if (!strcmp("show", instruct)) //show指令
        {
            if (L.length == 0)
            {
                printf("\n");
            }
            else
            {
                TraverseList(L, visit);
                printf("\n");
            }
        }
        else if (!strcmp("search", instruct)) //search指令 search name
        {
            scanf("%s", name);
            int locate = FindElem(L, name, *compare);
            printf("%d\n", locate);
        }
        else
        {
            status = ERROR;
        }
        //free(name);
        //free(e);
    }

    DestroyList(&L);
    return 0;
}
