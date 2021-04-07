#include <cstdio>
#include <cstdlib>
using namespace std;
const int N=50010;
int n,m,tot,head[N],dist[N],maxn,ma,minn=500000000;
struct node
{
	int to;
	int las;
	int val;
} e[2*N];
void add(int a,int b,int c)
{
	e[++tot].to=b;
	e[tot].las=head[a];
	e[tot].val=c;
	head[a]=tot;
}
bool vis[N],flag;
void dfs(int x)
{
	vis[x]=true;
	for (int i=head[x]; i; i=e[i].las)
	{
		int c=e[i].to;
		if (vis[c]) continue;
		dist[c]=dist[x]+e[i].val;
		if (dist[c]>maxn) ma=c,maxn=dist[c];
		dfs(c);
	}
}
void dfs1(int x)
{
	vis[x]=true;
	for (int i=head[x]; i; i=e[i].las)
	{
		int c=e[i].to;
		if (vis[c]) continue;
		dist[c]=dist[x]+e[i].val;
		if (dist[c]>maxn) maxn=dist[c];
		dfs(c);
	}
}
void dij(int x)
{
	for (int i=head[x];i;i=e[i].las)
	{
		int c=e[i].to;
		dist[c]=dist[x]+e[i].val;
		dij(c);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for (int i=1; i<n; i++)
	{
		int a,b,c;
		scanf ("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		if (b!=a+1) flag=true;
		if (c<minn) minn=c;
	}
	if (m==n-1)
	{
		printf ("%d\n",minn);
		return 0;
	}
	if (m==1)
	{
		dfs(1);
		for (int i=1; i<=n; i++)
			vis[i]=false,dist[i]=0;
		maxn=0;
		dfs1(ma);
		printf ("%d\n",maxn);
	}
	if (!flag)
	{
		dij(1);
		int mmin=500000000;
		int s=dist[n]/m,sta=1;
		for (int i=1;i<=n;i++)
			if (dist[i]-dist[sta]>s)
			{
				if (minn>dist[i-1]-dist[sta])
					minn=dist[i-1]-dist[sta];
				sta=i;
			}
		if (mmin>dist[n]-dist[sta]) mmin=dist[n]-dist[sta];
		printf ("%d\n",mmin);
		return 0;
	}
	return 0;
}
