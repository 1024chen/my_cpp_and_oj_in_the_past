#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

string OPT;
struct Node
{
    long long P, Num;
    Node() {}
    Node(long long X, long long Y) : P(X), Num(Y) {}
    bool operator<(const Node &A) const
    {
        return P > A.P; //编号从小到大,原因在下面
    }
};
priority_queue<Node> Ans;    //用来存已有的点
priority_queue<Node> OutPut; //用来输出的
map<long long, bool> Che;
//(long long)用来将表示位置的那一串转换成二进制,bool表示这个位置是否出现过

inline void WorkOut()
{
    long long i(1), Num(0), P(1);
    for (; OPT[i] != ','; ++i)
        Num = (Num << 1) + (Num << 3) + (OPT[i] ^ 48); //string转换成int
    ++i;
    for (; OPT[i] != ')'; ++i)
        OPT[i] == 'L' ? P = P << 1 : P = P << 1 | 1; //将LR的表示变成二进制,与线段树LSon = Root << 1, RSon = Root << 1 | 1比较类似,所以1是根节点
    Ans.push(Node(P, Num));
}

inline bool Check()
{
    Che[0] = 1;
    while (!Ans.empty())
    {
        if (!Che[Ans.top().P >> 1] || Che[Ans.top().P])
            return 0;
        //如果没有爸爸,那这个树不能输出,这个位置有两个值,也不能输出
        Che[Ans.top().P] = 1;
        OutPut.push(Ans.top());
        Ans.pop();
    }
    return 1;
}

int main()
{
    while (cin >> OPT)
    {
        WorkOut();
        while (cin >> OPT && OPT.size() > 2)
            WorkOut();
        if (Check())
        {
            while (OutPut.size() > 1) //好像要卡空格,所以特殊处理一下
            {
                cout << OutPut.top().Num << ' ';
                OutPut.pop();
            }
            cout << OutPut.top().Num << endl;
        }
        else
            cout << "not complete" << endl;
        while (!OutPut.empty())
            OutPut.pop(); //清空
        while (!Ans.empty())
            Ans.pop(); //清空
        Che.clear();
    }
}
