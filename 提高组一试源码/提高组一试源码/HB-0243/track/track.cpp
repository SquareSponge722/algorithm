#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
const int mm=50050;
struct node{
int u;
int v;
int w;
};
vector<node>mat[mm];
queue<int>q;
int n,m;
int a[mm];
/*int dp(int pos,int las)
{
    if(pos==n-1&&las>0)return 0;
    if()
}*/
int vis[mm];
int dis[mm];
int maxx=0;
int anss=0;
void dfs(int p,int l,int le)
{
    if(p==n&&l!=0)return;
    if(p==n){anss=max(le,anss);
    return;}
    for(int i=p+1;i<=n-l+1;i++)
    {
        int ttt=0;
        for(int j=p;j<=i;j++)
            ttt+=a[i];
        dfs(i,l-1,min(le,ttt));
    }
}
/*int dfs(int pos)
{
    int ans=0;
    for(int i=0;i<mat[pos].size();i++)
    {
        int v;
        int w=mat[pos][i].w;
        if(mat[pos][i].u==pos)v=mat[pos][i].v;
        else
            v=mat[pos][i].u;
            if(vis[v]==1)
                continue;
            vis[v]=1;
        ans=max(maxx,dfs(v)+w);
        vis[v]=0;
    }
}*/
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    cin>>n>>m;
    int flag=1;
    for(int i=1;i<=n-1;i++)
    {
        node temp;
        cin>>temp.u>>temp.v>>temp.w;
        mat[temp.u].push_back(temp);
        mat[temp.v].push_back(temp);
        if(int(abs(temp.u-temp.v))!=1)flag=-1;
    }
    if(m==1)
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            if(mat[i].size()>2)continue;
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            dis[i]=0;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                //cout<<u<<endl;
                q.pop();
                vis[u]=0;
                for(int j=0;j<mat[u].size();j++)
                {
                    int v;
                    int w=mat[u][j].w;
                    if(mat[u][j].u==u)v=mat[u][j].v;
                    else
                        v=mat[u][j].u;
                        if(dis[u]+w<dis[v])
                    {dis[v]=dis[u]+w;
                    if(vis[v]==0)
                    {
                        q.push(v);
                        vis[v]=1;
                    }
                    }
                }
            }
            //cout<<maxx<<endl;
            int tm=0;
            for(int po=1;po<=n;po++)
                if(dis[po]>tm)tm=dis[po];
            maxx=max(maxx,tm);
        }
        cout<<maxx;
        /*int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            int qq=dfs(i);
            if(qq>ans)ans=qq;
        }
        cout<<ans;*/
        return 0;
    }
    else if(flag==1)
    {
        for(int i=1;i<=n-1;i++)
        {
                if(mat[i][0].u==i+1)a[i]=mat[i][0].w;
                if(mat[i][0].u==i+1)a[i]=mat[i][0].w;
                if(mat[i][1].v==i+1)a[i]=mat[i][1].w;
                if(mat[i][1].v==i+1)a[i]=mat[i][1].w;
                //for(int i=1;i<=n;)
        }
dfs(1,m,1000000);
cout<<anss;
    }
    return 0;

}
