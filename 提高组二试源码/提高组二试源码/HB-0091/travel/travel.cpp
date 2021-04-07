#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
bool a[1100][1100];
bool vis[1100];
int n,m,getnewpoint;
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	if(a[x][i]==1&&vis[i]==0)
	{
		vis[i]=1;
		cout<<i<<' ';
		dfs(i);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	vis[1]=1;
	cout<<1<<' ';
	dfs(1);
	return 0;
}
