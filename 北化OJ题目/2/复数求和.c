#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define MaxLength 99


//复数类型
typedef struct complex
{
    int real;
    int imag;
} Complex;

//结点类型
typedef struct node
{
    Complex complex;   //数据域
    struct node *link; //指针域
} Node;

typedef struct
{
    struct Node *first; //头指针

    int numberOfNodes;  //单链表中元素的个数
} SingleList;

//初始化单链表
int InitSingleList(SingleList *L)
{
    L->first = NULL;
    L->numberOfNodes = 0;
    return OK;
}

//尾部加入元素
int AddNode(SingleList *L, Complex c)
{
    Node *q;
    q = (Node *)malloc(sizeof(Node)); //生成新尾结点
    q->complex = c;
    q->link = NULL;

    //判断空链
    if (L->numberOfNodes == 0)
    {
       // L->first->link = q;
        L->numberOfNodes++;
    }
    else
    {
        Node *p;
        p = L->first;
        for (int i = 0; i < L->numberOfNodes; i++)
        {
            p = p->link;
        }
        q->link = p->link;
        p->link = q;
        L->numberOfNodes++;
        return OK;
    }
}

int CalcuAndOutPut(SingleList *L)
{
    Node *p;
    p = L->first;
    int real_sum, imag_sum;
    for (int i = 0; i < L->numberOfNodes; i++)
    {
        p = p->link;
        real_sum += p->complex.real;
        imag_sum += p->complex.imag;
    }
    printf("%d+%di", real_sum, imag_sum);
    return OK;
}

int main()
{
    int line, real, imag;
    SingleList *Lp;
    InitSingleList(Lp);

    scanf("%d", &line);
    while (line != 0)
    {
        scanf("%d %d", &real, &imag);
        Complex complex;
        complex.real = real;
        complex.imag = imag;
        AddNode(Lp,complex);
            line--;
    }
    CalcuAndOutPut(Lp);
    return 0;
}