#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define N 5050
using namespace std;
int g[N][N],cut[N],tot;
bool book[N];
int ans[N];
int head[N],n,m;
void dfs(int x)
{
	book[x]=true;
	ans[++tot]=x;
	for(int i=1;i<=n;i++)
		if(i<=cut[x]&&(!book[g[x][i]])) dfs(g[x][i]);
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][++cut[u]]=v;
		g[v][++cut[v]]=u;
	}
	for(int i=1;i<=n;i++)
		sort(g[i]+1,g[i]+cut[i]+1);
	dfs(1);
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}
