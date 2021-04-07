#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define N 20000
using namespace std;

int n,m,flag[N];
int head[N],nxt[N],to[N],cnt,u;
int ans[N],s;
void init(int x,int y)
{
	++cnt;
	to[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add(int x,int y)
{
	init(x,y);
	init(y,x);
}
void dfs(int x)
{
	flag[x]=1;
	ans[++s]=x;
	int t[1000],k=0;
	for(int i=head[x];i;i=nxt[i])
		t[++k]=to[i];
	sort(t+1,t+1+k);
	for(int i=1;i<=k;i++)
	if(!flag[t[i]])
	dfs(t[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1);
	for(int i=1;i<=s;i++)
	printf("%d ",ans[i]);
}

