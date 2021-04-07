#include<cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct str{
	int to,next,w;
}e[100010];
int head[100010],cnt=0;
int dep[100010],book[100010];
int maxx=0,rec=0,smax=0;
int map[100010],dp[50010];
bool cmp(str a,str b)
{
	return a.w<b.w;
}
void add(int u,int v,int w)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
int n,m;
void dfs(int x,int deep){
	book[x]=1;
	for(int i=head[x];i!=0;i=e[i].next)
	{
		int v=e[i].to;
		if(book[v]==0)
		{
			dep[v]=deep+e[i].w;
			if(dep[v]>=maxx)
			{
				maxx=dep[v];
				rec=v;
			}
			dfs(v,dep[v]);
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,0,sizeof(head));
	memset(book,0,sizeof(book));
	scanf("%d%d",&n,&m);
	int umax=0;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		umax=max(u,umax);
		smax=max(v-u,smax);
		add(u,v,w);
		add(v,u,w);
	}
	if(m==1)
	{
		dep[1]=0;
		dfs(1,0);
		memset(book,0,sizeof(book));
		memset(dep,0,sizeof(dep));
		maxx=0;
		dfs(rec,0);
		printf("%d",maxx);
		return 0;
	}
	else if(umax==1)
	{
		sort(e+1,e+1+cnt,cmp);
		int j=0,ans=123153132;
		for(int i=1;i<=m;i++)
		{
			int rr=e[cnt-(m*2)+j].w+e[cnt-j].w;
			j+=2;
			ans=min(ans,rr);
		}
		printf("%d",ans);
		return 0;
	}
	else if(smax==1)
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=head[i];j!=0;j=e[j].next)
			{
				if(e[j].to=i-1){
				map[i]=e[j].w;
				break;
				}
			}
		}
	}
}
