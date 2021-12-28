#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5

typedef char ElemType;
typedef int status;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int ser = 0;     //位置
int depth = 0;   //深度
int counter = 0; //计数

/*
 * 创建二叉树,输入0表示创建空树
 */
status CreateBiTree(BiTree *T, char str[])
{
    ElemType e = str[ser];
    if (e != '\0')
        if (e == '#')
        {
            *T = NULL;
            //(*T)->data = e;
            ser++;
        }
        else
        {
            *T = (BiTree)malloc(sizeof(BiTNode));
            if (!T)
            {
                exit(OVERFLOW);
            }
            (*T)->data = e;
            ser++;
            CreateBiTree(&(*T)->lchild, str); //创建左子树
            CreateBiTree(&(*T)->rchild, str); //创建右子树
        }
    return OK;
}

//没啥用
int getMax(int a, int b)
{
    return (a >= b) ? a : b;
}

int GetTreeDepth(BiTree t)
{
    if (t == NULL)
    {
        return 0;
    }
    counter++;
    GetTreeDepth(t->lchild);
    if (counter > depth)
    {
        depth = counter;
    }
    GetTreeDepth(t->rchild);
    counter--;
    return depth;
}

void visit(BiTree t)
{
    printf("%c", t->data);
}

void PreTrave(BiTree t)
{
    if (t != NULL)
    {
        visit(t);
        PreTrave(t->lchild);
        PreTrave(t->rchild);
    }
}

void MidTrave(BiTree t)
{
    if (t != NULL)
    {
        MidTrave(t->lchild);
        visit(t);
        MidTrave(t->rchild);
    }
}

void PostTrave(BiTree t)
{
    if (t != NULL)
    {

        PostTrave(t->lchild);
        PostTrave(t->rchild);
        visit(t);
    }
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
    char str[2001];
    int num;
    BiTree t;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", str);

        CreateBiTree(&t, str);
        printf("%d\n", GetTreeDepth(t));
        ClearBiTree(&t);
        //printf("%d\n", GetTreeDepth(t));
        ser = 0;
        depth = 0;
        counter = 0;
    }
    return 0;
}