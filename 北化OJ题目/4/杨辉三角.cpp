//队列的顺序存储c++实现
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;

#define MaxSize 100
typedef struct sQueue
{
    ElemType data[MaxSize]; //存放队列元素
    int front;              //队头指针
    int rear;               //队尾指针,指向队尾元素的下一个元素
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

bool IsEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//入队
bool EnQueue(SqQueue &Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front) //队满报错
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize; //队尾步进
    return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.rear == Q.front) //队空报错
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; //队头步进
    return true;
}

//获取队头元素
bool GetHead(SqQueue &Q, ElemType &x)
{
    if (Q.rear == Q.front) //队空报错
    {
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

//获取长度
int GetLength(SqQueue Q)
{
    return Q.rear - Q.front;
}

/*
 * 访问元素
 */
void visit(ElemType e)
{
    printf("%d ", e);
}

/*
 * 遍历队列
 */
bool TraverseQueue(SqQueue Q, void (*visit)(ElemType))
{
    for (int i = Q.front; i < Q.rear; i++)
    {
        visit(Q.data[i]);
    }

    return true;
}

void YanghuiTriangle(SqQueue &Q, int n)
{
    EnQueue(Q, 1);
    int i, j, m, l;
    for (i = 1; i <= n; i++)
    {
        m = 0;
        l = 0;
        for (j = 1; j <= i; j++)
        {
            l = m;
            DeQueue(Q, m);
            // if (j < i)
            // {
            //     printf("%d ", m);
            // }
            // else
            // {
            //     printf("%d", m);
            // }
            if (j == 1)
            {
                printf("%d", m);
            }
            else
            {
                if (n >= 2 && n <= 5)
                {
                    printf("%2d", m);
                }
                else if (n > 5 && n < 10)
                {
                    printf("%3d", m);
                }
                else if (n > 9 && n < 14)
                {
                    printf("%4d", m);
                }
                else if (n > 13 && n < 17)
                {
                    printf("%5d", m);
                }
                else if (n > 16 && n < 21)
                {
                    printf("%6d", m);
                }
                else if (n > 20 && n < 24)
                {
                    printf("%7d", m);
                }
                else if (n > 23 && n <27)
                {
                    printf("%8d", m);
                }
                else if (n > 26 && n < 31)
                {
                    printf("%9d", m);
                }
            }
            EnQueue(Q, m + l);
        }
        EnQueue(Q, m);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n <= 0 || n > 30)
            break;
        SqQueue Q;
        InitQueue(Q);
        YanghuiTriangle(Q, n);
    }
    return 0;
}