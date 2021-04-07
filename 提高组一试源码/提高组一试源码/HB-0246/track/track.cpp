#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int disto[1010][1010];
int edge[1010][1010];
int n,m;
int maxa;
int mark[1010][1010];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	memset(disto,0,sizeof(disto));
	int u,v,w;
	for(int i=1; i<n; i++)
	{
		cin>>u>>v>>w;
		edge[u][v]=w;
	}
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			for(int k=j; k<=n; k++)
				if(edge[i][j]<edge[i][k]+edge[k][j])
					edge[i][j]=edge[i][k]+edge[k][j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			maxa=maxa>edge[i][j]? maxa:edge[i][j];
	cout<<maxa;
	return 0;
}
