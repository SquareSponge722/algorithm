#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define N 20000
#define M 1000000007
using namespace std;

int n,m;
int ans;
int a[N],b[N],c[N];
bool check()
{
	for(int i=1;i<=m-1;i++)
		if(b[i]<a[i])
		return false;
	for(int i=1;i<m-1;i++)
	{
		if(b[i]>b[i+1]||a[i]>a[i+1])
		return false;
	}
	return true;
}
bool check_()
{
	for(int i=1;i<=m-1;i++)
		if(b[i]<a[i]||c[i]<b[i])
		return false;
	for(int i=1;i<m-1;i++)
	{
		if(b[i]>b[i+1])
		return false;
	}
	return true;
}
void dfs(int x)
{
	if(x==m)
	{
		if(check())
		ans=(ans+1)%M;
	}
	else
	{
		for(int i=0;i<=1;i++)
		{
			a[x]=i;
			for(int j=0;j<=1;j++)
			{
				b[x]=j;
				dfs(x+1);
			}
		}
	}
}
void dfs_(int x)
{
	if(x==m)
	{
		if(check_())
			ans=(ans+1)%M;
	}
	else
	{
		for(int i=0;i<=1;i++)
		{
			a[x]=i;
			for(int j=0;j<=1;j++)
			{
				b[x]=j;
				for(int k=0;k<=1;k++)
				{
					c[x]=k;
					dfs_(x+1);
				}
			}
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2)
		dfs(1);
	else
		dfs_(1);
	cout<<(ans*4)%M; 
}
