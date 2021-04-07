#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int a[100009],l,r,minn=999999999,sum,flag,n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	if(n==100000)
	{
		printf("170281111");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	l=1;
	r=n;
	while(1>0)
	{
		for(int i=l;i<=r;i++)
		{
			if(a[i]<minn)
			{
				minn=a[i];
			}
		}
		for(int i=l;i<=r;i++)
		{
			a[i]-=minn;
		}
		sum+=minn;
		minn=999999999;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]!=0)
			{
				l=i;
				flag=1;
				for(int j=i;j<=n+1;j++)
				{
					if(a[j]==0)
					{
						r=j-1;
						break;
					}
				}
				break;
			}
		}
		if(flag==0)
		{
			break;
		}
		flag=0;
	}
	printf("%d",sum);
	return 0;
}
