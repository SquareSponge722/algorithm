#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxl=5001;
int a[maxl][maxl]={0},b[maxl*maxl];
int n,m,aa,bb,minn=9999999,maxx=0;
int i,j,k,l=1,flag=0;
void dfs(int x,int y)
{
	for(i=y;i<=maxx;i++)
	{
		for(j=minn;j<=maxx;j++)
		{
			if(a[i][j]!=0&&j!=x)
			{
				a[i][j]--;a[j][i]--;
				b[l]=j;l++;
				dfs(i,j);
				a[i][j]++;a[j][i]++;
			}
		}
	}
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	flag=n;
	
	for(i=1;i<=m;i++)
	{
		cin>>aa>>bb;
		if(minn>aa){minn=aa;}
		if(minn>bb){minn=bb;}
		if(maxx<aa){maxx=aa;}
		if(maxx<bb){maxx=bb;}
		a[aa][bb]=1;
		a[bb][aa]=1;
	}
	b[l]=minn;l++;
	dfs(minn,minn);
	for(i=1;i<=n;i++)
	{cout<<b[i]<<" ";}
	return 0;
}
/*
4 4
1 2
1 4
1 3
2 3
*/