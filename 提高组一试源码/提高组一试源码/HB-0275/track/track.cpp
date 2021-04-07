#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
inline int read()
{
	int k=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';return f*k;
}
const int N=200055;
int n,m,de[N];
int tot,to[N],nextt[N],head[N],w[N];
int f[N],g[N],as,dp[N][2];
void add(int a,int b,int c)
{
	to[++tot]=b;
	nextt[tot]=head[a];
	head[a]=tot;
	w[tot]=c;
}
void dfs(int u,int fa)
{	
	for(int i=head[u];i;i=nextt[i])
		if(to[i]!=fa)
		{
			dfs(to[i],u);
			as=max(as,f[u]+w[i]+f[to[i]]);
			f[u]=max(f[u],f[to[i]]+w[i]);
		}
}
int check(int x)
{
	int sum=0,now=0;
	for(int i=1;i<n;i++)
	{
		for(int j=head[i];j;j=nextt[j])
		{
			if(to[j]==i+1)
				now+=w[j];
		}
		if(now>=x) sum++,now=0;
	}
	return sum>=m;
}
void dfs2(int u,int fa,int x)
{
	int a=0,b=0,c=0,d=0;
	for(int i=head[u];i;i=nextt[i])
		if(to[i]!=fa)
		{
			dfs2(to[i],u,x);
			if(!a) a=to[i],c=w[i];
			else b=to[i],d=w[i];
		}
	if(!b)
	{
		if(dp[a][1]+c>=x)
			dp[u][0]=dp[a][0]+1,dp[u][1]=0;
		else dp[u][0]=dp[a][0],dp[u][1]=dp[a][1]+c;
	}		
	else 
	{
		if(dp[a][1]+c>=x&&dp[b][1]+d>=x)
		{
			dp[u][0]=dp[a][0]+dp[b][0]+2,dp[u][1]=0;
		}
		else 
		{
			if(dp[a][1]+c>=x)
				dp[u][0]=dp[a][0]+dp[b][0]+1,dp[u][1]=dp[b][1]+d;
			else if(dp[b][1]+d>=x)
				dp[u][0]=dp[a][0]+dp[b][0]+1,dp[u][1]=dp[a][1]+c;
			else if(dp[a][1]+c+dp[b][1]+d>=x)
			{
				dp[u][0]=dp[a][0]+dp[b][0]+1;dp[u][1]=0;
			}
			else dp[u][0]=dp[a][0]+dp[b][0],dp[u][1]=max(dp[a][1]+c,dp[b][1]+d);
		}
	}
}		
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a,b,c,f1=1,f2=1;
	n=read();m=read();
	for(int i=1;i<n;i++)
	{
		a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
		if(a!=1) f1=0;
		if(b!=a+1) f2=0;
	}
	if(m==1)
	{
		dfs(1,0);printf("%d\n",as);return 0;
	}
	if(f1)
	{
		int cnt=0;as=2e9;
		for(int i=head[1];i;i=nextt[i])	
			de[++cnt]=w[i];
		sort(de+1,de+n);
		for(int i=1;i<=m;i++)
		{
			as=min(as,de[n-i]+de[max(0,n-1-2*m+i)]);
		}
		printf("%d\n",as);return 0;
	}
	if(f2)
	{
		int l=0,r=2e9,mid;
		while(r>=l)
		{
			mid=l+r>>1;
			if(check(mid)) as=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",as);
		return 0;
	}
	int l=0,r=2e9,mid;
	while(r>=l)
	{
		mid=l+r>>1;
		for(int i=1;i<=n;i++)
			dp[i][0]=dp[i][1]=0;
		dfs2(1,0,mid);
		if(dp[1][0]>=m) as=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",as);
	return 0;
}
/*
7 2
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
