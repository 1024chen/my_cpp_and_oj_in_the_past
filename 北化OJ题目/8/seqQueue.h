#ifndef SeqQueue_FILE
#define SeqQueue_FILE

//队列的顺序存储实现
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

#define MaxSize 50
typedef struct sQueue
{
    ElemType data[MaxSize]; //存放队列元素
    int front;              //队头指针
    int rear;               //队尾指针,指向队尾元素的下一个元素
} SqQueue;

void InitQueue(SqQueue*Q)
{
    Q->rear = Q->front = 0;
}

Status IsEmpty(SqQueue* Q)
{
    if (Q->rear == Q->front)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//入队
Status EnQueue(SqQueue *Q, ElemType x)
{
    if ((Q->rear + 1) % MaxSize == Q->front) //队满报错
    {
        return FALSE;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize; //队尾步进
    return TRUE;
}

//出队
Status DeQueue(SqQueue *Q, ElemType *x)
{
    if (Q->rear == Q->front) //队空报错
    {
        return FALSE;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize; //队头步进
    return TRUE;
}

//获取队头元素
Status GetHead(SqQueue *Q, ElemType *x)
{
    if (Q->rear == Q->front) //队空报错
    {
        return FALSE;
    }
    *x = Q->data[Q->front];
    return TRUE;
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
Status TraverseQueue(SqQueue Q, void (*visit)(ElemType))
{
    for (int i = Q.front; i < Q.rear; i++)
    {
        visit(Q.data[i]);
    }

    return TRUE;
}

#endif