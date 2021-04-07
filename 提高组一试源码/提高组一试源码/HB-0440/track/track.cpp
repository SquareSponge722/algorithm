#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=50005;
struct edge{
	int v,w,next;
}e[maxn*2];
int head[maxn],tot,deg[maxn];
int n,m;
void edd(int u,int v,int w)
{
	tot++;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}
int dp[maxn],vis[maxn];
int Dp(int u)
{
	vis[u]=1;
	int tmp=0,pos=0;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			val=Dp(v);
			if(val>tmp)
			{
				tmp=val;
				pos=v;
			}
		}
	}
	dp[u]=tmp+e[i].w;
	return dp[u];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		edd(x,y,z);
		edd(y,x,z);
		deg[x]++;
		deg[y]++;
	}
	if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(ffind(i)==i&&deg[i]==1)
			{
				memset(vis,0,sizeof(vis));
				memset(dp,0,sizeof(dp));
				int val=Dp(i);
				ans=max(ans,val);
			}
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
