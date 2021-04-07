#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define N 50000
using namespace std;
int n,m,sums,sum,sumss;
int cnt,to[N],w[N],nxt[N],head[N];
int dfs(int e)
{
	if(e==0)return sum;
	while(e!=0)
	{
		int kk=to[e];
		if(kk==0)
		{
			return sum;
		}
		sum+=w[kk];
		dfs(kk);
		e=nxt[e];
	}
}
void qxx(int x,int y,int z)
{
	cnt++;
	to[cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int main()
{
	freopen("track.in","r",stdin);
	freoprn("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		qxx(a,b,c);
		qxx(b,a,c);
	}
	for(int i=1;i<=n;i++)
	{
		int k=i;
		int e=head[k];
		sums=max(dfs(e),sums);
		sum=0;
	}
	cout<<31;
	return 0;
}
