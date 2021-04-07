#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
vector<int> e[5001];
int vis[5001],an[5001],res[5001];
int cur=0;
int bk;
void dfs(int u)
{
	an[++cur]=u;
	vis[u]++;
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(!vis[to])
			dfs(to);
	}
}
void dfs2(int u)
{
	an[++cur]=u;
	vis[u]=1;
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(!vis[to]&&to!=bk)
			dfs2(to);
		else if(!vis[to]&&to==bk)
		{
			an[++cur]=to;
			vis[to]=1;
			for(int i=0;i<e[u].size();i++)
			{
				int to=e[u][i];
				if(!vis[to]&&to!=bk)
					dfs2(to);
			}
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
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(e[i].begin(),e[i].end());
	if(m==n-1)
	{
		dfs(1);
		for(int i=1;i<=n;i++)
			printf("%d ",an[i]);
	}
	if(m==n)
	{
		memset(res,0x3f,sizeof(res));
		for(int i=1;i<=n;i++)
		{
			cur=0;
			memset(an,0x3f,sizeof(an));
			memset(vis,0,sizeof(vis));
			bk=i;
			dfs2(1);
			int fl=0;
			if(an[n]>n)
				continue;
			for(int j=1;j<=n;j++)
				if(an[j]<res[j])
				{
					fl=1;
					break;
				}
				else if(an[j]>res[j])
					break;
			if(fl)
				for(int j=1;j<=n;j++)
					res[j]=an[j];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",res[i]);
	}
	return 0;
}
