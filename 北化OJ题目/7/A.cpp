#include <stdio.h>
#define MAX_V 10
#include <queue>
using namespace std;
typedef struct Graph
{
    int n;
    char v[MAX_V];
    int edge[MAX_V][MAX_V];
    int isVisited[MAX_V];
} Graph;

void print(Graph *g)
{
    printf("%d\n", g->n);
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            printf("%d ", g->edge[i][j]);
        }
        printf("\n");
    }
}
/*
������ȱ���
E1������һδ���������Ķ���Ϊ��㣬�ȷ��ʸö��㣻
E2������������ȱ����ö��������δ�����������ڽӵ㣻
E3����������δ�������Ķ��㣬���ظ�E1��
*/

void dfs(Graph *g, int i)
{
    printf("%c", g->v[i]);
    g->isVisited[i] = 1;
    for (int j = 0; j < g->n; j++)
    {
        if (g->edge[i][j] == 1)
        {
            if (g->isVisited[j] == 0)
            {
                dfs(g, j);
            }
        }
    }
}
void dfs(Graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        if (g->isVisited[i] == 0)
        {
            dfs(g, i);
        }
    }
}

void bfs(Graph *g)
{
    queue<int> q;
    for (int i = 0; i < g->n; i++)
    {
        g->isVisited[i] = 0;
    }
    for (int i = 0; i < g->n; i++)
    {
        printf("========%d start\n", i);
        if (g->isVisited[i] == 0)
        {
            q.push(i);
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                printf("%c", g->v[temp]);
                g->isVisited[temp] = 1;
                for (int j = 0; j < g->n; j++)
                {
                    if (g->edge[temp][j] == 1)
                    {
                        if (g->isVisited[j] == 0)
                        {
                            //g->isVisited[j] = 1;
                            //printf("=========push %d %d\n",temp,j);
                            q.push(j);
                        }
                    }
                }
            }
        }
        printf("\n========%d end\n", i);
    }
}

int main()
{
    freopen("A.in", "r", stdin);
    int n;
    scanf("%d", &n);
    Graph g;
    g.n = n;
    for (int i = 0; i < n; i++)
    {
        g.v[i] = '0' + i;
        g.isVisited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g.edge[i][j]);
        }
    }
    //print(&g);
    dfs(&g);
    //bfs(&g);
    return 0;
}
