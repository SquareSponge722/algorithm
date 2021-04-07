#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> q;
const int mn = 5005;
vector<int> ve[mn];
int n,m,st[mn],top,aft[mn],fa[mn];
bool vis[mn],tag[mn],trs[mn],ino[mn];
void dfs_pre(int x)
{
	int tmp=ve[x].size();
	for(int i=0;i<tmp;i++)
	{
		int v=ve[x][i];
		if(tag[v]) continue;
		fa[v]=x;
		dfs_pre(v);
	}
}
void find_cyc(int x)
{
	int y=x;
	while(!vis[y])
	{
		vis[y]=1;
		y=aft[y];
	}
	int st=y;
	tag[st]=1;
	y=aft[st];
	while(y!=st)
	{
		tag[y]=1;
		y=aft[y];
	}
	y=aft[st];
	dfs_pre(st);
	while(y!=st)
	{
		dfs_pre(y);
		y=aft[y];
	}
}
void dfs(int x,int ff)
{
	st[++top]=x;
	int tmp=ve[x].size();
	for(int i=0;i<tmp;i++)
	{
		if(ve[x][i]!=ff)
		{
			dfs(ve[x][i],x);
		}
	}
}
void dfs_r(int x);
void dfs_c(int flag)
{
	if(q.empty()) return ;
	int u=-q.top();
	q.pop();
	if(!tag[u])
	{
		dfs_r(u);
		return ;
	}
	st[++top] = u;
	trs[u]=1;
	int tmp=ve[u].size(),res=0;
	if(flag==0)
	{
		for(int i=0;i<tmp;i++)
		{
			int v=ve[u][i];
			if(trs[v]) continue;
			res = v;
			break;
		}
		if(!q.empty() && -q.top() < res)
			dfs_c(1);
		else {
			for(int i=0;i<tmp;i++)
			{
				int v=ve[u][i];
				if(trs[v]) continue;
				if(!ino[v])
				{
					ino[v]=1;
					q.push(-v);
				}
			}
			dfs_c(0);
		}
	}
	else{
		for(int i=0;i<tmp;i++)
		{
			int v=ve[u][i];
			if(trs[v]) continue;
			dfs_r(v);
		}
	}
}
void dfs_r(int x)
{
	st[++top]=x;
	trs[x]=1;
	int tmp=ve[x].size();
	for(int i=0;i<tmp;i++)
	{
		int v=ve[x][i];
		if(trs[v] || v==fa[x]) continue;
		dfs_r(v);
	}
}
void work()
{
	if(tag[1])
	{
		ino[1]=1;
		q.push(-1);
		dfs_c(0);
	}
	else {
		dfs_r(1);
		int x=fa[1];
		while(!tag[x])
		{
			dfs_r(x);
			x=fa[x];
		}
		q.push(-x);
		dfs_c(0);
	}
}
int main()
{
	int x,y;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
			sort(ve[i].begin(),ve[i].end());
		dfs(1,0);
	}
	else if(m==n)
	{
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			ve[x].push_back(y);
			ve[y].push_back(x);
			if(!aft[x]) aft[x]=y;
			else if(!aft[y]) aft[y]=x;
		}
		for(int i=1;i<=n;i++)
			sort(ve[i].begin(),ve[i].end());
		/*for(int i=1;i<=n;i++)
			if(!vis[i])
				find_cyc(i);*/	
		find_cyc(1);
		work();
	}
	for(int i=1;i<=top;i++)
		printf("%d ",st[i]);
	return 0;
}

