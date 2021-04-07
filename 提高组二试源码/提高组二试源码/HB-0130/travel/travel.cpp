#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define N 10005
using namespace std;
int n,m,x,y,z,head[N],tot,ans[N],mp[5002][5002],cnt[5002],dfn[5002],low[5002],vis[5002],idx,hav[5002],fir,sa,sb,flag;
stack < int > st;

void dfs(int u,int fa)
{
	ans[++ans[0]]=u;
	for(int i=1; i<=n; i++)
	{
		if(mp[u][i]==0) continue;
		int nex=i;
		if(nex==fa) continue;
		dfs(nex,u);
	}
}

void Dfs(int u,int fa)
{
	dfn[u]=low[u]=++idx;
	vis[u]=1;
	st.push(u);
	for(int i=1; i<=n; i++)
	{
		if(mp[u][i]==0) continue;
		int nex=i;
		if(nex==fa) continue;
		if(!dfn[nex])
		{
			Dfs(nex,u);
			low[u]=min(low[u],low[nex]);
		}
		else if(vis[nex])
			low[u]=min(low[u],dfn[nex]);
	}
	if(dfn[u]==low[u])
	{
		int now=0;
		if(st.top()==u)
		{
			st.pop();
			return ;
		}
		while(!st.empty())
		{
			now=st.top();
			st.pop();
			vis[now]=0;
			hav[now]=1;
			if(now==u) break;
		}
	}
}

void DFS(int u,int fa)
{
	ans[++ans[0]]=u;
	for(int i=1; i<=n; i++)
	{
		if(mp[u][i]==0) continue;
		int nex=i;
		if(flag==nex) continue;
		if(hav[nex]==1)
		{
			if(fir==0)
			{
				fir=nex;
				for(int j=1; j<=n; j++)
				{
					if(mp[fir][j]==1)
					{
						if(sa==0) sa=j;
						else sb=j;
					}
				}
			}
			else if(nex==fir) continue;
			else if(nex>sb && flag==0)
			{
				flag=u;
				continue;
			}
		}
		if(nex==fa) continue;
		DFS(nex,u);
	}
}

void print()
{
	for(int i=1; i<=ans[0]; i++)
	{
		if(i!=ans[0]) printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		mp[x][y]=1;
		mp[y][x]=1;
	}
	if(m==n-1)
	{
		dfs(1,0);
		print();
	}
	else
	{
		for(int i=1; i<=n; i++)
			if(!dfn[i]) Dfs(i,0);
		DFS(1,0);
		print();
	}
	return 0;
}

/*
6 5
1 3
2 3
2 5
3 4
4 6

6 6
1 3
2 3
2 5
3 4
4 5
4 6

*/

