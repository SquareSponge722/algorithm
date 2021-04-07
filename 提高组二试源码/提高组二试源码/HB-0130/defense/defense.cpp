#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#define N 1000010
#define mod 1000000007
using namespace std;
struct edge
{
	int to,nxt;
} e[N];
int n,m,du[N],x,y,z,p,dp[N][2],val[N],f[N][2],tot,head[N];
char ch[100];

void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}

void DP(int l,int r,int flag)
{
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	if(flag==0)
	{
		for(int i=1;i<=r-l+1;i++)
		{
			int now=i+l-1;
			f[i][1]=min(f[i-1][1],f[i-1][0])+val[now];
			f[i][0]=f[i-1][1];
		}
		for(int i=1;i<=r-l+1;i++)
		{
			dp[i+l-1][1]=f[i][1];
			dp[i+l-1][0]=f[i][0];
		}
	}
	else
	{
		for(int i=1;i<=r-l+1;i++)
		{
			int now=n-i+1;
			f[i][1]=min(f[i-1][1],f[i-1][0])+val[now];
			f[i][0]=f[i-1][1];
		}
		for(int i=1;i<=r-l+1;i++)
		{
			dp[n-i+1][1]=f[i][1];
			dp[n-i+1][0]=f[i][0];
		}
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,ch);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dp[0][1]=999999999;
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		scanf("%d %d %d %d",&x,&y,&z,&p);
		if(x==z+1 || z==x+1)
		{
			if(y==0 && p==0)
			{
				printf("-1\n");
				continue;
			}
		}
		if(y==1)
			ans+=val[x];
		if(p==1)
			ans+=val[z];
		if(x>1)
		{
			DP(1,x-1,0);
			if(y==1 || p==1) ans+=min(dp[x-1][1],min(dp[x-1][0],dp[x-2][1]));
			else ans+=dp[x-1][1];	
		}	
		if(z<n)
		{
			DP(y+1,n,1);
			if(p==1 || y==1) ans+=min(dp[y+1][1],min(dp[y+1][0],dp[y+2][1]));
			else ans+=dp[y+1][1];
		}
		printf("%d\n",ans);
	}
	return 0;
}
