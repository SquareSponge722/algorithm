#include<cstdio>
#include<iostream>
int n;
int a[1000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int max=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(max<a[i])
		{
			max=a[i];
		}
	}
	int r=0;int t;
	for(int j=0;j<max;j++)
	{
		if(a[0]>1)
		{
			t=1;
		}
		else t=0;
		for(int i=1;i<n;i++)
		{
			if((a[i-1]==0)&&(a[i]>0))
			t++;printf("%d",t);
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]>0)
			{
				a[i]--;
			}
			r+=t;
		}
	}
	printf("%d",n);
	return 0;
}
