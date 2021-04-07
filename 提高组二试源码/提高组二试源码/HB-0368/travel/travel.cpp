#include <cstdio>
#include <vector>
#include <algorithm>
const int N=5e3+10;
int head[N],to[N<<1],Next[N<<1],cnt=1;
void add(int u,int v)
{
    to[++cnt]=v,Next[cnt]=head[u],head[u]=cnt;
}
int n,m,tot;
struct node
{
    int road[N];
    bool friend operator <(node n1,node n2)
    {
        for(int i=1;i<=n;i++)
            if(n1.road[i]!=n2.road[i])
                return n1.road[i]<n2.road[i];
        return n1.road[n]<n2.road[n];
   }
}ans,s;
std::vector <int> edge[N];
void dfs(int now,int fa)
{
    s.road[++tot]=now;
    for(int i=0;i<edge[now].size();i++)
    {
        int v=edge[now][i];
        if(v!=fa) dfs(v,now);
    }
}
void work(int id)
{
    tot=0;
    for(int u=1;u<=n;u++)
    {
        edge[u].clear();
        for(int i=head[u];i;i=Next[i])
        {
            if(i==id||(i^1)==id) continue;
            edge[u].push_back(to[i]);
        }
    }
    for(int u=1;u<=n;u++)
        std::sort(edge[u].begin(),edge[u].end());
    dfs(1,0);
}
int sta[N],in[N],E[N],ct;
void dfs0(int now,int fa)
{
    if(ct) return;
    if(in[now])
    {
        int tmp=tot;
        E[++ct]=sta[tot--];
        while(to[sta[tot]]!=now)
            E[++ct]=sta[tot--];
        in[now]=0;
        tot=tmp;
        return;
    }
    in[now]=1;
    for(int i=head[now];i;i=Next[i])
        if(to[i]!=fa)
        {
            sta[++tot]=i;
            dfs0(to[i],now);
            --tot;
        }
    in[now]=0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int u,v,i=1;i<=m;i++)
        scanf("%d%d",&u,&v),add(u,v),add(v,u);
    ans.road[1]=n+1;
    if(m==n-1)
    {
        work(0);
        for(int i=1;i<=n;i++)
            printf("%d ",s.road[i]);
        return 0;
    }
    else
    {
        dfs0(1,0);
        for(int k=1;k<=ct;k++)
        {
            work(E[k]);
            ans=ans<s?ans:s;
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans.road[i]);
    }
    return 0;
}