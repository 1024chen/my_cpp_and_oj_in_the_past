#include <stdio.h>
#include <stdlib.h>
#include<queue>

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

int ser = 0;

/*
 * 创建二叉树,输入0表示创建空树
 */
status CreateBiTree(BiTree *T,char str[])
{
    ElemType e = str[ser];
    if (e!='\0')
    if (e == '#')
    {
        *T = NULL;
        ser++;
    }
    else
    {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if (!T)
        {
            exit(OVERFLOW);
        }
        (*T)->data = e;
        ser++;
        CreateBiTree(&(*T)->lchild,str);    //创建左子树
        CreateBiTree(&(*T)->rchild,str);    //创建右子树
    }
    return OK;
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

int main()
{
    char str[2001];
    BiTree t;
    while (scanf("%s", str)!=EOF)
    {
    if (str[0] == '#'&&str[1] == '\0')
    {
        printf("\n");
        continue;
    }
    
    CreateBiTree(&t,str);
    MidTrave(t);
    printf(" ");
    PostTrave(t);
    printf(" ");
    LevelTrave(t);
    printf("\n");
    ser = 0;
    }
    return 0;
}