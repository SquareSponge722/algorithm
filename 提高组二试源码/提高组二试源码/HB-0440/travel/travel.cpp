#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=5005;
struct edge
{
	int v,next;
} e[maxn*2];
int head[maxn],tot;
void edd(int u,int v)
{
	tot++;
	e[tot].v=v,e[tot].next=head[u];
	head[u]=tot;
}
int fa[maxn],dt[maxn],son[maxn],vis[maxn];
int n,m;
void dfs(int u)
{
	printf("%d ",u);
	vis[u]=1;
	priority_queue<int,vector<int>,greater<int> > Q;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			Q.push(v);
		}
	}
	while(!Q.empty())
	{
		int v=Q.top();
		Q.pop();
		dfs(v);
	}
}
void bfs()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].v;
			if(!vis[v])
			{
				if(!fa[v])fa[v]=u;
				else fa[v]=max(fa[v],u);
				q.push(v);
			}
		}
	}
}
void dfs2(int u)
{
	printf("%d ",u);
	vis[u]=1;
	priority_queue<int,vector<int>,greater<int> > Q;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].v;
		if(!vis[v]&&fa[v]==u)
		{
			Q.push(v);
		}
	}
	while(!Q.empty())
	{
		int v=Q.top();
		Q.pop();
		dfs2(v);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==n-1)
	{
		for(int i=1; i<=m; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			edd(x,y);
			edd(y,x);
		}
		dfs(1);
	}
	else if(m==n)
	{
		for(int i=1; i<=m; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			edd(x,y);
			edd(y,x);
		}
		bfs();
		memset(vis,0,sizeof(vis));
		dfs2(1);
	}
	return 0;
}
