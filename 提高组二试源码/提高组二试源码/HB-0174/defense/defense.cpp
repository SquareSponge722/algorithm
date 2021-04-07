//defense.cpp
#include<cmath>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#define MAXN 2100
using namespace std;

ifstream fin("defense.in");
ofstream fout("defense.out");

int n,m,ans;
int a,b,x,y;
int p[MAXN];
string type;
bool w[MAXN][MAXN],k[MAXN];

inline void init()
{
	fin>>n>>m;
	fin>>type;
	for(int i=1; i<=n; ++i)
		fin>>p[i];
	for(int i=1; i<=n-1; ++i)
	{
		fin>>x>>y;
		w[x][y]=w[y][x]=1;
	}
}

inline void work()
{
	while(m--)
	{
		fin>>a>>x>>b>>y;
		memset(k,0,sizeof(k));
		if(w[a][b]==1&&x==0&&y==0)
		{
			fout<<-1<<endl;
			continue;
		}
		else
		{
			k[a]=x;
			k[b]=y;
			if(a>b)		swap(a,b);
			for(int i=a-1; i>=1; --i)
				k[i]=k[i+1]^1;
			for(int i=b+1; i<=n; ++i)
				k[i]=k[i-1]^1;
			for(int i=a+1; i<=b-1; ++i)
				k[i]=k[i-1]^1;
			if(k[b-1]==0&&k[b]==0)
				k[b-1]=1;
			ans=0;
			for(int i=1; i<=n; ++i)
				if(k[i])	ans+=p[i];
			fout<<ans;
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}
