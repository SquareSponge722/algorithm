#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long 
using namespace std;
const int N=5e4+110;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,head[N],cnt,deep[N],pos,fa[N],siz[N],son[N],top[N],coc;
ll sum,b[N],dis[N],maxx;
struct node
{
	int nt,to;
	ll w;
}edge[N*2];
void add(int x,int y,ll z)
{
	edge[++cnt]=(node){head[x],y,z};head[x]=cnt;
	edge[++cnt]=(node){head[y],x,z};head[y]=cnt;
}
void dfs(int x,int fa,ll d)
{
	if(d>maxx){
		maxx=d;
		pos=x;
	}
	for(int i=head[x];i;i=edge[i].nt)
	{
		int v=edge[i].to;
		if(v!=fa)
		dfs(v,x,d+edge[i].w);
	}
}
void dfs2(int x,int fa1,ll dist,int d)
{
	deep[x]=d;fa[x]=fa1;dis[x]=dist;siz[x]=1;
	for(int i=head[x];i;i=edge[i].nt)
	{
		int v=edge[i].to;
		if(v==fa1)continue;
		dfs2(v,x,dist+edge[i].w,d+1);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs3(int x,int tp)
{
	top[x]=tp;
	if(!son[x])return;
	dfs3(son[x],tp);
	for(int i=head[x];i;i=edge[i].nt)
	{
		int v=edge[i].to;
		if(v!=fa[x]&&v!=son[x])
		dfs3(v,v);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]>deep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	if(deep[x]>deep[y])return y;
	else return x;
}
ll dist(int x,int y)
{
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
bool check(ll x)
{
	int k=lower_bound(b+1,b+1+coc,x)-b;
	if(b[k]==x)
	{
		if((sum-x)/(m-1)>x)return 1;
		else return 0;
	}
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<n;i++)
    {
    	int x,y;
		ll z;
    	x=read();y=read();z=read();sum+=z;
    	add(x,y,z);
	}
	if(m==1)
	{
		dfs(1,0,0);
		dfs(pos,0,0);
		printf("%lld\n",maxx);
		return 0;
	}
	dfs2(1,0,1,1);
	dfs3(1,1);
	coc=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
	  {
	  	 coc++;
	  	 b[coc]=dist(i,j);
	  }
	}
	sort(b+1,b+1+coc);
	int l=1,r=b[coc];
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
		
	}
	printf("%lld\n",(l+r)/2);
	

  	return 0;	
}
