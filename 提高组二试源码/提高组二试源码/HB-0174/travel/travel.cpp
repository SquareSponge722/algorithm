//travel.cpp
#include<cmath>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#define MAXN 5005
using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

bool vis[MAXN];
int ans[MAXN],head[MAXN];
int x,y,n,m,cnt,mmin,mmin2,w=1;

struct edge
{
	int to,nxt;
} ly[MAXN<<1];

inline void add(int u,int v)
{
	ly[++cnt].to=v;
	ly[cnt].nxt=head[u];
	head[u]=cnt;
}

inline void init()
{
	fin>>n>>m;
	for(int i=1; i<=m; ++i)
	{
		fin>>x>>y;
		add(x,y);
		add(y,x);
	}
}

inline void print()
{
	for(int i=1; i<=n; ++i)
		fout<<ans[i]<<" ";
}

inline void dfs(int x,int step)
{
	if(!vis[x])
	{
		vis[x]=1;
		ans[step]=x;
	}
	if(step==n)
		print();
	else
	{
		mmin=MAXN;
		for(int p=head[x]; p; p=ly[p].nxt)
		{
			if(vis[ly[p].to])
				continue;
			else
				mmin=min(mmin,ly[p].to);
		}
		if(mmin==MAXN)
			dfs(ans[--w],step);
		else
		{
			step++;
			w=step;
			dfs(mmin,step);
		}
	}
	return;
}

int main()
{
	init();
	dfs(1,1);
	return 0;
}
