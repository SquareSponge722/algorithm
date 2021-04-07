#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,vis[5005],b[5005];
vector<int>v[5005];
stack<int>s;
void dfs(int x)
{
	vis[x]=true;
	for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(vis[y]) continue;
			dfs(y);
			s.push(y);
		}
}
void dfs2(int x)
{
	vis[x]=true;
	cout<<x<<" ";
	for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(vis[y]) continue;
			dfs2(y);
		}
}
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	if(m==n-1)
	{
	for(int i=1;i<=n;i++)
	{
		int t=v[i].size();
		for(int j=0;j<v[i].size();j++)
			{
				b[j+1]=v[i][j];
			}
		sort(b+1,b+t+1,cmp);
		v[i].clear();
		for(int j=1;j<=t;j++)
			{
				v[i].push_back(b[j]);
			}
	}
	dfs(1);
	cout<<1<<" ";
	while(!s.empty())
	{
		int x=s.top();
		s.pop();
		cout<<x<<" ";
	}
	return 0;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
	{
		int t=v[i].size();
		for(int j=0;j<v[i].size();j++)
			{
				b[j+1]=v[i][j];
			}
		sort(b+1,b+t+1);
		v[i].clear();
		for(int j=1;j<=t;j++)
			{
				v[i].push_back(b[j]);
			}
	}
		dfs2(1);
		return 0;
	}
	return 0;
}
