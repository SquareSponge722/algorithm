#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[100100],n,i,j,start=0,end=0,sum=0,flag=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(flag==1)
	{
		for(i=1;i<=n;i++)
		{
			if(start==0 && a[i]!=0)
				start=i;
			if(a[i]!=0) 
				end=i;
			if(a[i+1]==0 && start!=0 && end!=0)
			{
				for(j=start;j<=end;j++)
					a[j]--;
				sum++;
				break;
			}
		}
		start=0;
		end=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				flag=1;
				break;
			}
			else 
				flag=0;
		}
	}
	printf("%d",sum);
	return 0;
}