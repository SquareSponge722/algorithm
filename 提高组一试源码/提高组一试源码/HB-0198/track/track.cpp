#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 999999999
#define MAXN 50005
using namespace std;

struct edge
{
	int to,val;
};

int ans;
vector<edge> g[MAXN];
int vis[MAXN];
bool usp1,usp2=1,usp3=1;
int fa[MAXN],deepth[MAXN],dis[MAXN];
int n,m;

int read()
{
	int r=0;
	char c=getchar();
	while(c < '0' || c > '9') c=getchar();
	while(c >= '0' && c <= '9') 
	{
		r=r*10+(c-'0');
		c=getchar();
	}
	return r;
}

int lca(int a,int b) 
{
	if(deepth[a] < deepth[b]) swap(a,b);
	while(deepth[a] > deepth[b])
	{
		a=fa[a];
	}
	while(a != b)
	{
		a=fa[a];
		b=fa[b];
	}
	return a;
}

void dfs(int r,int d,int deep)
{
	for(int i=0;i<g[r].size();i++)
	{
		if(g[r][i].to == fa[r]) continue;
		edge &e=g[r][i];
		fa[e.to]=r;
		deepth[e.to]=deep+1;
		dis[e.to]=d+e.val;
		dfs(e.to,dis[e.to],deepth[e.to]);
	}
	return;
}

void build()
{
	n=read();
	m=read();
	if(m == 1)usp1=1;
	for(int i=1;i<n;i++)
	{
		edge e,e2;
		int f,t,v;
		f=read(); t=read(); v=read();
		if(f != 1) usp2=0;
		if(t != f+1) usp3=0;
		e.to=t; e.val=v;
		e2.to=f; e2.val=v;
		g[t].push_back(e2);
		g[f].push_back(e);
	}
	dfs(1,0,0);
	edge first;
	first.to=1;
	first.val=0;
	g[0].push_back(first); 
	return;
}

bool check(int ans)
{
	int tem=0,sum=1;
	for(int i=1;i<n;i++)
	{
		int d=dis[i+1]-dis[i];
		if(tem+d <= ans)
		{
			tem+=d;
		}
		else
		{
			tem=0;
			sum++;
		}
	}
	if(sum <= m) return false;
	else return true;
}

int sp1()
{
	int m=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int f=lca(i,j),d=0;
			d=dis[i]+dis[j]-dis[f]*2;
			m=max(d,m);
		}
	}
	return m;
}

int sp2()
{
	priority_queue<int> q;
	for(int i=0;i<g[1].size();i++)
	{
		q.push(g[1][i].val);
	}
	for(int i=1;i<m;i++)
	{
		q.pop();
	}
	return q.top();
}

int sp3()
{
	int ans=-1;
	int l=1,r=INF;
	while(l <= r)
	{
		int mid=(r-l)/2+l;
		if(check(mid))
		{
			l=mid+1;
			
		}
		else
		{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}

void solve()
{
	if(usp1)
	{
		ans=sp1();
	}
	else if(usp2)
	{
		ans=sp2();
	}
	else if(usp3)
	{
		ans=sp3();
	}
	else sp1();
	return;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	build();
	solve();
	cout<<ans;
	return 0;
}
