#include <bits/stdc++.h>
using namespace std;
int read()
{
	int sum=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch<='9'&&ch>='0'){sum=sum*10+ch-'0';ch=getchar();}
	return sum;
}
const int N = 5e4+10;
const int M = N*2+10;
int head[N],net[M],to[M],wi[M],ecnt=1;
void add(int x,int y,int z)
{
	net[++ecnt]=head[x],head[x]=ecnt,to[ecnt]=y,wi[ecnt]=z;
}
int n,m;
int dp[N],fa[N],ans;
void dfs1(int x)
{
	int ma=0,mi=0;
	for(int e=head[x];e;e=net[e])
	{
		int v=to[e];
		if(fa[x]==v)continue;
		fa[v]=x;
		dfs1(v);
		dp[x]=max(dp[v]+wi[e],dp[x]);
		if(dp[v]+wi[e]>=ma){mi=ma;ma=dp[v]+wi[e];}
		else if(dp[v]+wi[e]>mi){mi=dp[v]+wi[e];}
	}
	ans=max(dp[x],ans);
	ans=max(ans,ma+mi);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();int ma=1e9+7;
	for(int i=1;i<n;i++)
	{
		int ju1=read(),ju2=read(),ju3=read();
		add(ju1,ju2,ju3);add(ju2,ju1,ju3);
		ma=min(ma,ju3);
	}
	if(m==n-1) cout<<ma;
	else if(m==1)
	{
		dfs1(1);
		printf("%d\n",ans);
	}
	return 0;
}
