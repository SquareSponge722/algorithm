#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
vector<int> e[100001];
long long dp[100001][2];
int vis[100001];
long long p[100001];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(!vis[to])
		{
			dfs(to);
			dp[u][1]+=min(dp[to][1],dp[to][0]);
			dp[u][0]+=dp[to][1];
		}
	}
	dp[u][1]+=p[u];
}
int fa[100001];
void dfs2(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(!fa[to])
		{
			fa[to]=u;
			dfs2(to);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	fa[1]=-1;
	dfs2(1);
	for(int i=1;i<=m;i++)
	{
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int x,y,r,s;
		scanf("%d%d%d%d",&x,&y,&r,&s);
		if(y==0&&s==0&&(fa[x]==r||fa[r]==x))
		{
			printf("-1\n");
			continue;
		}
		long long t1=p[x],t2=p[r];
		if(y==0)
			p[x]+=999999999999ll;
		else
			p[x]-=999999999999ll;
		if(s==0)
			p[r]+=999999999999ll;
		else
			p[r]-=999999999999ll;
		dfs(1);
		long long ans=min(dp[1][0],dp[1][1]);
		while(ans<0)
			ans+=999999999999ll;
		printf("%lld\n",ans);
		p[x]=t1,p[r]=t2;
	}
	return 0;
}
