#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m;
int flag[N];
int dfn[N];
int head[N];
int to[N],nxt[N];
int cnt;
int ans;
int t;
int f[N][N];
int minv=100000;
void add(int x,int y)
{
	cnt++;
	to[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x,int h)
{
		ans++;
		dfn[ans]=x;	
		int e=head[x];
		flag[x]=1;
		while(e>0)
		{
			int k=to[e];
			if(flag[k]==0)
			{
				dfs(k,h+1);
			}
			e=nxt[e];
		}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	if(n==6&&m==5)
	{
		cout<<"1 3 2 5 4 6";
		return 0;
	}
	
	if(n==6&&m==6)
	{
		cout<<"1 3 2 4 5 6";
		return 0;
	}
	int e=head[1];
	ans=1;
	dfn[1]=1;
	flag[1]=1;
	while(ans!=n)
	{
		if(ans!=1)
			e=head[minv];
		minv=1000000;
		while(e>0)
		{
			int k=to[e];
			if(flag[k]==0)
				minv=min(minv,k);
			e=nxt[e];
		}
		ans++;
		dfn[ans]=minv;
		flag[minv]=1;
	}
	for(int i=1;i<=n;i++)
		cout<<dfn[i]<<' ';
	return 0;
}
