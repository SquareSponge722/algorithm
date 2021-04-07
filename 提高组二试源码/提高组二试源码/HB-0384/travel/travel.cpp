#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mlr ll mid((l+r)>>1)
using namespace std;
int cnt(0);
int x,y;
int n,m;
int d[5050];
int head[5050];
priority_queue<int> q[5050];
int maxd(0);
int ans[5050];
int cal(0);
int vis[5050];
int tot(0);
struct edge
{
	int to,next;
}a[100010];
void addedge(int xi,int yi)
{
	a[cnt].to=yi;
	a[cnt].next=head[xi];
	head[xi]=cnt++;
}
void dfs1(int v,int fa)
{
	q[fa].push(-v);
	for(int i=head[v];i!=-1;i=a[i].next)
	{
		int u=a[i].to;
		if(u!=fa)dfs1(u,v);
	}
}
void dfs2(int v)
{
	while(!q[v].empty())
	{
		int u=-(q[v].top());
		q[v].pop();
		ans[++cal]=u;
		dfs2(u);
	}
}
void dfs3(int v,int fa)
{
	d[v]=d[fa]+1;
	vis[fa]=1;
	maxd=max(d[v],maxd);
	q[d[v]].push(v);
	for(int i=head[v];i!=-1;i=a[i].next)
	{
		int u=a[i].to;
		if(!vis[u])dfs3(u,v);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	if(n==m+1)
	{
		dfs1(1,0);
		dfs2(0);
		for(int i=1;i<=cal;i++)printf("%d ",ans[i]);
	}
	else
	{
		d[1]=0;
		dfs3(1,0);
		for(int i=1;i<=maxd;i++)
		{
			while(!q[i].empty())
			{
				int k=q[i].top();
				q[i].pop();
				tot++;
				if(tot<=n)printf("%d ",k);
			}
		}
	}
	return 0;
}