#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n,i,y,x,a[5001][5001]={0},j,book[5005]={0},sum=2,flag=0,sunb[5005]={0};
void dfs(int tx)
{
	if(sum==m+1)
		return ;
	for(i=1;i<=m;i++)
	{
		if(a[tx][i]==1)
		{
			for(j=1;j<=sum;j++)
			{
				if(book[j]==i)
					flag=1;
			}
			if(flag==0)
			{
				sunb[tx]=i;
				book[sum]=i;
				sum++;
				dfs(i);
			}
			flag=0;
			if(tx!=book[sum-1])
				i=sunb[tx];
				
		}
	}
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	book[1]=1;
	dfs(1);
	for(i=1;i<=m;i++)
	{
		printf("%d ",book[i]);
	}
	return 0;
}