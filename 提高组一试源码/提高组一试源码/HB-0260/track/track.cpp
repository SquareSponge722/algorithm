#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int mx=1000000;
const int inf=0x3f3f3f3f;
int head[mx],dis[mx],vis[mx],cnt;
int n,m;
struct edge
{
    int u,v,w;
}a[mx];
void add(int u,int v,int w)
{
    a[++cnt].u=v;
    a[cnt].v=head[u];
    a[cnt].w=w;
    head[u]=cnt;
}
queue<int>q;
void spfa(int s)
{
    q.push(s);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n-1;i++)dis[i]=inf;
    dis[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(int i=head[u];i;i=a[i].v)
        {
            if(dis[a[i].u]>dis[u]+a[i].w)
            {
                dis[a[i].u]=dis[u]+a[i].w;
                if(!vis[a[i].u])
                {
                    vis[a[i].u]=1;
                    q.push(a[i].u);
                }
            }
        }
    }
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    cin>>n>>m;
    int a,b,c;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
      spfa(i);
      for(int j=1;j<=n-1;j++)
    {
        sum=max(sum,dis[j]);
    }
    }
    cout<<sum;
    return 0;
}
