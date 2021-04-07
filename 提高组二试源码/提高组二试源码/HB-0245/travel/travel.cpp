#include<bits/stdc++.h>
using namespace std;
int n,m,g,a;
int vis[5001];
int ans[5001];
struct bian{	
	friend bool operator < (bian n1,bian n2)
	{
		return n2.to<n1.to;
	}
	int next,to;
}o[10001];
int head[5001];
void add(int x,int y)
{
	o[++g].to=y;
	o[g].next=head[x];
	head[x]=g;
}
void dfs(int u)
{
	int k[5001];
	vis[u]=1;
	int ge=0;
	for(int i=head[u];i;i=o[i].next)
	{
		if(!vis[o[i].to])
		k[++ge]=o[i].to;
	}
	sort(k+1,k+ge+1);
	for(int i=1;i<=ge;i++)
	{ans[++a]=k[i];dfs(k[i]);}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	vis[1]=1;
	ans[1]=1;
	a=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(m==n-1)
	{
		dfs(1);
		for(int i=1;i<=n;i++)
		{cout<<ans[i];
		if(i!=n)cout<<" ";}
	}
	else
	{
		priority_queue<bian> q;
		for(int i=head[1];i;i=o[i].next)
		{
			q.push(o[i]);
		}
		while(!q.empty())
		{
			bian l=q.top();
			q.pop();
			if(!vis[l.to])
			{
				vis[l.to]=1;
				ans[++a]=l.to;
				for(int i=head[l.to];i;i=o[i].next)
				{
					if(!vis[o[i].to])
					q.push(o[i]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{cout<<ans[i];if(i!=n)cout<<" ";}
	}
	return 0;
}
