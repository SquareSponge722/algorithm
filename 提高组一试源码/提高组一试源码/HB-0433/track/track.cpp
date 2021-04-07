#include<bits/stdc++.h>
using namespace std;
const int mn=1010;
int f[mn][mn],b[mn][mn];
int x,y,z;
int n,m,maxn,l;
void dfs(int x)
{
	int tx,ty;
	if(x==n)
	{
		if(l>maxn) maxn=l;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]!=0&&b[i][j]==0&&b[j][i]==0)
			{
				tx=i;ty=j;
				b[i][j]=1;
				b[j][i]=1;
				l+=f[i][j];
				dfs(ty);
				l-=f[i][j];
			}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	maxn=0;
	cin>>n>>m;
	for(int i=1; i<=n-1; i++)
	{
		cin>>x>>y>>z;
		f[x][y]=z;
		f[y][x]=z;
	}
	for(int i=1; i<=n-1; i++)
		for(int j=i+1; j<=n; j++)
		{
			for(int k=i+1; k<=j-1; k++)
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
			if(f[i][j]>maxn) maxn=f[i][j];//floyedÀ„∑® 
		}
	/*dfs(1);*/
	cout<<maxn;
	return 0;
}
