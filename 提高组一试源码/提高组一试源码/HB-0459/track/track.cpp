#include<bits/stdc++.h>
#define maxn 50010
#define inf 999999999
using namespace std;
struct edge{
	int v,w,nxt;
}e[maxn<<1];
int cnt=0,head[maxn],n,m;
long long dis[maxn],ans;
void ade(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
struct node{
	int u,d;
	bool operator < (const node& rhs) const{
	return d>rhs.d;
	}
};
void dj(int s)
{
	for(int i=1;i<=n;i++)
	dis[i]=inf;
	dis[s]=0;
	priority_queue <node> Q;
	Q.push((node) {s,0});
	while(!Q.empty())
	{
		node fr=Q.top();
		int u=fr.u,d=fr.d;
		Q.pop();
		if(d!=dis[u])
		continue;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				Q.push((node) {v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ade(a,b,c);
		ade(b,a,c);
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			dj(i);
			for(int j=1;j<=n;j++)
			if(ans<dis[i])
			{
				ans=dis[i];
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			ans+=e[i].w;
		}
		ans/=m*2;
		ans--;
		cout<<ans;
		return 0;
	}
	return 0;
}
