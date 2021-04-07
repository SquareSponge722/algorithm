#include<bits/stdc++.h>
typedef long long LL;
const LL INF=LLONG_MAX/3;
const LL maxn=100010;
using namespace std;

LL n,m,w[maxn],dep[maxn],fa[maxn];
string type;
LL tot,to[maxn<<1],nxt[maxn<<1],head[maxn];
LL a,x,b,y,f[maxn],g[maxn],nf[maxn],ng[maxn];

inline void Add(LL u,LL v) {to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
inline void init() {for(LL i=1;i<=n;i++) f[i]=nf[i],g[i]=ng[i];}

void dfs(LL u,LL d,LL f)
{
    dep[u]=d,fa[u]=f;
    for(LL i=head[u];i;i=nxt[i])
        if(!dep[to[i]]) dfs(to[i],d+1,u);
}

void UpdateG(LL u)
{
    g[u]=0;
    for(LL i=head[u];i;i=nxt[i])
    {
        LL v=to[i];
        if(dep[v]<dep[u]) continue;
        if(f[v]>=INF) {g[u]=INF;return;}
        g[u]+=f[v];
    }
}

void UpdateF(LL u)
{
    f[u]=w[u];
    for(LL i=head[u];i;i=nxt[i])
    {
        LL v=to[i];
        if(dep[v]<dep[u]) continue;
        if(min(f[v],g[v])>=INF) {f[u]=INF;return;}
        f[u]+=min(f[v],g[v]);
    }
}

void TreeDP(LL u)
{
    for(LL i=head[u];i;i=nxt[i])
        if(dep[to[i]]>dep[u]) TreeDP(to[i]);
    UpdateG(u),UpdateF(u);
}

void Update(int u)
{
    if(!u) return;
    if((a==u && x==0) || (b==u && y==0)) UpdateG(u),f[u]=INF;
    else if((a==u && x==1) || (b==u && y==1)) UpdateF(u),g[u]=INF;
    else UpdateG(u),UpdateF(u);
    Update(fa[u]);
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    scanf("%lld%lld",&n,&m);cin>>type;
    for(LL i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(LL i=1,u,v;i<n;i++) scanf("%lld%lld",&u,&v),Add(u,v),Add(v,u);
    dfs(1,1,0);TreeDP(1);
    for(LL i=1;i<=n;i++) nf[i]=f[i],ng[i]=g[i];
    for(LL i=1;i<=m;i++)
    {
        init();
        scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
        if(x==0) f[a]=INF;else g[a]=INF;
        if(y==0) f[b]=INF;else g[b]=INF;
        Update(fa[a]),Update(fa[b]);
        LL ans=min(f[1],g[1]);
        printf("%lld\n",ans=(ans>=INF? -1:ans));
    }
    return 0;
}
