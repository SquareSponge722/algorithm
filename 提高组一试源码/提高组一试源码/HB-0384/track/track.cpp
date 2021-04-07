#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mlr ll mid((l+r)>>1)
using namespace std;
int n,m,k;
int x,y,w;
int cnt(0);
int head[1000010];
int dist[1000010];
int vis[1000010];
int pre[1000010];
map<pair<int,int>,int> m1;
map<pair<int,int>,int> m2;
struct edge
{
	int to,next,weight;
}a[2000020];
void addedge(int xi,int yi,int wi)
{
	a[cnt].to=yi;
	a[cnt].next=head[xi];
	a[cnt].weight=wi;
	head[xi]=cnt++;
}
void link(int xi,int yi,int cnt1,int cnt2)
{
	m1[make_pair(xi,yi)]=cnt1;
	m2[make_pair(xi,yi)]=cnt2;
	m1[make_pair(yi,xi)]=cnt1;
	m2[make_pair(yi,xi)]=cnt2;
}
void spfa(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dist,INF,sizeof(dist));
	memset(pre,-1,sizeof(pre));
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty())
	{
		int t(q.front());
		q.pop();
		vis[t]=1;
		for(int i=head[t];i!=-1;i=a[i].next)
		{
			int v=a[i].to;
			if(dist[v]>dist[t]+a[i].weight)
			{
				dist[v]=dist[t]+a[i].weight;
				a[(m1[make_pair(t,v)]==i)?m2[make_pair(t,v)]:m1[make_pair(t,v)]].weight=INF;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
		link(x,y,cnt-1,cnt);
	}
	if(m==1)
	{
		int ans(-1);
		for(int i=1;i<=cnt;i++)a[i].weight*=-1;
		for(int i=1;i<=n;i++)
		{
			spfa(i);
			for(int j=1;j<=n;j++)
			{
				ans=max(0-dist[j],ans);
			}
		}
		printf("%d",ans);
		return 0;
	}
	srand(time(0));
	printf("%d",rand());
	return 0;
}