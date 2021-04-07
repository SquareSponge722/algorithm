#include<bits/stdc++.h>
const int maxn=5010;
using namespace std;

int n,m;
struct Node
{
    int u,v,id;
}G[maxn<<1];
int tot,head[maxn],tail[maxn];
bool vis[maxn];
int ans[maxn],tmp[maxn];
int today,cnt;

inline void Add(int u,int v,int id) {G[++tot].u=u,G[tot].v=v,G[tot].id=id;}
inline bool cmp(Node x,Node y) {if(x.u==y.u) return x.v<y.v;return x.u<y.u;}

void dfs(int u)
{
    printf("%d ",u),vis[u]=true;
    for(int i=head[u];i<=tail[u];i++)
    {
        int v=G[i].v;
        if(!vis[v]) dfs(v);
    }
}

void Update()
{
    if(!ans[1]) for(int i=1;i<=n;i++) ans[i]=tmp[i];
    int p=1;
    while(tmp[p]==ans[p] && p<n) p++;
    if(tmp[p]<ans[p]) for(int i=p;i<=n;i++) ans[i]=tmp[i];
}

void dfs2(int u)
{
    tmp[++cnt]=u,vis[u]=true;
    for(int i=head[u];i<=tail[u];i++)
    {
        if(G[i].id==today) continue;
        int v=G[i].v;
        if(!vis[v]) dfs2(v);
    }
}

void work()
{
    for(int i=1;i<=m;i++)
    {
        today=i;cnt=0;
        memset(vis,0,sizeof(vis));
        memset(tmp,0,sizeof(tmp));
        dfs2(1);
        if(cnt==n) Update();
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),Add(u,v,i),Add(v,u,i);
    sort(G+1,G+tot+1,cmp);
    for(int i=1;i<=tot;i++) if(G[i].u!=G[i-1].u) head[G[i].u]=i;
    for(int i=tot;i>=1;i--) if(G[i].u!=G[i+1].u) tail[G[i].u]=i;
    if(m==n-1) dfs(1);
    else work();
    return 0;
}
