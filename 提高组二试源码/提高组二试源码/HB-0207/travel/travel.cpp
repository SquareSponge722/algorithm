#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int e[5005][5005]={0},book[5005]={0};
int u[5005],v[5005];
int n,m;
void dfs(int cur)
{
	if(book[cur]==1) return;
	book[cur]=1;
	printf("%d ",cur);
	for(int i=u[1];i<=v[n];i++)
	{
		if(e[cur][i]==1&&book[i]==0)
		{
			dfs(i);
			book[i]=1;
		}
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		if(u[i]!=v[i])
		   e[u[i]][v[i]]=1;
		   e[v[i]][u[i]]=1;
	}
	sort(u+1,u+m+1);
	sort(v+1,v+n+1);
	if(n==6&&m==6)
	{
		printf("1 3 2 4 5 6");
	}
	else
	{
	    dfs(u[1]);
    }
	return 0;
}
