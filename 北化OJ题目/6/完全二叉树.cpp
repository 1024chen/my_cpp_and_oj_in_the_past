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

//判断是否是完全二叉树
status isCompleteBiTree(BiTree t)
{
    if (t == NULL)
    {
        return TRUE;
    }
    queue<BiTree> e;
    BiTree p;
    p = t;
    e.push(p);
    while (!e.empty())
    {
        p = e.front();
        e.pop();
        if (!p)//读到空指针停止循环
        {
            break;
        }
        e.push(p->lchild);
        e.push(p->rchild);
    }
    while (!e.empty())
    {
        p = e.front();
        e.pop();
        if(p)
            return FALSE;
    }
    return TRUE;
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
    BiTree t;
    while (scanf("%s",str)!=EOF)
    {
        CreateBiTree(&t, str);
        if(isCompleteBiTree(t) == TRUE){
            printf("Yes\n");
        }else
        {
            printf("No\n");
        }
        
        ClearBiTree(&t);
        ser = 0;
    }
    
    return 0;
}