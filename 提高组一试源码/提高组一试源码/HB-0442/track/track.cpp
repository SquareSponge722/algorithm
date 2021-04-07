#include<iostream>
#include<cstdio>
using namespace std;
const int mn=50005;
int n,m,num=1,flag,cnt,flag0;
int h[mn],vis[mn];
int en,ansmax;
int r[1000*1000+5];
bool dis[1005][1005];
struct edge
{
    int u,v,w;
    int nxt;
}e[mn];
void addeg(int u,int v,int w)
{
    e[num].u=u;
    e[num].v=v;
    e[num].w=w;
    e[num].nxt=h[u];
    h[u]=num;
    num++;
    return;
}
void getlen(int u,int ans,int s,int t)
{
    if(u==t)
    {
        ansmax=max(ansmax,ans);
        if(flag==0)
        {
            if(dis[s][t]==0)
            {
                r[cnt++]=ans;
                dis[s][t]=dis[t][s]=1;
            }
            flag=1;
        }
        return;
    }
    for(int i=h[u];i>=0;i=e[i].nxt)
    {
        int v=e[i].v;
        if(vis[v]==0)
        {
            vis[v]=1;
            getlen(v,ans+e[i].w,s,t);
            vis[v]=0;
        }
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
bool isbig(int mid)
{
    int num=0;
    for(int i=1;i<=cnt;i++)
    {
        if(r[i]>=mid)num++;
        if(num>m)return false;
    }
    return true;
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)h[i]=-1;
    for(int i=1;i<=n-1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addeg(u,v,w);addeg(v,u,w);
        dis[u][v]=dis[v][u]=w;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    vis[i]=1;
                    getlen(i,0,i,j);
                    vis[i]=0;
                }
            }
        }
        cout<<ansmax;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    flag=0;
                    vis[i]=1;
                    getlen(i,0,i,j);
                    vis[i]=0;
                }
            }
        }
        sort(r+1,r+cnt,cmp);cnt--;
        int x=0,y=r[1];
        while(x<y)
        {
            int mid=x+y>>1;
            if(isbig(mid))y=mid;
            else x=mid+1;
        }
        cout<<x;
    }
    return 0;
}
