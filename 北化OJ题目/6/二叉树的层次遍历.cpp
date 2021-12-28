#include <stdio.h>
#include <stdlib.h>
#include <queue>
//该程序未完成
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5
#define maxStrLen 100

typedef char ElemType;
typedef int status;

typedef struct BiTNode
{
    //ElemType data;
    ElemType data[30];
    struct BiTNode *lchild, *rchild;
    ElemType k[100]; //移动序列
} BiTNode, *BiTree;

typedef struct BiTL
{
    int num;
    int root;
    BiTNode list[100];
} BiTList;

//左子返回0，右子返回1，无子返回-1
int findChildAndBuildTree(BiTree *T, char str[])
{
    BiTree *temp;
    *temp = (BiTree)malloc(sizeof(BiTNode));

}

status CreateBiTreeByBracket(BiTree *T, char str[])
{
    *T = (BiTree)malloc(sizeof(BiTNode));
    //(*T)->k = (char *)malloc(maxStrLen * sizeof(char));
    //((*T)->k) = ",)";
    int i = 0, m = 0, j = 0;
    while (str[i] != '(' && str[i + 1] != ')') //寻找根节点
    {
        if (str[i] == ',' && str[i + 1] == ')')
        {
            for (m = i; str[m] != '('; m--)
            {
            }
            for (int n = m + 1; n < i; n++)
            {
                (*T)->k[j] = str[n];
                j++;
            }
            (*T)->k[++j] = '\0';
            break;
        }
        i++;
    }
}

BiTList CreateBiTList(char str[])
{
    BiTList BL;
    int i = 0,j=0,iter;//子步进，list步进
    BL.num = 0;
    while (str[i] != '(' && str[i + 1] != ')')
    {
        if (str[i] == '(')//左括号开始
        {
            iter = 0;
            for ( j = i+1;str[j]!=','; j++)//匹配到,
            {
                BL.list[BL.num].data[iter] = str[j];
                iter++;
            }
            BL.list[BL.num].data[++iter] = '\0';
            if (str[j+1] == ')')//寻找根节点
            {
                BL.root = BL.num;
                BL.list[BL.num].k[0] = '\0';
            }
            
        }
        
        i++;
    }
    return BL;
}

    void
    visit(BiTree t)
{
    printf("%s", t->data);
}

void LevelTrave(BiTree t)
{
    queue<BiTree> e;
    BiTree p;
    e.push(t);
    while (!e.empty())
    {
        p = e.front();
        e.pop();
        visit(p);
        if (p->lchild != NULL)
        {
            e.push(p->lchild);
        }
        if (p->rchild != NULL)
        {
            e.push(p->rchild);
        }
    }
}

void ClearBiTree(BiTree *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    if ((*t)->lchild != NULL)
        ClearBiTree(&(*t)->lchild);
    if ((*t)->rchild != NULL)
        ClearBiTree(&(*t)->rchild);
    free(*t);
    (*t) = NULL;
}

int main()
{
    char str[50000];
    int num;
    BiTree t;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", str);

        CreateBiTreeByBracket(&t, str);
        LevelTrave(t);
        ClearBiTree(&t);
        ser = 0;
    }
    return 0;
}