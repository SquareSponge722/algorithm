#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool ma[5020][5020];
int vi[5020];
bool c[5020];
int a[5000000];
int n,m,flagi=2;
int fi=1;
int dfs(int t,int x,int sum)
{
	if(ma[t][x])
	{
	vi[x]=t;
	a[sum]=x;
	memset(c,0,sizeof(c));
	int s;
	for(int i=1;i<=n;i++)
	if(!vi[i]&&i!=1)
	{
	s=dfs(x,i,sum+1);
	if(s) return x;
	}
	}
	else
	{
		if(!c[vi[t]]&&t!=1)
		{
		c[vi[t]]=1;
		dfs(vi[t],x,sum);
		c[vi[t]]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ma[x][y]=ma[y][x]=1;
	}
	int x;
	a[1]=1;
	for(int i=1;i<=n;i++)
	if(dfs(1,i,2)) break;
	int sum=0;
	for(int i=1;sum<n;i++)
	if(a[i])
	{
		cout<<a[i]<<" ";
		sum++;
	}
	return 0;
}
