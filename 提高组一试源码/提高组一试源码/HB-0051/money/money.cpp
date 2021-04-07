#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		int n,m;
		scanf("%d",&n);
		m=n;
		for(int i=1;i<=n;i++)
			a[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(n==2)
		{
			if(a[2]%a[1]==0)
				printf("1\n");
			else
				printf("2\n");
		}
		if(n==3)
		{
			if(a[2]%a[1]==0)
			{
				if(a[3]%a[1]!=0)
					printf("2\n");
				else
					printf("1\n");
			}
			else
			{
				int t=gcd(a[1],a[2]),flag=0;
				a[1]/=t;
				a[2]/=t;
				if(a[3]>a[1]*a[2]-a[1]-a[2])
					printf("2\n");
				else
				{
					for(int i=0;i<a[2];i++)
					{
						for(int j=0;j<a[1];j++)
							if(a[3]==a[1]*i+a[2]*j)
							{
								printf("2\n");
								flag=1;
								break;
							}
						if(flag)
							break;
					}
					if(!flag)
						printf("3\n");
				}
			}
		}
	}
	return 0;
}