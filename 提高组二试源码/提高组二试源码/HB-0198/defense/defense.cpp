#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define MAXN 100005
using namespace std;

vector<int> g[MAXN];
int p[MAXN];
int n,m;
int fx[MAXN],fn[MAXN],fa[MAXN];
string sp;

void build()
{
	cin>>n>>m;
	cin>>sp;
	for(int i=1; i<=n; i++)
		{
			cin>>p[i];
		}
	for(int i=1; i<n; i++)
		{
			int f,t;
			cin>>f>>t;
			g[f].push_back(t);
			g[t].push_back(f);
		}
	return;
}

void dfs(int s)
{
	for(int i=0;i<g[s].size();i++)
	{
		if(g[s][i] == fa[s]) continue;
		fa[g[s][i]]=s;
		dfs(g[s][i]);
		if(vis[s] != 1 && vis[s] != -1)
		fx[s]=min(fx[s],fx[g[s][i]]);
		else if()
		fx[s]=p[s];
		if(vis[s] != -1)
		fn[s]+=fx[g[s][i]];
	}
	fx[s]=min(fx[s],p[s]);
}

void sp1()
{
	int vis[MAXN]= {};
	int ans=0;
	int a,b,x,y;
	cin>>a>>x>>b>>y;
	if(x)
	{
		vis[a]=1;
		if(a > 1) vis[a-1]=1;
		if(a < n) vis[a+1]=1;
		ans+=p[a];
	}
	else
	{
		vis[a]=-1;
	}
	if(y)
	{
		vis[b]=1;
		if(b > 1) vis[b-1]=1;
		if(b < n) vis[b+1]=1;
		ans+=p[y];
	}
	else
	{
		vis[b]=-1;
	}
	if((vis[1] == -1 && vis[2] == -1) || (vis[n-1] == -1 && vis[n] == -1))
	{
		cout<<-1<<endl;
		return;
	}
	dfs(1);
	cout<<min(fn[1],fx[1]);
}

void solve()
{
	if(sp[0] == 'A')
		{
			for(int i=0; i<m; i++)
				{
					memset(fx,0x3f,sizeof(fx));
					sp1();
				}
		}
}

int main()
{
	build();
	solve();
	return 0;
}
