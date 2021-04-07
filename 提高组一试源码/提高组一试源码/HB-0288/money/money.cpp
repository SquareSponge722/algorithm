#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define run(a,b,c) for(a=b;a<=c;a++)
using namespace std;//15~20
int a[105];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",a+i);
		}
		if(N==2)
		{
			int b=a[1];
			int c=a[2];
			if(b%c==0||c%b==0)
			{
				printf("1\n");
			}
			else
			{
				printf("2\n");
			}
		}
		if(N==3)
		{
			int b=a[1];
			int c=a[2];
			int d=a[3];
			int ans=3;
			if(b%c==0||b%d==0)
			{
				ans--;
				b=9999;
			}
			if(c%b==0||c%d==0)
			{
				ans--;
				c=9999;
			}
			if(d%b==0||d%c==0)
			{
				ans--;
				d=9999;
			}
/*			int book=0;
			for(int i=1;i<=1000;i++)
			{
				for(int j=1;j<=1000;j++)
				{
					if(d%(b*i+c*j)==0)
					{
						book=1;
						d=9999;
						printf("%d =%d +%d",d,b*i,c*j);
						break;
					}
				}
			}
			if(book=1)
			{
				ans--;
			}
			book=0;
			for(int i=1;i<=1000;i++)
			{
				for(int j=1;j<=1000;j++)
				{
					if(c%(d*i+b*j)==0)
					{
						book=1;
						c=9999;
						printf("%d =%d +%d",c,d*i,b*j);
						break;
					}
				}
			}
			if(book=1)
			{
				ans--;
			}
			book=0;
			for(int i=1;i<=1000;i++)
			{
				for(int j=1;j<=1000;j++)
				{
					if(b%(d*i+c*j)==0)
					{
						book=1;
						b=9999;
						printf("%d =%d +%d",b,d*i,c*j);
						break;
					}
				}
			}
			if(book=1)
			{
				ans--;
			}
			*/
			printf("%d\n",ans);
		}
		if(N!=2&&N!=3)
		{
			printf("%d\n",N);
		}
	}
	return 0;
}
