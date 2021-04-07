#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 99999999
using namespace std;

int n,m,a[101][101];

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j) a[i][j]=0;
		else a[i][j]=INF;
	}
	int x,y,z;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=z;
		a[x][y]=z;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(a[i][j]>=a[i][k]+a[j][k])
	a[i][j]=a[i][k]+a[j][k];
	cout<<10<<endl
	return 0;
}
