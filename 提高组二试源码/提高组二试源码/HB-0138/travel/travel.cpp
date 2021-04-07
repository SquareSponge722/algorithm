#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;
const int MAXN=5005;
int n,m;
vector<int>G[MAXN];
int read()
{
    int re=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return re;
}
namespace Tree
{
    void dfs(int now,int fa)
    {
        printf("%d ",now);
        for(int i=0;i<G[now].size();i++)
            if(G[now][i]!=fa) dfs(G[now][i],now);
    }
    void mian()
    {
        dfs(1,0);
    }
}
namespace Circle
{
    bool vis[MAXN];
    void dfs(int now)
    {
        vis[now]=true;
        printf("%d ",now);
        for(int i=0;i<G[now].size();i++)
            if(!vis[G[now][i]]) dfs(G[now][i]);
    }
    void mian()
    {
        dfs(1);
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    n=read(),m=read();
    for(int i=0;i<m;i++)
    {
        int x=read(),y=read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    if(m==n-1) Tree::mian();
    else if(m==n) Circle::mian();
    return 0;
}
