#include<cstdio>
#include<algorithm>
#define N 50010
using namespace std;
struct Edge{int to,next,w;}e[N<<1];
int first[N];
int d1[N],d2[N];
int a[N];
int n,m;
int mmax(int a,int b){return a>b?a:b;}
int mmin(int a,int b){return a<b?a:b;}
bool cmp(const Edge &a,const Edge &b){
	return a.w>b.w;
}
void dfs1(int u,int fa)
{
	int k=first[u];
	while(k)
	{
		int v=e[k].to,w=e[k].w;k=e[k].next;
		if(v==fa)continue;
		dfs1(v,u);
		if(d1[v]+w>d1[u]){d2[u]=d1[u];d1[u]=d1[v]+w;}
		else if(d1[v]+w>d2[u])d2[u]=d1[v];
	}
}
void dfs2(int u,int fa)
{
	int k=first[u];
	while(k)
	{
		int v=e[k].to,w=e[k].w;k=e[k].next;
		if(v==fa)continue;
		a[u]=w;dfs2(v,u);
	}
}
bool judge(int x)
{
	int s=0,ans=0;
	for(int i=1;i<n;i++)
		if((s+=a[i])>=x)s=0,ans++;
	if(ans<m)return true;
	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	int u,v,w;bool ai=true,bi=true;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);if(u!=1)ai=false;if(v!=u+1)bi=false;
		e[i]=(Edge){v,first[u],w};first[u]=i;
		e[i+n]=(Edge){u,first[v],w};first[v]=i+n;
	}
	if(m==1)
	{
		dfs1(1,0);
		int ans=0;
		for(i=1;i<=n;i++)ans=mmax(ans,d1[i]+d2[i]);
		printf("%d",ans);return 0;
	}
	if(m==n-1)
	{
		int ans=0;
		for(i=1;i<n;i++)ans=mmax(ans,e[i].w);
		printf("%d",ans);return 0;
	}
	if(ai)
	{
		sort(e+1,e+n,cmp);
		printf("%d",mmin(e[m-1].w,e[m].w+e[m+1].w));
		return 0;
	}
	if(bi)
	{
		dfs2(1,0);
		int l=0,r=999999999;
		while(l!=r)
		{
			int mid=(l+r)>>1;
			if(judge(mid))r=mid;
			else l=mid+1;
		}
		printf("%d",l-1);return 0;
	}
	return 0;
}
