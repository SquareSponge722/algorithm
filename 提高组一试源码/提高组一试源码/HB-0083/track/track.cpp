#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define N 23166
using namespace std;
int n,m,dist[N][N],maxv=0;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a,b,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		dist[i][j]=63;
		dist[i][i]=0;
	}
	for(int i=1;i<n;i++)
	{
		cin>>a>>b>>l;
		dist[a][b]=l;
		dist[b][a]=l;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(dist[i][j]-dist[i][k]>dist[k][j])
		dist[i][j]=dist[i][k]+dist[k][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(maxv<dist[i][j])maxv=dist[i][j];
	cout<<maxv;
	return 0;
}
