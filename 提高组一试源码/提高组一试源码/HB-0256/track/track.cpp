#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 500001
using namespace std;
int n,m,u,v,w,maxn;
int head[N],fa[N][25],_log2[N],dep[N],dis[N],ww[N];
struct edge
{
	int to,next,w;
} e[N<<1];
void dfs(int v)
{
	for(int i=1;i<=_log2[dep[v]];i++)
	fa[v][i]=fa[fa[v][i-1]][i-1];
	for(int i=head[v];i;i=e[i].next)
	{
		int go=e[i].to;
		if(go==fa[v][0]) continue;
		fa[go][0]=v; dep[go]=dep[v]+1;
		dis[go]=dis[v]+e[i].w;
		dfs(go);
	}
	return ;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int cha=dep[x]-dep[y],pj=_log2[cha];
	for(int i=0;i<=pj;i++)
	if((1<<i)&cha)
	x=fa[x][i];
	if(x==y) return x;
	for(int i=maxn;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	{
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}
bool judge(int mid)
{
	int choice=0,tmp=n+1,j=2;
	for(int i=n;i>=2;i--)
	if(ww[i]>=mid) choice++,tmp=i;
	else break;
	tmp--;
	for(int i=tmp;i>=3;i--)
	{
		while(j<i && ww[i]+ww[j]<mid)
		j++;
		if(j>=i) break;
		choice++; j++;
	}
	return choice>=m;	 	
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m); 
	if(m==1)
	{	
		for(int i=2;i<=n;i++)
		_log2[i]=_log2[i>>1]+1;
		maxn=_log2[n]+1;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v>>w;
			e[i]=(edge) {v,head[u],w};
			head[u]=i;
			e[i+n-1]=(edge) {u,head[v],w};
			head[v]=i+n-1;
		}
		dfs(1);
		int ans=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,dis[i]+dis[j]-(dis[lca(i,j)]<<1));
		printf("%d\n",ans);
		return 0;
	}
	else if(m==n-1)
	{
		int ans=0x7f7f7f7f;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v>>w;
			ans=min(ans,w);
		}
		printf("%d\n",ans);
		return 0;
	}
	else
	{	
		int l=0,r=0,mid,ans;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v>>w;
			ww[v]=w; r+=w;
		}
		sort(ww+1,ww+n+1);
		while(l<=r)
		{
			mid=l+r>>1;
			if(judge(mid))
			{ans=mid; l=mid+1;}
			else
			r=mid-1;
		}
		printf("%d\n",ans);
		return 0;
	}
}
