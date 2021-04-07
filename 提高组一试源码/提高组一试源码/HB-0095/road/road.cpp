#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;
int n,d[100005],minn=20000,sum,k,flag;
void dfs(int x,int y)
{
	if(x>y) return;
	if(x==y&&y==n) flag=1;
	for(int i=x;i<=y;i++)
	{
		if(d[i]<minn) minn=d[i];
	}
	for(int i=x;i<=y;i++) d[i]-=minn;
	sum+=minn;
	minn=20000;
	int k=x;
	for(int i=x;i<=y+1;i++)
	{
		if((d[i]==0||i==n+1)&&flag==0)
		{
			dfs(k,i-1);
			k=i+1;
		}
	}
	return;
}
int main() 
{
	freopen("road.in",r,"stdin")
	freopen("road.out",w,"stdout")
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&d[i]);
	}
	dfs(1,n);
	cout<<sum<<endl;
	return 0;
}
