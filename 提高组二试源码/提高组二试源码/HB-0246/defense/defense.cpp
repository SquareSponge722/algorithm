#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,m;
int p[100010];
int maze[2010][2010];
string type;
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	if(n<=2000)
	{
		for(int i=1; i<=n; i++) cin>>p[i];
		for(int i=1; i<n; i++)
		{
			int u,v;
			cin>>u>>v;
			maze[u][v]=1;
			maze[v][u]=1;
		}
		int a,b,x,y;
		for(int i=1; i<=m; i++)
		{
			cin>>a>>x>>b>>y;
			if(maze[a][b]==1&&(x==0&&y==0)) cout<<"-1"<<endl;
		}
	}
}
