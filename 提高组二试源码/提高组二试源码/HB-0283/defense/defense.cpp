#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=999999999;
int p[100001];
struct EDGE
{
	int s;
	int e;
	int next;
}edge[100001*2];
int head[100001];
int cnt;
int n,m;
char sp[10];
int f[10001][5];
int dfn[100001];
int ff[100001];
int siz[100001];
int top[100001];
int de[100001];
int wson[100001];
int w[100001];
int cur;
void add(int s,int e)
{
	cnt++;
	edge[cnt].s=s;
	edge[cnt].e=e;
	edge[cnt].next=head[s];
	head[s]=cnt;
	cnt++;
	edge[cnt].e=s;
	edge[cnt].s=e;
	edge[cnt].next=head[e];
	head[e]=cnt;
}
void dfs1(int u,int fa,int depth)
{
	ff[u]=fa;
	de[u]=depth;
	siz[u]=1;
	int maxson=-1;
	for(int t=head[u];t;t=edge[t].next)
	{
		int v=edge[t].e;
		if(v==fa)
		{
			continue;
		}
		dfs1(v,u,depth+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson)
		{
			maxson=siz[v];
			wson[u]=v;
		}
	}
}
void dfs2(int u,int topline)
{
	cur++;
	dfn[u]=cur;
	top[u]=topline;
	w[dfn[u]]=p[u];
	if(!wson[u])
	{
		return;
	}
	dfs2(wson[u],topline);
	for(int t=head[u];t;t=edge[t].next)
	{
		int v=edge[t].e;
		if(v==ff[u]||v==wson[u])
		{
			continue;
		}
		dfs2(v,v);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,sp);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<n;i++)
	{
		int x;
		int y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if((dfn[a]==dfn[b]+1||dfn[b]==dfn[a]+1)&&(x==0&&y==0))
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			f[i][1]=INF;
			f[i][0]=INF;
		}
		f[1][0]=0;
		f[1][1]=w[1];
		for(int i=1;i<=n;i++)
		{
			if(i-1==dfn[a])
			{
				if(x==1)
				{
					f[i][1]=min(f[i-1][1]+w[i],f[i][1]);
					f[i][0]=min(f[i-1][1],f[i][1]);
				}
				if(x==0)
				{
					f[i][1]=min(f[i][1],f[i-1][0]+w[i]);
				}
				continue;
			}
			if(i-1==dfn[b])
			{
				if(y==1)
				{
					f[i][1]=min(f[i-1][1]+w[i],f[i][1]);
					f[i][0]=min(f[i-1][1],f[i][1]);
				}
				if(y==0)
				{
					f[i][1]=min(f[i][1],f[i-1][0]+w[i]);
				}
				continue;
			}
			f[i][1]=min(f[i][1],f[i-1][0]+w[i]);
			f[i][1]=min(f[i][1],f[i-1][1]+w[i]);
			f[i][0]=min(f[i][0],f[i-1][1]);
		}
		if(dfn[a]!=n&&dfn[b]!=n)
		{
			printf("%d\n",min(f[n][1],f[n][0]));
			continue;
		}
		if(dfn[a]==n)
		{
			if(x==1)
			{
				printf("%d\n",f[n][1]);
				continue;
			}
			if(x==0)
			{
				printf("%d\n",f[n][0]);
				continue;
			}
		}
		if(dfn[b]==n)
		{
			if(y==1)
			{
				printf("%d\n",f[n][1]);
				continue;
			}
			if(y==0)
			{
				printf("%d\n",f[n][0]);
				continue;
			}
		}
	}
	return 0;
}
/*
5 5 A3
1 2 3 4 5
1 2
2 3
3 4
4 5
1 0 2 1
1 1 5 1
1 1 3 1
1 0 2 0
1 1 5 0
*/
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/