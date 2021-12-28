#include <stdio.h>
#include <stdlib.h>
#include "seqStack.h" //自己写的头文件

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
                InsertENodeAtTail(lg, i, j, mg->a[i][j]); //尾插才能保证和邻接矩阵一样
            }
        }
    }
}

//拓扑排序
//入度计算
void Degree(int *inDegree, LGraph *lg)
{
    int i;
    ENode *p;
    for (i = 0; i < lg->n; i++) //初始化
    {
        inDegree[i] = 0;
    }
    for (i = 0; i < lg->n; i++)
    {
        for (p = lg->a[i]; p; p = p->nextArc)
        {
            inDegree[p->adjVex]++; //将顶点i的邻接点p->adjVex的入度加一
        }
    }
}
//拓扑排序
Status TopoSort(int *topo, LGraph *lg)
{
    int i, j, k;
    ENode *p;
    SqStack s;
    //int *inDegree = malloc(sizeof(ENode) * lg->n);
    int *inDegree = malloc(sizeof(int) * lg->n);
    InitStack(&s);
    Degree(inDegree, lg); //计算各顶点入度
    for (i = 0; i < lg->n; i++)
    {
        if (!inDegree[i]) //入度为0则入栈
        {
            Push(&s, i);
        }
    }
    for (i = 0; i < lg->n; i++)
    {
        if (IsEmpty(&s)) //堆栈为空，存在有向回路
        {
            return ERROR;
        }
        else
        {
            Pop(&s, &j); //顶点出栈
            topo[i] = j; //输出顶点到拓扑序列
            //printf("%d ", j);
            for (p = lg->a[j]; p; p = p->nextArc) //检查以顶点j为尾的所有邻接点
            {
                k = p->adjVex;
                inDegree[k]--;
                if (!inDegree[k])
                {
                    Push(&s, k); //顶点k的入度为0，则入栈
                }
            }
        }
    }
    free(inDegree);
    return OK;
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

    int *topo;
    topo = (int *)malloc(sizeof(int) * lg.n);
    if (TopoSort(topo, &lg) == ERROR)
    {
        printf("ERROR");
    }
    else
    {
        for (int i = 0; i < lg.n; i++)
        {
            printf("%d ", topo[i]);
        }
    }

    free(topo);
    //OutPutLGraph(&lg);
    //DFSGraph(&lg);
    //BFSGraph(&lg);
    DestoryLGraph(&lg);
    return 0;
}