#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef char TElemType;

/*
 * 存储结构
 */
typedef struct BiTNode
{
    TElemType data; //数据
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree CreateBiTreeByPreTraAndMidTra(string pre, string mid)
{
    BiTree tree = NULL;
    if (pre.size() > 0)
    {
        tree = new BiTNode;
        tree->data = pre[0];
        tree->lchild = NULL;
        tree->rchild = NULL;
    }
    if (pre.size() > 1)
    {
        int rooter; //找根节点在中序的位置
        for (int i = 0; i < mid.size(); i++)
        {
            if (mid[i] == tree->data)
            {
                rooter = i;
                break;
            }
        }
        //重建左子树
        string pre_left = pre.substr(1, rooter);
        string mid_left = mid.substr(0, rooter);
        tree->lchild = CreateBiTreeByPreTraAndMidTra(pre_left, mid_left);
        //重建右子树
        string pre_right = pre.substr(rooter + 1, pre.size() - rooter - 1);
        string mid_right = mid.substr(rooter + 1, mid.size() - rooter - 1);
        tree->rchild = CreateBiTreeByPreTraAndMidTra(pre_right, mid_right);
    }
    return tree;
}

//后序遍历
void PostOrderTraverse(BiTree t)
{
    if (t != NULL)
    {
        if (t->lchild != NULL)
        {
            PostOrderTraverse(t->lchild);
        }
        if (t->rchild != NULL)
        {
            PostOrderTraverse(t->rchild);
        }
        cout << t->data;
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
        cout<<p->data;
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
    string pre, mid;
    while (cin >> pre >> mid)
    {
        BiTree t = CreateBiTreeByPreTraAndMidTra(pre, mid);
        PostOrderTraverse(t);
        cout << " ";
        LevelTrave(t);
        cout << endl;
    }

    return 0;
}