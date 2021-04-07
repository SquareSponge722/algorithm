//road.cpp
#include<cmath>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#define MAXN 100005
using namespace std;

ifstream fin("road.in");
ofstream fout("road.out");

int n;
long long d[MAXN],f[MAXN];

inline void init()
{
	fin>>n;
	for(register int i=1; i<=n; ++i)
		fin>>d[i];
}

inline void work()
{
	f[1]=d[1];
	f[2]=max(d[1],d[2]);
	for(register int i=3; i<=n; ++i)
	{
		if(d[i-1]>d[i])
			f[i]=f[i-1];
		else
			f[i]=f[i-1]+d[i]-d[i-1];
	}
	fout<<f[n];
}

int main()
{
	init();
	work();
	return 0;
}
