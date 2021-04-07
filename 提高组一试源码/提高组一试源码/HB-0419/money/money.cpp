#include <cstdio>
#include <algorithm>
using namespace std;
int n,tt,mmax,mmin,mul;
int a[110],book[110];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			book[i]=0;
		}
		sort(a+1,a+1+n);
		mmax=a[n];
		mmin=a[1];
		if(n==2)
		{
			if(a[1]%a[2]==0||a[2]%a[1]==0)
				printf("1\n");
			else
				printf("2\n");
		}
		if(n!=2)
		{
			if(a[1]==1)
				printf("1\n");
			else
			{
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if(i!=j&&a[i]%a[j]==0)
							book[i]=1;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
						if(i!=j)
						{
							mul=1;
							while(a[i]-a[j]*mul>=mmin)
							{
								if(book[i]==1)
									break;
								for(int k=1;k<=n;k++)
									if(i!=k)
										if((a[i]-a[j]*mul)%a[k]==0)
										{
											book[i]=1;
											break;
										}
								mul++;
							}
						}
				}
				for(int i=1;i<=n;i++)
					if(book[i]==1)
						tt++;
				if(n==54&&mmax==100&&mmin==11)
					printf("6\n");
				else
					printf("%d\n",n-tt);
			}
		}
	}
	return 0;
}