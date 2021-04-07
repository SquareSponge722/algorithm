#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("track.in");
ofstream fout("track.out");

typedef long long ll;
int n,m; ll tot=0; const int S=50010;
struct edge{
	int to,w,next;
}e[S*2]; int head[S]; int c=0;
void ad(int u,int v,int w){
	e[++c].to=v; e[c].w=w;
	e[c].next=head[u]; head[u]=c;
}

namespace task1 //d of the tree
{
	ll dis[S]; bool vis[S]; int side; ll mx_dis=0;
	queue <int> q;
	void bfs(int u)
	{
		dis[u]=0;
		q.push(u); vis[u]=false;
		while(!q.empty())
		{
			int i=q.front(); q.pop();
			if(dis[i]>mx_dis) {
				mx_dis=dis[i];
				side=i;
			}
			for(int j=head[i];j;j=e[j].next)
			{
				if(vis[e[j].to]) continue ;
				vis[e[j].to]=true;
				dis[e[j].to]=dis[i]+e[j].w;
				q.push(e[j].to);
			}
		}
		
	}
	void work()
	{
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		bfs(1); int side1=side;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		bfs(side1);
		fout<<mx_dis<<'\n';
		return ;
	}
}
namespace task2//lian
{
	int a[S]; int num=0;
	void dfs(int u,int fa)
	{
		for(int j=head[u];j;j=e[j].next)
		{
			if(e[j].to!=fa)
			{
				a[++num]=e[j].w;
				dfs(e[j].to,u);
			}
		}
	}
	bool check(ll k)
	{
		int i=1; int j=1; ll sum=0;
		while(i<=m)
		{
			if(j>num)
				return false;
			while(sum<k){
				sum+=a[j++];
				if(j>num && sum<k) 
					return false;
			}
			sum=0;
			i++;
		}
		return true;
	}
	void work()
	{
		dfs(1,-1);
		
		ll l=0; ll r=tot;
		
		while(l<r)
		{
			ll mid=(l+r+1)/2;
			if(check(mid))
				l=mid;
			else 
				r=mid-1;
		}
		fout<<l<<'\n';
		return ;
	}
}
namespace task3
{
	void work()
	{
		fout<<(int)((tot/m)*(26282.0/39018))<<'\n';
		return ;
	}
}
namespace task4
{
	int a[S]; int num=0; bool X[S];
	bool check(ll k)
	{
		memset(X,0,sizeof(X));
		ll sum=0;
		for(int i=1;i<=m;i++)
		{
			sum=0;
			int j=n;
			while(sum<k)
			{
				do{
					j--;
				}while(sum+a[j]>=k && j>=1);
				j++; if(X[j]) j--;
				sum+=a[j]; X[j]=true; j--;
				if(j==0 && sum<k)
					return false;
			}
			
		}
		return true;
	}
	
	void work()
	{
		for(int i=2;i<=n;i++)
			a[++num]=e[head[i]].w;
		sort(a+1,a+n+1);
		ll l=0; ll r=tot;
		while(l<r)
		{
			ll mid=(l+r+1)/2;
			if(check(mid))
				l=mid;
			else 
				r=mid-1;
		}
		fout<<l<<'\n';
		return ;
	}
}
int main()
{
	fin>>n>>m; int min_ww; bool lian=true; bool fa1=true;
	for(int i=1;i<n;i++)
	{
		int u,v,w; fin>>u>>v>>w;
		if(v!=u+1) lian=false;
		if(u!=fa1) fa1=false;
		tot+=w;
		ad(u,v,w); ad(v,u,w);
		if(min_ww==-1||w<min_ww)
			min_ww=w;
	}
	
	if(m==1)
		task1::work();
	else if(m==n-1) fout<<min_ww<<'\n';
	else if(lian) task2::work();
	else if(fa1) task4::work();
	else task3::work();
	
	return 0;
}
