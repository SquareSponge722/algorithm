#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mx=5010;
int n,m;
bool vis[mx];
int lu[mx][mx],dian[mx],p[mx];///dian每个点最多能到几个点
int i,j,s[mx],mina,sum,tot;///mina[]/cnt记录可以到达的最小的点
bool cmp(const int &x,const int &y)
{
    return x<y;
}
void zxy(int v,int nn)///v当前节点
{
    mina=99999;
    for (i=1; i<=tot; i++)
    {
        int u=p[i];
        for (j=1; j<=dian[u]; j++)
        {
            if (!vis[lu[u][j]])
                mina=min(mina,lu[u][j]);
        }
    }
    vis[mina]=true;
    sum++;
    s[sum]=mina;
    tot++;
    p[tot]=mina;
    if (nn>=n) return ;
    else zxy(mina,nn+1);
}
void dfs(int v)
{
    int mina=99999,tot=0,pp[mx];
    for (i=1;i<=dian[v];i++)
    {
        if (!vis[lu[v][i]])
        {
            tot++;
            pp[tot]=lu[v][i];
        }
    }
    if (tot==0) return;
    sort(pp+1,pp+tot+1,cmp);
    for (int k=1;k<=tot;k++)
    {
        vis[pp[k]]=true;///cout<<pp[i]<<endl;
        sum++;
        s[sum]=pp[k];
        dfs(pp[k]);
    }
    return;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for (i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        dian[x]++,dian[y]++;
        lu[x][dian[x]]=y,lu[y][dian[y]]=x;
    }
    ///从1号点出发
    if (m==n)
    {
        s[1]=1,sum=1,vis[1]=true,tot=1,p[1]=1;
        zxy(1,1);
    }
    else if (m==n-1)
    {
        sum=1,s[1]=1,vis[1]=true;
        dfs(1);
    }
    for (i=1; i<=n; i++) cout<<s[i]<<" ";
    return 0;
}
