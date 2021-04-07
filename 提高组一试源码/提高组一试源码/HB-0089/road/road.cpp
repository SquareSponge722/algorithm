#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<set>
#include<stack>

using namespace std;

int d[100000];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,node,sdays=0;
	int k = 10000000;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&d[i]);
	}
	for(int i = 0;i < n;i++)
	{
		if(d[i] != 0){
			d[i]=d[i] - 1;		//填坑一次 
			if(i == n)
				{
					sdays++;
				}
			}
	for(int i = 0;i < n;i++)
	{
		if(d[i] != 0)
		{
			if(d[i] < k)
			{
				k = d[i];		//k为最小值 
			}
			for(int i = 0;i < n;i++)
			{
				d[i]=d[i] - 1;		//填坑一次 
				if(i == n)
				{
					sdays++;
				}
			}
		}
		else
		{
			node = d[i];
			sdays += node;
		}
	}
	}
	printf("%d",sdays);
	return 0;
}



/*
			for(int i = 0;i < n;i++)
			{
				d[i]=d[i] - 1;		//填坑一次 
				if(i == n)
				{
					sdays++;
				}
			}
*/






