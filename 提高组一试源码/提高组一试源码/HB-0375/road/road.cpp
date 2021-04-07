#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int  dfs(int i,int n,int d[],int total,int mum,int book[])
{
	for(int j=0;j<n;j++)
	{
		if(book[j]==1)
			mum++;
		if(mum==n)
			return total;
	}
	int min=999999;
	for(int j=i;j>=0;j--)
	{
		if(d[j]<d[j+1])
		{
			min=d[j];
	}
	for(int j=i;j>=0;j--)
		d[j]=d[j]-min;
	for(int j=i;j>=0;j--)
	{
		if(d[j]==0)
			book[j]=1;		
	}	 
	for(int j=i;j>=0;j--)
	{
		if(book[j]!=0)
		{
			for(int k=j-1;k>=0;k--)
			{
				if(book[k]!=0)
					dfs(j-1,n,d,total+min,mum,book);
			}
			dfs(j+1,n,d,total+min,mum,book);
		}
	}
}
int main(int argc, char** argv)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int n,total,mum;
	scanf("%d",&n);
	int d[1000001];
	d[1000001]=0;
	int book[1000001];
	book[1000001]=0;
	total=0;
	mum=0;
	for(int i=0;i<n;i++)
		scanf("%d",&d[i]);
	dfs(i,n,d,total,mum,book);
	printf("%d",total);
	return 0;
}














