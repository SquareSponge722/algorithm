#include<iostream>
#include<cstdio>
using namespace std;
const int maxx=50010;
int f[maxx],dis[maxx*5],head[maxx*5],tot=0;
int n,m,g[2001][2001];
bool vis[maxx];
struct data
{
	int x,y,z;
}a[maxx];
int getf(int x)
{
	if(f[x]==x) return x;
	f[x]=getf(f[x]);
	return f[x];
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[x][y]=z;
		g[y][x]=z;
	}
	return 0;
}
