#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
const int N=10001;
long long n;
bool flag;
int visit[N],d[N];
int dfs(long long k)
{
	scanf("%lld",&k);
	long long sum=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&d[i]);
	}
	for(int m=1;m<=k;m++)
	{
		for(int j=0;j<k;j++)
		{
			if(flag)
			{
				j++;
			}
			if(d[j]!=0)
			{
				if(j==k)
				{
					sum++;
					d[j]=d[j]-1;
					break;
				}
				d[j]=d[j]-1;
				j++;
				if(d[j]==0)
				{
					d[j]=false;
					sum++;
					j--;
					break;
				}
				j--;
				if(d[j]==0)
				{
					d[j]=false;
				}
				else
				{
					continue;
				}	
			}
		}
	}
	printf("%d",sum*3);
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("raod,out","w",stdout);	
	dfs(n);
	return 0;
}
