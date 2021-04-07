#include<cstdio>
#include<iostream>
#include<queue>
#define maxn 5010
#define WQD 0x7f7f7f7f
using namespace std;
int book[maxn],que[maxn],in[maxn]={-1},head[maxn],_head=1,tail;
struct Edge{
	int next,to;
}e[maxn<<1];
void dfs(int u)
{
	priority_queue<int>q;
	book[u]=1;que[++tail]=u;
	//int pos=WQD;
	for(int i=head[u];i;i=e[i].next )
	{
		int v=e[i].to ;
		if(book[v]) continue;
		else q.push(-v);
		//pos=min(v,pos);
	}
	//if(pos==23||pos==63||pos==77|pos==90) ;
	//if(pos<WQD) dfs(pos);
	/*for(int i=head[u];i;i=e[i].next )
	{
		int v=e[i].to;
		if(book[v]) continue;
		dfs(v);
	}*/
	while(q.size() )
	{
		int v=q.top() ;q.pop() ;
		dfs(-v);
	}
}
void dfs2(int u)
{
	priority_queue<int>q;
	book[u]=1;que[++tail]=u;
	for(int i=head[u];i;i=e[i].next )
	{
		int v=e[i].to ;
		if(book[v]||(in[v]&&v>e[head[v]].to )) continue;
		else q.push(-v);
	}
	while(q.size() )
	{
		int v=q.top() ;q.pop() ;
		dfs(-v);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	if(m==n-1)
	{
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&u,&v);
			e[i]=(Edge){head[u],v};head[u]=i;
			e[i+n]=(Edge){head[v],u};head[v]=i+n;
		}
		dfs(1);
		for(int i=1;i<=n;++i) printf("%d ",que[i]);
	}
	else if(m==n)
	{
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&u,&v);
			e[i]=(Edge){head[u],v};head[u]=i;
			e[i+n+1]=(Edge){head[v],u};head[v]=i+n+1;
			++in[u],++in[v];
		}
		dfs2(1);
		for(int i=1;i<=n;++i) printf("%d ",que[i]);
	}
	return 0;
}
