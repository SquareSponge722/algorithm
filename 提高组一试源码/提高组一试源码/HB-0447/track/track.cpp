# include<cstdio>
# include<queue>
# include<algorithm>
# include<cstring>
# define N 50005
# define WQD 0x7f7f7f7f
using namespace std;
int n,m;
struct E
{
	int from,to,w,next;
}e[N];
int f[N][21];
int pre[N];
int head[N];
int dep[N];
void dfs(int x)
{
	for(int i=1;1<<i<=n;i++)
		if(f[x][i-1])
			f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==f[x][0]) continue;
		f[v][0]=x;
		pre[v]=i;
		dep[v]=dep[x]+1;
		dfs(v);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	int cha=dep[x]-dep[y];
	for(int i=20;i>=0;i--)
	{
		if((1<<i)&cha) 
			x=f[x][i];
	}
	if(x==y)
		return x;
	for(int i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main()

{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		e[i].from=u;
		e[i].to=v;
		e[i].next=head[u];
		e[i].w=t;
		head[u]=i;
		e[i+n].from=v;
		e[i+n].to=u;
		e[i+n].w=t;
		e[i+n].next=head[v];
		head[v]=i+n;
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int j=1;j<=n;j++)
		{
		int k=lca(i,j);
		for(int h=i;h!=k;h=f[h][0])
		    tot+=e[pre[h]].w;
		for(int h=j;h!=k;h=f[h][0])	
			tot+=e[pre[h]].w;
		if(tot<ans)
			break;
		}
		ans=max(ans,tot);	
	}
	printf("%d",ans);
	return 0;
}
