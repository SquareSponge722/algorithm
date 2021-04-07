#include<bits/stdc++.h>
#define N 5010
using namespace std;
int sum=0;
int ans[N];
int m,n;
int g[N][N];
void init()
{
	memset(g,-1,sizeof(g));
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
}
bool flag[N];
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	for(int i=1; i<=n; i++)
	{
		int minn=0x3f;
		for(int j=1; j<=n; j++)
			if(g[i][j]&&!flag[j]&&j<minn)
					ans[++sum]=j;
	}
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	return 0;
}
