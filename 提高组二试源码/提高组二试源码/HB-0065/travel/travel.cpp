#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 5010
using namespace std;
int n,m,t=0;
int a[N][N];
int vis[N];
int d[N];
void dfs(int x){
	if(t>=n) return ;
	vis[x]=1;
	d[++t]=x;
	for(int i=1;i<=n;i++)
		if(!vis[i] && a[x][i])
			dfs(i);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	for(int i=1;i<=t;i++)
		printf("%d ",d[i]);
	return 0;
}
