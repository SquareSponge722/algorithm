#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

const int maxn=5005;
const int maxm=5005;
const double MAX_TIME = 0.5;
const double Dlt=0.97;
const double eps=1e-10;
int n,m;
int vis[maxn];
int h[maxn];

struct Edge {
    int v,next;
} edge[maxm];

int edge_num=0;
void AddEdge(int u,int v)
{
    edge[++edge_num].next=h[u];
    edge[edge_num].v=v;
    h[u]=edge_num;
}
int check(int a[maxn],int b[maxn])
{
    for(int i=1; i <= n; ++i) if(a[i]<b[i]) return (a[i]-b[i]);
    return 0;
}
int r[maxn];
void solve(int s, int a[maxn],int cnt)
{
    if(cnt>n) {
        for(int i=1; i<=n; ++i) r[i]=a[i];
        return;
    }
    for(int i=h[s]; i; i=edge[i].next) {
        int v=edge[i].v;
        if(vis[v]>1) continue;
        if(vis[v]==0) {
            a[cnt]=v;
            vis[v]++;
            solve(v,a,++cnt);
        } else {
            vis[v]++;
            vis[s]++;
            solve(v,a,cnt);
        }
    }
}
int ed[maxn];
void SA()
{
    memset(vis,0,sizeof(vis));
    int times=10;
    vis[1]=1;
    int a[maxn];
    a[1]=1;
    solve(1,a,2);
    int ans[maxn];
    for(int i=1; i<=n; ++i) ans[i]=r[i];
    while(times--) {
        int sum[maxn];
        for(double T=10000; T>eps; T*=Dlt) {
            int x,y;
            x=rand()%n+1;
            y=rand()%n+1;
            swap(edge[x],edge[y]);
            int b[maxn];
            b[1]=x;
            vis[x]=1;
            solve(x,b,2);
            int nxt[maxn];
            for(int i=1; i<=n; ++i) nxt[i]=r[i];
            int delta = check(nxt,ans);
            if (delta==0) continue;
            if(delta < 0) {
                for(int i=1; i<=n; ++i) ans[i]=nxt[i];
                continue;
            } else if(exp(-delta/T)< rand()/RAND_MAX) {
                for(int i=1; i<=n; ++i) ans[i] = nxt[i];
                continue;
            }
            swap(edge[x],edge[y]);
        }
        if(check(sum,ans)<0) for(int i=1; i<=n; ++i) ans[i]=sum[i];
    }
    for(int i=1; i<=n; ++i) ed[i]=ans[i];
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    srand(19260817);
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1; i<=m; ++i) {
        scanf("%d%d",&u,&v);
        AddEdge(u,v);
        AddEdge(v,u);
    }
    SA();
    int ma[maxn];
    for(int i=1; i<=10000; ++i) {
        int x=rand()%n+1;
        vis[x]=1;
        int a[maxn];
        a[1]=x;
        solve(1,a,2);
        if(check(r,ma)) for(int i=1; i<=n; ++i) ma[i]=r[i];
    }
    //for(int i=1; i<=n; ++i) cout<<ma[i]<<" ";
    for(int i=1; i<=n; ++i) cout<<ed[i]<<" ";
    cout<<endl;
    return 0;
}
