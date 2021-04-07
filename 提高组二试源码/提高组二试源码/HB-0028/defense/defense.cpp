#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
#define M 101001
using namespace std;
int n,m,u,v,r[5050][5050],p[3000010],used[3000010],a,x,b,y,ans=99999999;
char c1,c2;
void dfs(int a,int x,int temp)
{
	if (temp>ans)
	{
		return;
	}
	if (a==b && x!=y)
	{
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (r[a][i]==1 && used[i]==0)
		{		
			dfs(i,1,temp+p[i]);
			if (x==1)
			{
				dfs(i,0,temp);
			}
		}
	}
	ans=min(ans,temp);
}
int main()
{
	scanf("%d %d %c%c",&n,&m,&c1,&c2);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d %d",&u,&v);
		r[u][v]=1;
		r[v][u]=1;
	}
	for (int j=1;j<=m;j++)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if (r[a][b]==1 && x==0 && y==0)
		{
			ans=-1;
		}
		else
		{
			used[a]=1;
			dfs(a,x,p[a]);
		}
		printf("%d\n",ans);
	}
}
