#include<cstdio>
int a[100100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,sum=0,r=0,i=1,x,s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(r<=1)
	{
		for(int k=1;k<=n;k++)
			if(a[k]==0) s++;
		if(s==n)	{printf("%d",sum);return 0;}
		s=0;
		if(a[i]==0)	{i++;continue;}
		if(a[i]!=0)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]==0)	break;
				else a[j]--;
			}
			sum++;
		}
	}
	return 0;	
}
