#include<cstdio>
using namespace std;
int c[10001][10001];
int a,b[100001],sum=1,d[10001],book1=0,book2=0;
int inf=999999999;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b[i]);
		d[i]=b[i];
		c[1][i]=b[i];
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(d[i]>d[j])
			{
				int t;
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
		}
	}
		for(int i=1;i<=d[1];i++)
		{
			if(c[i][1]==0)
			{
				c[i][1]=inf;
			}
			if(c[i][a]==0)
			{
				c[i][a]=inf;
			}
			for(int j=2;j<=a-1;j++)
			{
				if(c[i][j]==0)
				{
					for(int k=j;k<=a-1;k++)
					{
						if(c[i][k]==0)
						{
							int num=0;
							num++;
							sum=sum-num+1;
						}
					}
					sum++;
					c[i][j]=inf;
					c[i+1][j]=c[i][j]-1;
				}
				else
				{
					c[i+1][j]=c[i][j]-1;
				}
			}
			sum++;
		}
		if(a=2)
		{
			if(b[1]>b[2])
				printf("%d",b[1]);
			else printf("%d",b[2]);
		}
		else printf("%d",sum);
	return 0;
}
	