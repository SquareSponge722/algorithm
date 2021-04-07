//%20 m==1,DFS求树的直径即可
//另15% a==1,菊花图，另20% b==a+1，一条链
#include<iostream>
#include<string.h>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<cstdio>
#define IN inline
#define re register
using namespace std;
const int N=50005;
int n,m,sum,ZJ1;
bool vis[N],ai1=1;
struct edge{int u,v,w;}E[N];
bool cmp(edge a,edge b){return a.w<b.w;}
struct node{int to,w;};
vector<node>G[N];

IN int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}
    while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    while(ch>='0'&&ch<='9');
    return f*x;
}

void dfsTreeZJ(int u,int dep)//求直径
{
    if(dep>sum){sum=dep;ZJ1=u;}
    vis[u]=1;
    for(int i=G[u].size()-1;i>=0;i--)
    {
        int v=G[u][i].to,w=G[u][i].w;
        if(vis[v])continue;
        dfsTreeZJ(v,dep+w);
    }
}

IN void workTreeZJ()
{
    vis[1]=1;
    dfsTreeZJ(1,0);
    memset(vis,0,sizeof(vis));
    vis[ZJ1]=1;sum=0;
    dfsTreeZJ(ZJ1,0);
    cout<<sum<<"\n";
    exit(0);
}

IN void workJuhua()
{
    sort(E+1,E+n,cmp);
    int minx=INT_MAX,lsk=2*n-2*m-1;
    for(int i=n-1;i>=n-m-1;i--)
        minx=min(minx,E[i].w+E[lsk-i].w);
    cout<<minx;
}

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),w=read();
        G[u].push_back((node){v,w});
        G[v].push_back((node){u,w});
        E[i]=(edge){u,v,w};
        if(u!=1)ai1=0;
    }
    if(m==1)
        workTreeZJ();//直径
    if(ai1&&2*m<n)
        workJuhua();//必过两条边的菊花图
    return 0;
}
