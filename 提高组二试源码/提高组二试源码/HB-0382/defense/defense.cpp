#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100010;
const long long INF=0x3f3f3f3f3f3f3f3fll;

void dfs(int u,int fa);
void add(int u,int v);

int head[N],nxt[N<<1],to[N<<1],cnt;
int n,m,p[N],a,x,b,y;
long long f[N][2];
char type[10];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	int i,u,v;
	
	scanf("%d%d%s",&n,&m,type);
	
	for (i=1;i<=n;++i)
	{
		scanf("%d",p+i);
	}
	for (i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for (i=0;i<m;++i)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		dfs(1,0);
		if (f[1][0]==INF&&f[1][1]==INF)
		{
			puts("-1");
		}
		else
		{
			printf("%lld\n",min(f[1][0],f[1][1]));
		}
	}
	
	return 0;
}

void dfs(int u,int fa)
{
	int i,v;
	for (i=head[u];i;i=nxt[i])
	{
		v=to[i];
		if (v!=fa)
		{
			dfs(v,u);
		}
	}
	if ((u==a&&x)||(u==b&&y)||(u!=a&&u!=b))
	{
		f[u][1]=p[u];
		for (i=head[u];i;i=nxt[i])
		{
			v=to[i];
			if (v!=fa)
			{
				if (f[v][0]==INF&&f[v][1]==INF)
				{
					f[u][1]=INF;
					break;
				}
				f[u][1]+=min(f[v][0],f[v][1]);
			}
		}
	}
	if ((u==a&&!x)||(u==b&&!y)||(u!=a&&u!=b))
	{
		f[u][0]=0;
		for (i=head[u];i;i=nxt[i])
		{
			v=to[i];
			if (v!=fa)
			{
				if (f[v][1]==INF)
				{
					f[u][0]=INF;
					break;
				}
				f[u][0]+=f[v][1];
			}
		}
	}
	if ((u==a&&x)||(u==b&&y))
	{
		f[u][0]=INF;
	}
	if ((u==a&&!x)||(u==b&&!y))
	{
		f[u][1]=INF;
	}
}

void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
