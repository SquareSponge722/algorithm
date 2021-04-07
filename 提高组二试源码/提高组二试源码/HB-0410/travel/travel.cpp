#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e3+55;
int head[maxn<<1],to[maxn<<1],nxt[maxn<<1],tot,a,b,num[maxn];
bool vis[maxn<<1];
int map[5055][5055];
bool cmp(int a,int b)
{
	return a>b;
}
inline void add(int u,int v)
{
	tot++;
	nxt[tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
inline void dfs(int u)
{
	printf("%d ",u);
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i])
	{
		if(!vis[to[i]]) {
			dfs(to[i]);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][++num[a]]=b;
		map[b][++num[b]]=a;
	}
	for(int i=1;i<=n;i++)
	sort(map[i]+1,map[i]+1+num[i],cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=num[i];j++)
			add(i,map[i][j]);
	dfs(1);
	return 0;
	
}
