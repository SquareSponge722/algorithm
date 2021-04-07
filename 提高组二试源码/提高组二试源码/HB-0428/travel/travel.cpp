#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int e[1005][1005]={0},book[6000]={0},i,j,k;
int n,m;
void dfs(int x)
{
	if(book[x]==1) return;
	book[x]=1;
	printf("%d ",x);
	for(int i=1; i<=n; i++)
	{
		if(e[x][i]==1)
		{
			dfs(i);
		}
	}
}
int main()
{
	int u,v,mmm=9999;
	scanf("%d%d",&n,&m);
	for(i=1; i<=m; i++)
	{
  		scanf("%d%d",&u,&v);
		e[u][v]=1;
		e[v][u]=1;
		if(v<mmm) mmm=v;
		if(u<mmm) mmm=u;
	}
	dfs(mmm);
	return 0;
}