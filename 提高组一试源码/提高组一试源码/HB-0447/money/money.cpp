# include<cstdio>
# include<iostream>
# include<cstring>
# include<algorithm>
# include<cmath>
using namespace std;
int gcd(int x,int y)
{ return y?gcd(y,x%y):x;}
int a[11];
int t,n,k;
int flag[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);int g=3;
		if(n==2)
		{
			if(a[1]<a[2]) swap(a[1],a[2]);
			if(a[1]%a[2]!=0) 
			{
				printf("2\n");
				continue;
			}
			else 
			{
				printf("1\n");
				continue;
			}
		}
		
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j*a[i]<=25000;j++)
					flag[j*a[i]]=true;
			sort(a+1,a+n+1);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
				 k=gcd(a[i],a[j]);
				}	
			if(k)
				printf("%d\n",g);
		}
	}
	return 0;
}
