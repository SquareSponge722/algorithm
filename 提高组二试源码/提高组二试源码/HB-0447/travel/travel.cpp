# include<cstdio>
# include<iostream>
# include<cstring>
# include<algorithm>
# include<queue>
# include<cmath>
# include<stack>
# define N 10005
using namespace std;
int n,m;
struct E
{
	int from,to,next;
}e[N];
int head[N];
int Next;
int f[N];
int path[N];
int s=1;
bool vis[N];

int ind[N];
int find(int x)
{ return x==f[x]?x:f[x]=find(f[x]);}

void Merge(int x,int y)
{
	int X=find(x);
	int Y=find(y);
	if(X!=Y)
		f[Y]=X;
	return ;
}

void dfs(int x,int fa,int bo)
{
	bool book[N];
	memset(book,0,sizeof(book));
	vis[x]=true;
	int tim=1;
	int k=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
		 Merge(x,e[i].to);
		 book[e[i].to]=true;
		}
	if(ind[x]>=2)
	{

		for(int i=1;i<=n;i++)
			if(find(x)==find(i)&&!vis[i]&&book[i])
			{
				path[++s]=i;
				if(tim==ind[x])
					dfs(i,x,0);
				else 
					dfs(i,x,1);
				tim++;
			}
	}
	else if(bo==0)
	{
		for(int i=1;i<=n;i++)
			if(find(x)==find(i)&&!vis[i])
			{
				k=i;
				break;
			}
		if(k)
		{
			path[++s]=k;
			dfs(k,x,0);
		}
	}
	return ;
} 
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[i].from=u;
		e[i].to=v;
		e[i].next=head[u];
		head[u]=i;
		e[i+m].from=v;
		e[i+m].to=u;
		e[i+m].next=head[v];
		head[v]=i+m;
		ind[u]++;
		ind[v]++;
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	path[1]=1;
	dfs(1,0,0);
	for(int i=1;i<=s;i++)
		printf("%d ",path[i]);
	return 0;
}
	
	
	
