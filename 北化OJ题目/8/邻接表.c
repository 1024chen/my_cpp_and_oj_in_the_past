#include <stdio.h>
#include <stdlib.h>
#include "seqQueue.h"//自己写的头文件

#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4 //元素不存在
#define Duplicate 5  //元素重复
#define MaxVev 100   //最大顶点数
typedef int Status;

typedef int ElemType;
typedef struct ENode //边结点类型
{
    int adjVex;            //任意顶点u相邻接的顶点
    ElemType w;            //边的权值
    struct ENode *nextArc; //指向下一个边结点，一维指针数组存储每条单链表中第一个边结点的地址
} ENode;
typedef struct
{
    int n;     //图的当前顶点数
    int e;     //图的当前边数
    ENode **a; //指向一维指针数组
} LGraph;

//int visited[MaxVev];

Status InitLGraph(LGraph *lg, int nSize)
{
    int i;
    lg->n = nSize;
    lg->e = 0;
    lg->a = (ENode **)malloc(nSize * sizeof(ENode *));
    if (!lg->a)
    {
        return ERROR;
    }
    else
    {
        for (i = 0; i < lg->n; i++)
        {
            lg->a[i] = NULL;
        }
    }
    return OK;
}

void DestoryLGraph(LGraph *lg)
{
    int i;
    ENode *p, *q;
    for (i = 0; i < lg->n; i++)
    {
        p = lg->a[i]; //每次指向单链表的第一个边结点
        q = p;
        while (p) //释放顶点i的单链表中所有的边结点
        {
            p = p->nextArc;
            free(q);
            q = p;
        }
    }
    free(lg->a);
}

//搜索边,存在返回OK，不存在返回ERROR
Status ExistENode(LGraph *lg, int u, int v)
{
    ENode *p;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
    {
        return ERROR;
    }
    p = lg->a[u];
    while (p && p->adjVex != v)
    {
        p = p->nextArc;
    }
    if (!p)
    {
        return ERROR;
    }
    else
        return OK;
}

//头插边
Status InsertENode(LGraph *lg, int u, int v, ElemType w)
{
    ENode *p;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
    {
        return ERROR;
    }
    if (ExistENode(lg, u, v))
    {
        return Duplicate;
    }
    p = (ENode *)malloc(sizeof(ENode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = lg->a[u]; //新结点插入单链表最前面
    lg->a[u] = p;
    lg->e++;
    return OK;
}

//尾插边
Status InsertENodeAtTail(LGraph *lg, int u, int v, ElemType w)
{
    ENode *p, *q, *t;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
    {
        return ERROR;
    }
    if (ExistENode(lg, u, v))
    {
        return Duplicate;
    }
    p = (ENode *)malloc(sizeof(ENode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = NULL;

    q = lg->a[u];
    t = q;
    while (q)
    {
        t = q;
        q = q->nextArc;
    }
    if (t == NULL)
    {
        lg->a[u] = p;
    }
    else
    {
        t->nextArc = p;
    }
    lg->e++;
    return OK;
}

//删除边
Status RemoveENode(LGraph *lg, int u, int v)
{
    ENode *p, *q;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
    {
        return ERROR;
    }
    p = lg->a[u], q = NULL;
    while (p && p->adjVex != v)
    {
        q = p;
        p = p->nextArc;
    }
    if (!p)
    {
        return NotPresent;
    }
    if (q)
    {
        q->nextArc = p->nextArc; //删除边结点
    }
    else
    {
        lg->a[u] = p->nextArc; //如果要删除的是该链表中的第一个结点，则q仍为NULL
    }
    free(p);
    lg->e--;
    return OK;
}

//输出邻接表样式
Status OutPutLGraph(LGraph *lg)
{
    ENode *p;
    printf("顶点数：%d\n", lg->n);
    printf("结点数：%d\n", lg->e);
    for (int i = 0; i < lg->n; i++)
    {
        printf("%d-->", i);
        p = lg->a[i];
        while (p)
        {
            printf("%d(%d)-->", p->adjVex, p->w);
            p = p->nextArc;
        }
        printf("\n");
    }
}

void DFS(int v, int visited[], LGraph *g)
{
    ENode *w;
    printf("%d ", v); //访问顶点v
    visited[v] = 1;
    for (w = g->a[v]; w; w = w->nextArc) //没被访问过则递归调用DFS
    {
        if (!visited[w->adjVex])
        {
            DFS(w->adjVex, visited, g);
        }
    }
}

void DFSGraph(LGraph *g)
{
    int i;
    int *visited = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < g->n; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited, g);
        }
    }
    free(visited);
}

void BFS(int v, int visited[], LGraph *g)
{
    ElemType x;
    ENode *w;
    SqQueue q;
    InitQueue(&q);
    printf("%d ", v); //访问顶点
    visited[v] = 1;
    EnQueue(&q, v);
    while (!IsEmpty(&q))
    {
        GetHead(&q, &v);
        DeQueue(&q, &x);
        for (w = g->a[v]; w; w = w->nextArc) //遍历v所有邻接点
            if (!visited[w->adjVex])
            {
                printf("%d ", w->adjVex);
                visited[w->adjVex] = 1;
                EnQueue(&q, w->adjVex);
            }
    }
}

void BFSGraph(LGraph *g)
{
    int i;
    int *visited = malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < g->n; i++)
    {
        if (!visited[i])
        {
            BFS(i, visited, g);
        }
    }
    free(visited);
}

//增设的邻接矩阵类型与对应函数
typedef struct
{
    ElemType a[MaxVev][MaxVev]; //邻接矩阵
    int n;                      //图的顶点数
    int e;                      //图的当前边数
    ElemType noEdge;            //两顶点间无边时的值
} mGraph;

Status InitMGraph(mGraph *mg, int nSize, ElemType noEdgeValue)
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
    }
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

void MGraphToLGraph(mGraph *mg, LGraph *lg)
{
    int i, j;
    InitLGraph(lg, mg->n);
    for (i = 0; i < mg->n; i++)
    {
        for (j = 0; j < mg->n; j++)
        {
            if (mg->a[i][j] != mg->noEdge)
            {
                //InsertENode(lg, i, j, mg->a[i][j]);
                InsertENodeAtTail(lg, i, j, mg->a[i][j]);//尾插才能保证和邻接矩阵一样
            }
        }
    }
}

int main()
{
    mGraph mg;
    LGraph lg;
    int nSize;
    scanf("%d", &nSize);
    InitMGraph(&mg, nSize, 0);
    InPutMGraph(&mg);
    MGraphToLGraph(&mg, &lg);
    //OutPutLGraph(&lg);
    //DFSGraph(&lg);
    //BFSGraph(&lg);
    DestoryLGraph(&lg);
    return 0;
}