#include<cstdio>
#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
int a[80][200];
void paixu(int i)
{
	int min=999999,l,temp;
	for(int u=1;u<=a[i][0];++u)
	{
		for(int y=u+1;y<=a[i][0];++y)
		{
			if(min>a[i][y]) min=a[i][y],l=y;
		}
		if(a[i][u]>min)
		{
			temp=a[i][u];
			a[i][u]=a[i][l];
			a[i][l]=temp;
		}
		min=999999;
	}
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,m,k,l=0;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&a[i][0]);
		for(int y=1;y<=a[i][0];++y)
		{
			scanf("%d",&a[i][y]);
		}
	}
	for(int i=1;i<=t;++i)
	{
		paixu(i);
		m=a[i][0];
		for(int u=1;u<=a[i][0];++u)
		{
			for(int y=u+1;y<=a[i][0];++y)
			{
				if(a[i][y]!=0&&a[i][u]!=0) 
				{
					if((a[i][y]%a[i][u])==0) m--,a[i][y]=0;
				}
			}
		}
		for(int u=a[i][0];u>1;--u)
		{
			if(a[i][u]!=0)
			{
				for(int y=2;y<u;++y)
				{
					if(a[i][u]!=0&&a[i][y]!=0) 
					{
						k=(a[i][u]%a[i][y]);
						for(int p=1;p<y;++p)
						{
							if((k%a[i][p])==0)
							{
								l++;
								m--;
								a[i][u]=0;
								break;
							}
						}
					if(l!=0) break;
					}
				}
			}
			l=0;
		}
		printf("%d\n",m);
	}
	return 0;
}
