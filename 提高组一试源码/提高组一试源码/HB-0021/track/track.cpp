#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 50050
using namespace std;
int _max(int x,int y) {return x>y?x:y;}
int head[N],point[N],cnt;
struct Edge{int next,to,w;} e[N<<1];
struct VD{int v,dis;};
bool operator <(const VD &x,const VD &y) 
{
	return x.dis>y.dis;
}
int n,m,in[N];
int dis[N];
int ans;
void dijkstra(int x)
{
	memset(dis,0x7f,sizeof(dis));
	priority_queue <VD> q;
	dis[x]=0;
	q.push((VD) {x,dis[x]});
	while(q.size()>0)
	{
		VD temp=q.top();
		q.pop();
		int u=temp.v;
		if(temp.dis>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push((VD) {v,dis[v]});
			}
		}
	}
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[i]=(Edge) {head[u],v,w};
		head[u]=i;
		e[i+n]=(Edge) {head[v],u,w};
		head[v]=i+n;
		in[u]++;
		in[v]++;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++) if(in[i]==1) point[++cnt]=i; 
		for(int i=1;i<=cnt;i++)
		{
			dijkstra(point[i]);
			for(int j=i+1;j<=cnt;j++)
			ans=_max(dis[point[j]],ans);
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
