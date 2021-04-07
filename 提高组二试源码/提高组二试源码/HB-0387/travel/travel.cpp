#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int mian()
{
	int m,n,a[5001][5001],u,v,dfs[5001],j=1;
	FILE *fin, *fout;
	fin=fopen("travel.in","r");
	fout=fopen("travel.out","w");
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
	    a[u][v]=1;
	    a[v][u]=1;
	}
	if(n>m)
	{
		mm[j]=i;
		j++;
		if(j==n) break;
		dfs[i];
		flag[i]=u;
	}
	if(j<=n)
	for(i=1;i<=n;i++)
	return;
	
}
