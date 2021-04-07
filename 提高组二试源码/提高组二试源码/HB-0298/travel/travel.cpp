#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int N=5005;
int n,m,s=999999999,visit[N],tot,ans[N],fa[N],du[N];
vector < int > g[N];
bool check(int x,int num)
{
	for(int i=0; i<g[x].size(); i++)
	{
		int temp=g[x][i];
		if(!visit[temp])
		{
			if(temp<num)
				return true;
		}
	}
	return false;
}
bool c()
{
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
			return false;
	}
	return true;
}
void dfs1(int x,int fff)
{
	if(c())
	{
		/*for(int i=1; i<=tot; i++)
		{
			printf("%d ",ans[i]);
		}*/
		exit(0);
	}
	for(int i=0; i<g[x].size(); i++)
	{
		if(fff==-1)
		{
			int temp=g[x][i];
			ans[++tot]=temp;
			visit[temp]=true;
			du[temp]--;
			//fa[temp]=x;
			printf("%d ",temp);
			dfs1(temp,x);
		}
		else
		{
			int temp=g[x][i];
			if(temp==fff)
				continue;
			if(!visit[temp] && check(fff,temp) && du[temp]!=1)
			{
				return ;
			}
			else
			{
				if(!visit[temp])
				{
					ans[++tot]=temp;
					visit[temp]=true;
					//fa[temp]=x;
					printf("%d ",temp);
					dfs1(temp,x);
				}
			}
		}
	}
}
void dfs2(int x,int fff)
{
	if(c())
	{
		/*for(int i=1; i<=tot; i++)
		{
			printf("%d ",ans[i]);
		}*/
		exit(0);
	}
	for(int i=0; i<g[x].size(); i++)
	{
		if(fff==-1)
		{
			int temp=g[x][i];
			ans[++tot]=temp;
			visit[temp]=true;
			du[x]--;
			//fa[temp]=x;
			printf("%d ",temp);
			dfs2(temp,x);
		}
		else
		{
			int temp=g[x][i];
			if(temp==fff)
				continue;
			du[x]--;
			if(!visit[temp] && check(fff,temp) && du[x]!=1)
			{
				return ;
			}
			else
			{
				if(!visit[temp])
				{
					ans[++tot]=temp;
					visit[temp]=true;
					//fa[temp]=x;
					printf("%d ",temp);
					dfs2(temp,x);
				}
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		du[x]++;
		du[y]++;
		g[x].push_back(y);
		g[y].push_back(x);
		s=min(s,min(x,y));
	}
	for(int i=1; i<=n; i++)
		sort(g[i].begin(),g[i].end());
	visit[s]=true;
	ans[++tot]=s;
	printf("%d ",s);
	if(n==m)
	{
		dfs1(s,-1);
	}
	else
	{
		dfs2(s,-1);
	}
	return 0;
}
