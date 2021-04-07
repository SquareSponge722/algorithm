#include<cstdio>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;
const int maxn=10001;
int head[maxn],cnt,vis[maxn],f[maxn];
struct node{int next,to;}edge[maxn];
int n,m,x,y;
queue<int>q;
void add(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	if(q.size()==n)return;
	if(!vis[u]){vis[u]=1;q.push(u);}
	int mina=9999999;
	for(int i=head[u];i;i=edge[i].next)
	if(!vis[edge[i].to])mina=min(mina,edge[i].to);
	if(mina==9999999)dfs(fa,f[fa]);
	else 
	{
		f[mina]=u;
		dfs(mina,f[mina]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{scanf("%d%d",&x,&y);add(x,y);add(y,x);}
	f[1]=1;
	dfs(1,f[1]);
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
	}
	return 0;
}
