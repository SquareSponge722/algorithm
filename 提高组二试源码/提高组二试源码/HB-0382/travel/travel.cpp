#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=5010;

void dfs(int u);

int n,m,cut,a[N][N],tot,e[N][2];
bool vis[N],used[N];
vector<int> g[N];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int i,j,u,v,minn;
	
	scanf("%d%d",&n,&m);
	
	for (i=0;i<m;++i)
	{
		scanf("%d%d",&u,&v);
		e[i][0]=u;
		e[i][1]=v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (i=1;i<=n;++i)
	{
		sort(g[i].begin(),g[i].end());
	}
	
	if (n==m)
	{
		for (cut=0;cut<m;++cut)
		{
			memset(vis,false,sizeof(vis));
			tot=0;
			dfs(1);
			if (tot<n)
			{
				used[cut]=true;
			}
		}
		for (i=1;i<=n;++i)
		{
			minn=n;
			for (j=0;j<m;++j)
			{
				if (!used[j]&&a[j][i]<minn)
				{
					minn=a[j][i];
				}
			}
			for (j=0;j<m;++j)
			{
				if (a[j][i]>minn)
				{
					used[j]=true;
				}
			}
			printf("%d",minn);
			if (i<n)
			{
				putchar(' ');
			}
		}
	}
	
	else
	{
		cut=m;
		dfs(1);
		for (i=1;i<=n;++i)
		{
			printf("%d",a[m][i]);
			if (i<n)
			{
				putchar(' ');
			}
		}
	}
	
	return 0;
}

void dfs(int u)
{
	if (vis[u])
	{
		return;
	}
	vis[u]=true;
	a[cut][++tot]=u;
	int v,i;
	for (i=0;i<g[u].size();++i)
	{
		v=g[u][i];
		if ((u!=e[cut][0]||v!=e[cut][1])&&(u!=e[cut][1]||v!=e[cut][0]))
		{
			dfs(v);
		}
	}
}
