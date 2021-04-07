#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005];
int d[1005][1005];
const int INF = 1e9;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		a[x][y]=w;
		a[y][x]=w;
		d[x][y]=d[y][x]=w;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++) 
		if(a[i][k])
		{
			for(int j=1;j<=n;j++)
			if(a[k][j])
			{
				if(i==j) continue;
				d[i][j]=max(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			ans=max(ans,d[i][j]);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
