#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std; 
int a[100005],b[100005],flag=0,c[100005];
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,k=2;
	scanf("%d",&n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	c[1]=1;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==1) 
		{
			c[k]=b[i];
			k++;
		}
		if (b[i]==1)
		{
			c[k]=a[i];
			k++;
		}
		for (int j=1;j<=n;j++)
		{
			if (c[j]==a[i]) 
			{
				c[j+1]=b[i];
				break;
			}
			if (c[j]==b[i]) 
			{
				c[j+1]=a[i];
				break;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d",c[i]);
		cout<<" ";
	}
	return 0;
}
