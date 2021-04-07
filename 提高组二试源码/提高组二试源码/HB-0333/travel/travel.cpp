//无重边，自环，图连通
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<vector>
#include<algorithm>
#define re register
#define IN inline
using namespace std;
const int N=5005;
int n,m;
bool vis[N];
vector<int>G[N];
vector<int>Ans;

IN int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}
    while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    while(ch>='0'&&ch<='9');
    return f*x;
}

void dfs(int u)
{
    Ans.push_back(u);vis[u]=1;
    int size=G[u].size();
    for(int i=0;i<size;++i)
    {
        int v=G[u][i];
        if(vis[v])continue;
        dfs(v);
    }
}

IN void workTree()
{
    for(int i=1;i<=n;i++)
        sort(G[i].begin(),G[i].end());
    //Ans.push_back(1);
    dfs(1);
    int size=Ans.size();
    for(int i=0;i<size;i++)
        cout<<Ans[i]<<" ";
    cout<<"\n";
    exit(0);
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    n=read(),m=read();
    for(re int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(m==n-1)
        workTree();

    return 0;
}

