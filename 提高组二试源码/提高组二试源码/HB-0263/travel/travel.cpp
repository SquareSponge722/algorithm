#include<cstdio>//AFO
#include<cstring>
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;
int Min(int x,int y)
{
    return x<y?x:y;
}
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
struct edge
{
    int n,nxt;
    edge(int n,int nxt)
    {
        this->n=n;
        this->nxt=nxt;
    }
    edge(){}
}e[10100];
int head[5050],ecnt=-1;
void add(int from,int to)
{
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
    e[++ecnt]=edge(from,head[to]);
    head[to]=ecnt;
}
bool used[5050],ava[5050];
bool used1[5050];
int n,flag;
int dfs(int x)
{
    int ans=n+1;//能找到的最小的合法
    if(ava[x])
        ans=x;
    used1[x]=1;
    for(int i=head[x];~i;i=e[i].nxt)
        if(!used[e[i].n]&&!used1[e[i].n])
            ans=Min(ans,dfs(e[i].n));
    return ans;
}
void Dfs(int x)
{
    printf("%d ",x);
    used[x]=1;
    ava[x]=0;
    vector<int> v;
    for(int i=head[x];~i;i=e[i].nxt)
        if(!used[e[i].n])
        {
            ava[e[i].n]=1;
            v.push_back(e[i].n);
        }
    //如果当前点p=1 可以去找另一端
    sort(v.begin(),v.end());
    if(v.empty())
        return;
    int mx=v.back();
    int tot=v.size();
    for(int i=0;i<tot-1;++i)
        if(ava[v[i]])
            Dfs(v[i]);
    if(!ava[mx])
        return;
    if(flag)
    {
        memset(used1,0,sizeof(used1));
        int tmp=dfs(mx);
        if(tmp<mx)
        {
            mx=tmp;
            flag=0;
        }
    }
    Dfs(mx);
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(head,-1,sizeof(head));
    int m,u,v,pos;
    n=read();
    m=read();
    for(int i=1;i<=m;++i)
    {
        u=read();
        v=read();
        add(u,v);
    }
    flag=(n==m);
    Dfs(1);
    return 0;
}

