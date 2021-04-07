#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,ding,zhi=0;
int zhen[5001];
int map[5001][5001]={0};
int ans=0;
int bfs(int x,int y)
{
	if(ans>=n-1)
		return 0;
	if(map[x][y]==1)
	{
		cout<<y<<" ";
		ans++;
		zhi++;
		zhen[ans]=y;
		map[x][y]=2;
		map[y][x]=2;
		bfs(y,1);
	}
	else
	{
		if(y<n)
			bfs(x,y+1);
		else
		{
			zhi--;
			bfs(zhen[zhi],x+1);
		}
	}

}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
		map[b][a]=1;
	}
	cout<<1<<" ";
	bfs(1,1);
	return 0;
}
