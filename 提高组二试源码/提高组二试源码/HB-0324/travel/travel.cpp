#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
	int x,y;
};
struct node a[10001],b;
int n,m;
int e[10001][10001]={0},book[10001]={0},c[10001],s=1,sum[10001]={0};
void dfs(int u)
{
	if(book[u]==1) return;
		c[s]=u;
		printf("%d ",u);
		book[u]=1;
		s=s+1;
	for(int i=1;i<=n;i++)
	{	
		if(e[u][i]==1)
		{
			for(int j=1;j<=s-2;j++)
			{
				for(int k=1;k<=i;k++)
				{
					if(e[c[j]][k]==1&&k<i&&sum[i]>1)
					{
						dfs(k);
					}
				}
			}
			dfs(i);
		}
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		e[a[i].x][a[i].y]=1;
		e[a[i].y][a[i].x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i].x<a[j].x)
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
			else if(a[i].x=a[j].x)
			{
				if(a[i].y<a[j].y)
				{
					b=a[i];
					a[i]=a[j];
					a[j]=b;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(e[i][j]==1)
			{
				sum[i]++;
			}
		}
	}
	dfs(1);
	return 0;
}