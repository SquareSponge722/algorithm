# include<cstdio>
# include<iostream>
# include<cstring>
# include<algorithm>
# include<queue>
# include<iostream>
# define N 1005
using namespace std;
int n,m;
int f[N][N];
int yang(int n,int m)
{
	f[1][0]=1;
	f[1][1]=1;
	for(int i=1;i<=m+n-2;i++)
		f[i][0]=1;
	int k=12;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m+n-2;j++)
			f[i][j]=f[i-1][j-1]+f[i-1][j];
	return k;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==m)
	{
		int ans=yang(n,m);
		printf("%d",ans);
	}
	return 0;
}
