#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NotPresent 4 //不存在
#define Duplicate 5  //元素重复
#define OVERFLOW -2
#define MAX_NUM 50

#define INFINTY INT_MAX
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

//迪杰斯特拉算法
//选出最小的d[i],i属于V-S集合
int Choose(int *d, int *s, int n)
{
    int i, minpos;
    ElemType min;
    min = INFINTY;
    minpos = -1;
    for (i = 0; i < n; i++)
    {
        if (d[i] < min && !s[i])
        {
            min = d[i];
            minpos = i;
        }
    }
    return minpos;
}
//对距离矩阵做INFINTY转换
Status TransToInfinty(mGraph *mg)
{
    for (int i = 0; i < mg->n; i++)
    {
        for (int j = 0; j < mg->n; j++)
        {
            if (mg->a[i][j] == mg->noEdge)
            {
                mg->a[i][j] = INFINTY;
            }
        }
    }
    return OK;
}

//迪杰斯特拉算法
Status Dijkstra(int v, ElemType *d, int *path, mGraph *mg)
{
    int i, w, k;
    int *s;
    if (v < 0 || v > mg->n - 1)
    {
        return ERROR;
    }
    s = malloc(sizeof(int) * mg->n);
    d = (ElemType *)malloc(sizeof(ElemType) * mg->n);
    path = (int *)malloc(sizeof(int) * mg->n);
    for (i = 0; i < mg->n; i++) //初始化
    {
        s[i] = 0;
        d[i] = mg->a[v][i];
        if (i != v && d[i] < INFINTY) //不是v点且边存在
        {
            path[i] = v;
        }
        else
        {
            path[i] = -1;
        }
    }
    s[v] = 1; //顶点为源点
    d[v] = 0;
    for (i = 0; i < mg->n - 1; i++)
    {
        k = Choose(d, s, mg->n);
        s[k] = 1; //k加入S中
        //printf("%d ", k);
        for (w = 0; w < mg->n; w++)
        {
            if (!s[w] && d[k] != INFINTY && mg->a[k][w] != INFINTY && d[k] + mg->a[k][w] < d[w]) //更新d和path
            {
                d[w] = d[k] + mg->a[k][w];
                path[w] = k;
            }
        }
    }
    for (i = 0; i < mg->n; i++)
    {
        if (i == v)
        {
            continue;
        }

        printf("%d ", d[i]);
    }
    printf("\n");
    // for (i = 0; i < mg->n; i++)
    // {
    //     printf("%d ", path[i]);
    // }
    // printf("\n");
    // for (i = 0; i < mg->n; i++)
    // {
    //     printf("%d ", s[i]);
    // }

    free(path);
    free(d);
    free(s);
    return OK;
}

int main()
{
    mGraph mg;
    int n, s;
    ElemType *d;
    int *path;
    scanf("%d %d", &n, &s); //源点为s-1
    Init(&mg, n, 0);
    InPutMGraph(&mg);
    TransToInfinty(&mg);
    Dijkstra(s, d, path, &mg);
    //OutPutMGraph(&mg);
    Destory(&mg);
    return 0;
}