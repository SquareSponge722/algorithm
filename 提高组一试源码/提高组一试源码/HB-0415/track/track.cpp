#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=50050;
struct node
{
	int to,val,nex;
}ed[N*4];
int n,m,x,y,z,tot;
int maxx,sum,ans,sp=1,cnt;
int head[N],f[N],ff[N],dis[N];
vector < int > g[N];
inline void add(int u,int v,int w){
	ed[tot].nex=head[u],ed[tot].to=v;
	ed[tot].val=w,head[u]=tot++;
}
bool jud(int);
bool judd(int);
int dfs(int,int,int);
int ddfs(int,int);
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
		dis[++cnt]=z;
		maxx=max(maxx,z);
		if(x!=1 && y!=1) sp=2;
	}
	if(m==1)
	{
		ddfs(1,1);
		printf("%d\n",ans);
	}
	else if(sp==1)
	{
		int l=1,r=(n-1)*maxx;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(judd(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	else
	{
		int l=1,r=(n-1)*maxx;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(jud(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
bool jud(int k)
{
	sum=0;
	for(int i=1;i<=n;i++) g[i].clear();
	dfs(1,k,1);
	if(sum>=m) return true;
	return false;
}
int dfs(int u,int lim,int fa)
{
	for(int i=head[u];i!=-1;i=ed[i].nex)
	{
		int to=ed[i].to,va=ed[i].val;
		if(to==fa) continue;
		int tmp=dfs(to,lim,u);
		tmp+=va;
		if(tmp>=lim) sum++;
		else g[u].push_back(tmp);
	}
	int siz=g[u].size();
	if(siz==0) return 0;
	sort(g[u].begin(),g[u].end());
	for(int i=siz-1;i>=0;i--)
	{
		bool f=true;
		for(int j=0;j<i;j++)
			if(g[u][i]+g[u][j]>=lim)
			{
				sum++;f=false;
				g[u][i]=g[u][j]=0;
			}
		if(f) break;
	}
	int tmp=0;
	for(int i=0;i<siz;i++) tmp=max(tmp,g[u][i]);
	return tmp;
}
int ddfs(int u,int fa)
{
	for(int i=head[u];i!=-1;i=ed[i].nex)
	{
		int to=ed[i].to,va=ed[i].val;
		if(to==fa) continue;
		int tmp=ddfs(to,u);tmp+=va;
		if(tmp>=f[u]) ff[u]=f[u],f[u]=tmp;
		else if(tmp>ff[u]) ff[u]=tmp;
	}
	ans=max(ans,f[u]+ff[u]);
	return f[u];
}
bool judd(int k)
{
	sort(dis+1,dis+cnt+1);
	int la=cnt,tmp=0,kkk=0;
	for(int i=1;i<=cnt;i++)
		if(dis[i]>=k) kkk++;
	for(int i=kkk;i<=cnt;i++)
	{
		bool f=true;
		for(int j=la;j>i;j--)
			if(dis[i]+dis[j]>=k)
			{
				tmp++;
				la=j-1;
				f=false;
			}
		if(f) break;
	}
	if(tmp+kkk>=m) return true;
	return false;
} 
