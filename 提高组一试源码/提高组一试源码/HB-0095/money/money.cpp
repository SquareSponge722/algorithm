#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;
long long T,n,a[100005];
int main() 
{
	freopen("money.in",r,"stdin")
	freopen("money.out",w,"stdout")
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int sum=n;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) continue;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]%a[i]==0)
				{
					sum--;
					a[j]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) continue;
			else
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==0) continue;
					else
					{
						for(int k=j+1;k<=n;k++)
						{
							if(a[k]==0) continue;
							else
							{
								for(int m=1;m<=100;m++)
								{
									if(a[i]*m>a[k]) break;
									else
									{
										for(int l=1;l<=100;l++)
										{
											if(a[i]*m+a[j]*l==a[k])
											{
												a[k]=0;
												sum--;
												break;
											}
											else if(a[i]*m+a[j]*l>a[k]) break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
