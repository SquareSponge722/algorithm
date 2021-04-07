#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
struct str{
	int to,next;
}e[100010];
int head[100010],book[100010],sum[100010],cnt=0;
int map[1001][1001];
void add(int u, int v)
{
	cnt++;
	e[cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int x,int r)
{
	if(book[x]==1)return;
	book[x]=1;
	printf("%d ",x);
	int que[1000],cntt=1;
	for(int i=head[x];i!=0;i=e[i].next)
	{
		if(book[e[i].to]==0){
			que[cntt]=e[i].to;
			cntt++;
		}
	}
	sort(que+1,que+cntt);
	if(que[1]>r&&sum[que[1]]>1)return;
	que[cntt]=99999;
	for(int i=1;i<cntt;i++)
	{
		dfs(que[i],que[i+1]);
	}
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
		add(u,v);add(v,u);
	//	map[u][v]=map[v][u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		if(map[i][j])
			sum[i]++;
	}
	dfs(1,9999);
}
