#include<bits/stdc++.h>
const int maxn=50010;
using namespace std;

int n,m,sum,son[maxn];
int tot,to[maxn<<1],nxt[maxn<<1],len[maxn<<1],head[maxn];
bool b2=true,b3=true;
int dis[maxn],mx;
bool vis[maxn];
int today,todayans;

void Add(int u,int v,int w)
{
    to[++tot]=v,nxt[tot]=head[u],len[tot]=w,head[u]=tot;
}

void dfs(int u)
{
    vis[u]=true;
    if(dis[u]>dis[mx]) mx=u;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(vis[v]) continue;
        dis[v]=dis[u]+len[i];
        dfs(v);
    }
}

void work1()
{
    mx=0;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dfs(1);
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dfs(mx);
    printf("%d",dis[mx]);
    exit(0);
}

bool check2(int mid)
{
    int now=0,nows=0;
    for(int i=1;i<n;i++)
    {
        nows+=len[head[i]];
        if(nows>=mid) now++,nows=0,i++;
    }
    return now>=m;
}

void work2()
{
    int ans=0,l=0,r=sum/2;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check2(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    exit(0);
}

bool check3(int mid)
{
    for(int i=2;i<=n;i++) dis[i-1]=len[head[i]];
    sort(dis+1,dis+n);
    int p1=1,p2=n-1;
    for(int i=1;i<=m;i++)
    {
        if(dis[p2]>=mid) {p2--;continue;}
        while(dis[p1]+dis[p2]<mid && p1<p2) p1++;
        if(p1==p2) return false;
        p1++,p2--;
    }
    return true;
}

void work3()
{
    int ans=0,l=0,r=sum/2;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check3(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    exit(0);
}

int TreeDP(int u)
{
    vis[u]=true;
    int cnt=0,tmp[son[u]+100];
    bool vi[son[u]+100];
    memset(vi,0,sizeof(vi));
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(vis[v]) continue;
        tmp[++cnt]=TreeDP(v)+len[i];
    }
    if(!cnt) return 0;
    sort(tmp+1,tmp+cnt+1);
    int p1=1,p2=cnt;
    while(tmp[p2]>=today) todayans++,vi[p2--]=true;
    while(p1<p2)
    {
        if(vi[p1]) p1++;
        for(int i=p1+1;i<=p2;i++)
        {
            if(vi[i]) continue;
            if(tmp[p1]+tmp[i]<today) continue;
            todayans++,vi[p1]=vi[i]=true;
            break;
        }
        p1++;
    }
    for(int i=cnt;i>=1;i--) if(!vi[i]) return tmp[i];
    return 0;
}

bool check(int mid)
{
    memset(vis,0,sizeof(vis));
    today=mid;todayans=0;
    TreeDP(1);
    return todayans>=m;
}

inline int read()
{
    int tmp=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) tmp=(tmp<<1)+(tmp<<3)+ch-'0',ch=getchar();
    return tmp;
}

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    n=read(),m=read();
    for(int i=1,u,v,w;i<n;i++)
    {
        u=read(),v=read(),w=read(),Add(u,v,w),Add(v,u,w);
        son[u]++,son[v]++;
        if(v!=u+1) b2=false;
        if(u!=1) b3=false;
        sum+=w;
    }
    if(m==1) work1();
    else if(b2) work2();
    else if(b3) work3();

    int ans=0,l=0,r=sum/m;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}

