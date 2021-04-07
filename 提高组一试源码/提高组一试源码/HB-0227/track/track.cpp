#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#define N 100000+100
using namespace std;
int num,n,flag[N];
int d[1010][1010],jl,ans;
void dfs(int x)
{
	flag[x]=1;
	for(int k=n;k>=1;k--)
	{
		if(d[k][x]>=1&&flag[k]==0&&k!=x)
		{
			jl+=d[x][k];
			ans=max(ans,jl);
			dfs(k);
			jl-=d[x][k];
		}
	}
}
int main() 
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;//cout<<z<<endl;
		d[x][y]=z;
		d[y][x]=z;
		//cout<<d[x][y]<<" "<<d[y][x]<<endl;
	}
	/*for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
		cout<<d[i][j]<<" ";
	}
	cout<<endl;
	}*/
	//cout<<d[1][2]<<endl;
	for(int i=1;i<=n;i++)dfs(i);
	cout<<ans;
	return 0;
}
