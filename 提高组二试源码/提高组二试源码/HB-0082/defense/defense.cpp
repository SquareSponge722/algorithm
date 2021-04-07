#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=100010;
const int maxn=100000000;
struct node
{
	int to;
	int las;
} e[N*2];
int n,m,tot,ans,cost[N],head[N],f[N],dp[N][2],d[N];
char s[2];
bool vis[N],flag;
void add(int a,int b)
{
	e[++tot].to=b;
	e[tot].las=head[a];
	head[a]=tot;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
void ddp(int x,int fa)
{
	if (d[x]==1 && x!=1)
	{
		dp[x][1]=cost[x];
		dp[x][0]=0;
		return ;
	}
	for (int i=head[x]; i; i=e[i].las)
	{
		int c=e[i].to;
		if (c==fa) continue;
		if (vis[x] && vis[c] && !f[x] && !f[c])
		{
			dp[1][0]=dp[1][1]=-1;
			flag=true;
			return; 
		}
		ddp(c,x);
		if (flag) return ;
		dp[x][0]+=dp[c][1];
		dp[x][1]+=min(dp[c][0],dp[c][1]);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf ("%d %d %s",&n,&m,s);
	for (int i=1;i<=n;i++)
		scanf ("%d",&cost[i]);
	for (int i=1; i<n; i++)
	{
		int a,b;
		scanf ("%d %d",&a,&b);
		add(a,b),add(b,a);
		d[a]++,d[b]++;
	}
	for (int i=1; i<=m; i++)
	{
		int a,b,c,d;
		scanf ("%d %d %d %d",&a,&b,&c,&d);
		for (int i=1;i<=n;i++)
			dp[i][0]=0,dp[i][1]=cost[i];
		if (b) dp[a][0]=maxn;
		else dp[a][1]=maxn;
		if (d) dp[c][0]=maxn;
		else dp[c][1]=maxn;
		flag=false;
		vis[a]=vis[c]=true;
		f[a]=b,f[c]=d;
		ddp(1,0);
		printf ("%d\n",min(dp[1][0],dp[1][1]));
		vis[a]=vis[c]=false;
		f[a]=f[c]=0;
	}
	return 0;
}
