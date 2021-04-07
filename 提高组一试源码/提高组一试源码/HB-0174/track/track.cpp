//track.cpp
#include<cmath>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#define MAXN 50005
using namespace std;

ifstream fin("track.in");
ofstream fout("track.out");

int cnt,tot,head[MAXN];
bool flag1=1,flag2=1;
int n,m,u,v,w,ans[MAXN],len;

struct edge
{
	int w;
	int to,nxt;
	bool operator <(const edge& rhs)const
	{
		return w>rhs.w;
	}
} ly[MAXN<<1];

inline void add(int u,int v,int w)
{
	ly[++cnt].to=v;
	ly[cnt].w=w;
	ly[cnt].nxt=head[u];
	head[u]=cnt;
}

inline void init()
{
	fin>>n>>m;
	for(int i=1; i<n; ++i)
	{
		fin>>u>>v>>w;
		if(u!=1)	flag1=0;
		if(v!=u+1)	flag2=0;
		add(u,v,w);
		add(v,u,w);
	}
	sort(ly+1,ly+2*n-1);
}

inline void dfs(int now)
{

}

inline void work()
{
	if(flag1)		//Ð¡Ê÷
	{
		if(m<=(n-1)/2)
		{
			for(int i=1; i<=m; ++i)
				ans[++tot]=ly[2*i].w+ly[2*m-2*i+1].w;
			sort(ans,ans+m+1);
			fout<<ans[1];
		}
		else
		{
			while(m>(n-1)/2)
			{
				tot++;
				m--;
				n--;
				ans[tot]=ly[tot*2].w;
			}
			len=tot+2;
			for(int i=1; i<=m; ++i)
			{
				tot++;
				ans[tot]=ly[tot*2].w+ly[len+2*m-2*i+2].w;
			}
			sort(ans,ans+m+1);
			fout<<ans[1];
		}
		exit(0);
	}
	if(flag2)		//ÐòÁÐ
	{

		exit(0);
	}
	if(m==1)		//Ö±¾¶
	{
		dfs(1);
		fout<<ans;
		exit(0);
	}
}

int main()
{
	init();
	work();
	return 0;
}

/*
5 3
1 2 3
1 3 4
1 4 5
1 5 6
*/
