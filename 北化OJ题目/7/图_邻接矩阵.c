#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NotPresent 4 //不存在
#define Duplicate 5  //元素重复
#define OVERFLOW -2
#define MAX_NUM 50

typedef int Status;
typedef int ElemType;

Status visited[MAX_NUM];

//垃圾BUCTOJ，居然动态申请内存会不通过，恶心死了
// typedef struct
// {
//     ElemType **a;    //邻接矩阵
//     int n;           //图的顶点数
//     int e;           //图的当前边数
//     ElemType noEdge; //两顶点间无边时的值
// } mGraph;

// Status Init(mGraph *mg, int nSize, ElemType noEdgeValue)
// {
//     int i, j;
//     mg->n = nSize;
//     mg->e = 0; //初始无边
//     mg->noEdge = noEdgeValue;
//     mg->a = (ElemType **)malloc(nSize * sizeof(ElemType)); //生成长度为n的一维指针数组
//     if (!mg->a)
//     {
//         return ERROR;
//     }
//     for (i = 0; i < mg->n; i++) //生成二维
//     {
//         mg->a[i] = (ElemType *)malloc(nSize * sizeof(ElemType));
//         for (j = 0; j < mg->n; j++)
//         {
//             mg->a[i][j] = mg->noEdge;
//         }
//         mg->a[i][i] = 0; //这里将到自己距离设置为0，有点反传统
//     }
//     return OK;
// }

// void Destory(mGraph *mg)
// {
//     for (int i = 0; i < mg->n; i++)
//     {
//         free(mg->a[i]);
//     }
//     free(mg->a);
// }

typedef struct
{
    ElemType a[MAX_NUM][MAX_NUM]; //邻接矩阵
    int n;                        //图的顶点数
    int e;                        //图的当前边数
    ElemType noEdge;              //两顶点间无边时的值
} mGraph;

Status Init(mGraph *mg, int nSize, ElemType noEdgeValue)
{
    int i, j;
    mg->n = nSize;
    mg->e = 0; //初始无边
    mg->noEdge = noEdgeValue;
    for (i = 0; i < mg->n; i++) //生成二维
    {
        for (j = 0; j < mg->n; j++)
        {
            mg->a[i][j] = mg->noEdge;
        }
        mg->a[i][i] = 0; //这里将到自己距离设置为0，有点反传统
    }
    return OK;
}

// void Destory(mGraph *mg)
// {
//     for (int i = 0; i < mg->n; i++)
//     {
//         free(mg->a[i]);
//     }
//     free(mg->a);
// }

void Destory(mGraph *mg)
{
    mg->n = 0;
}

//返回边是否存在
Status Exist(mGraph *mg, int u, int v)
{
    if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge)
    {
        return ERROR;
    }
    return OK;
}

Status Insert(mGraph *mg, int u, int v, ElemType w)
{
    if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v)
    {
        return ERROR;
    }
    if (mg->a[u][v] != mg->noEdge) //已有元素
    {
        return Duplicate;
    }
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}

Status Remove(mGraph *mg, int u, int v)
{
    if (u < 0 || v < 0 || u > mg->n - 1 || v > mg->n - 1 || u == v)
    {
        return ERROR;
    }
    if (mg->a[u][v] == mg->noEdge)
    {
        return NotPresent;
    }
    mg->a[u][v] = mg->noEdge;
    mg->e--;
    return OK;
}

Status InPutMGraph(mGraph *mg)
{
    for (int i = 0; i < mg->n; i++)
    {

        for (int j = 0; j < mg->n; j++)
        {
            scanf("%d", &mg->a[i][j]);
        }
    }
    return OK;
}

Status OutPutMGraph(mGraph *mg)
{
    for (int i = 0; i < mg->n; i++)
    {
        for (int j = 0; j < mg->n; j++)
        {
            printf("%d ", mg->a[i][j]);
        }
        printf("\n");
    }
    return OK;
}

void DFS(mGraph *mg, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%d ", i); //访问
    for (j = 0; j < mg->n; j++)
    {
        if (mg->a[i][j] != mg->noEdge && !visited[j])
        {
            DFS(mg, j);
        }
    }
}

void DFSTraverse(mGraph *mg)
{
    int i;
    for (i = 0; i < mg->n; i++)
    {
        visited[i] = FALSE;
    }
    for (i = 0; i < mg->n; i++)
    {
        if (!visited[i])
        {
            DFS(mg, i);
        }
    }
}

//广度优先需要的循环队列
typedef struct
{
    int data[MAX_NUM];
    int front, rear;
} Queue;

void InitQueue(Queue *Q)
{
    Q->front = Q->rear = 0;
}

void EnQueue(Queue *Q, int e)
{
    if ((Q->rear + 1) % MAX_NUM == Q->front)
    {
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_NUM;
}

Status QueueEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
        return TRUE;
    else
        return FALSE;
}

void DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear)
        return;

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_NUM;
}

void BFSTraverse(mGraph *mg)
{
    int i, j;
    Queue Q;
    for (i = 0; i < mg->n; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(&Q);
    for (i = 0; i < mg->n; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%d ", i);
            EnQueue(&Q, i);
            while (!QueueEmpty(&Q))
            {
                DeQueue(&Q, &i);
                for (j = 0; j < mg->n; j++)
                {
                    if (!visited[j] && mg->a[i][j] != mg->noEdge)
                    {
                        visited[j] = TRUE;
                        printf("%d ", j);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

int main()
{
    mGraph m;
    int nSize;
    scanf("%d", &nSize);
    Init(&m, nSize, 0);
    InPutMGraph(&m);
    //OutPutMGraph(&m);
    //DFSTraverse(&m);
    BFSTraverse(&m);
    printf("\n");
    Destory(&m);
    return 0;
}