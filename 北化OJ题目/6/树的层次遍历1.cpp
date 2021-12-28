#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream in("input.txt");
ofstream out("output.txt");
#define debug(x) cerr<<#x<<" = "<<x<<endl
#define debugs(x,y) cerr<<#x<<" = "<<x<<"   "<<#y<<" = "<<y<<endl
const ll N=5e5+7;
const ll base=137;
const ll mod=2147483647;
template<typename T>inline T read(T &x)
{
    x=0;ll f=1;char c;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
struct node
{
    ll v;//编号
    bool have_value;
    node *left,*right;
    node():have_value(false),left(NULL),right(NULL){}
};
ll v;
bool flag;
char s[N];
node *root;
node* newnode(){return new node();}
inline void remove_tree(node *p)
{
    if(p==NULL)return ;
    remove_tree(p->left);
    remove_tree(p->right);
    delete p;
}
inline bool bfs(vector<ll>&ans)
{
    ans.clear();
    queue<node*>q;
    q.push(root);
    while(!q.empty())//利用队列的先进先出来实现层序遍历
    {
        node*u=q.front();
        q.pop();
        if(!u->have_value)
            return false;
        ans.push_back(u->v);
        if(u->left!=NULL)
            q.push(u->left);
        if(u->right!=NULL)
            q.push(u->right);
    }
    return true;
}
inline void add_node(ll v,char *s)
{
    int len=strlen(s);
    node*u=root;
    for(int i=0;i<len;++i)
    {
        if(s[i]=='L'){
            if(u->left==NULL)
                u->left=newnode();
            u=u->left;
        }
        if(s[i]=='R'){
            if(u->right==NULL)
                u->right=newnode();
            u=u->right;
        }
    }
    if(u->have_value){flag=true;}
    u->v=v;
    u->have_value=true;
}
inline bool read_input()
{
    flag=false;
    remove_tree(root);
    root=newnode();
    for( ;; )
    {
        if(scanf("%s", s) != 1) {
            return false;
        }
        if(strcmp(s,"()") == 0) {
            break;
        }
        sscanf(&s[1],"%d",&v);
        add_node(v,strchr(s,',')+1);
    }
    return true;
}
int main()
{
    vector<ll>ans;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(read_input())
    {

        if(flag||!bfs(ans)){
            printf("not complete");
        }
        else {
            for(vector<ll>::iterator it=ans.begin();it!=ans.end();it++){
                if(it!=ans.end()-1)
                    printf("%lld ",*it);
                else printf("%lld",*it);
            }
        }
        puts("");
    }
    return 0;
}
