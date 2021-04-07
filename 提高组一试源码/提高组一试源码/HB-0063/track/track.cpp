#include<bits/stdc++.h>
using namespace std;
int dis[1005],n,m,u,v,f[1005][1005],wmin,w;
bool vis[1005];
vector<int>path[1005];
priority_queue<int>q1;
void spfa(int x)
{
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		dis[i]=9999999;
		vis[i]=0;
	}
	q.push(x),dis[x]=0,vis[x]=1;
	
	while(!q.empty())
	{
		int u=q.front(),l=path[u].size();
		q.pop(),vis[x]=0;
		for(int i=0;i<l;i++)
		{
			int v=path[u][i];
			if(dis[v]>dis[u]+f[u][v])
			{
				dis[v]=dis[u]+f[u][v];
				if(!vis[v])
					q.push(v);
			}
				
		}
		
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	wmin=50005;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		path[u].push_back(v);
		path[v].push_back(u);
		f[u][v]=f[v][u]=w;
		if(w<wmin)wmin=w;
	}
	if(m==n-1)
	{
		printf("%d",wmin);
		return 0;
	}
	wmin=50005;
	for(int i=1;i<=n;i++)
	{
		spfa(i);
		for(int i=1;i<=n;i++)
			q1.push(dis[i]);
	}
//	printf("%d",q1.top());
	for(int i=1;i<m;i++)
		q1.pop();
	printf("%d",q1.top());
	return 0;
}
