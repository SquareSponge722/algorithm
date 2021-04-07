#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int e[2003][2003]={0},book[2003]={0},money[2003]={0},i,j,q,l,k,h,ans;
int n,m;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int mon,u,v,a,x,b,y;
	char leixing[6];
	scanf("%d%d%s",&n,&m,leixing);
	for(i=1; i<=n; i++)
	{
		scanf("%d",&mon);
		money[i]=mon;
	}
	for(i=1; i<=n-1; i++)
	{
		scanf("%d%d",&u,&v);
		e[u][v]=1;
		e[v][u]=1;
	}
	for(j=1; j<=m; j++)
	{
		ans=0;
		for(l=1; l<=n; l++)
		{
			book[l]=0;
		}
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==0 && y==0 && e[a][b]==1)
		{
			printf("-1");
			printf("\n");
			continue;
		}
		if(x==1)
		{
			ans=ans+money[a];
			book[a]=1;
		}
		if(y==1)
		{
			ans=ans+money[b];
			book[b]=1;
		}
		if(x==0)
		{
			for(i=1; i<=n; i++)
			{
				if(e[a][i]==1 && book[i]==0)
				{
					ans=ans+money[i];
					book[i]=1;
				}
			}
		}
		if(y==0)
		{
			for(k=1; k<=n; k++)
			{
				if(e[b][k]==1 && book[i]==0)
				{
					ans=ans+money[k];
					book[i]=1;
				}
			}
		}
		for(h=1; h<=n; h++)
		{
			if(book[h]==1) continue;
			for(q=1; q<=n; q++)
			{
				if(book[q]==0 && e[h][q]==1)
				{
					if(money[q]>money[h])
					{
						ans=ans+money[h];
						book[h]=0;
					}
					if(money[h]>money[q])
					{
						ans=ans+money[q];
						book[q]=0;
					}
				}
			}
		}
		printf("%d",ans-money[1]);
		printf("\n");
	}
	return 0;
}