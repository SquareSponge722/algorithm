#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,road[10005][10005],flag[100005],l,a[100005],k2;
void dfs(int x,int y)
{
	flag[x]=1;
	flag[y]=1;
	int ans1=0,ans2=0,k1=0,k2=0;
	for(int i=1;i<=n;i++)
	{
		if(road[x][i]&&flag[i]==0)
		{
			ans1=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(road[y][i]&&flag[i]==0)
		{
			ans2=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(road[ans2][i]&&flag[i]==0) k2=1; 
	}
	if((ans1<ans2&&ans1&&k2)||ans1>ans2&&ans2==0)
	{
		a[++l]=ans1;
		dfs(x,ans1);
	}
	else if((ans1>ans2||(ans1==0&&ans2)||k2==0)&&ans2)
	{
		a[++l]=ans2;
		dfs(y,ans2);
		a[++l]=ans1;
		dfs(x,ans1);
	}
	if(l==n)
	{
		return;
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		road[u][v]=1;
		road[v][u]=1;
	}
	a[++l]=1;
	for(int i=1;i<=n;i++)
	{
		if(road[1][i])
		{
			a[++l]=i;
			dfs(1,i);
			break;
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}
