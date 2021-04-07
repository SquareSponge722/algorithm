#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int dp[1001],f[1001][16];
int sum;
int rig,lef,step;
void lca()
{
	for(int i=1;i<=n;i++)
		f[i][0]=dp[i];
	for(int j=1;j<=16;j++)
	for(int i=1;i+(1<<j)<=n;i++)
	{
		f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
}
int qz(int a,int b)
{	
	int a1=max(a,b),b1=min(a,b);
	int k=log2(a1-b1+1);
	int ans=min(f[b1][k],f[a1-(1<<k)][k]);
	return ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	
		int a;
		scanf("%d",&a);
		dp[i]=a;
		sum+=a;
	}
	while(sum>0)
	{
		lca();
		for(int i=1;i<=n;i++)
		{
			if(dp[i]!=0)
			{
				lef=i;
				break;
			}
		}
		for(int i=lef;i<=n;i++)
		{
			if(dp[i]!=0)
			{
				rig=i;
			}
			else
			break;
		}
		int minm=999999;
		for(int i=lef;i<=rig;i++)
		{
			minm=min(dp[i],minm);
		}
		for(int i=lef;i<=rig;i++)
		{
			dp[i]-=minm;
		}
		step+=minm;
		sum-=(rig-lef+1)*minm;
	}
	printf("%d",step);
	return 0;
}
