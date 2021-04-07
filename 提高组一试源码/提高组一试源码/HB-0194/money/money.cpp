#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[105];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,j,i,x;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",a[i]);
		}
	}
	for(i=1;i>=1;i++)
	{
		for(j=1;j<=n;j++)
		{
			x=a[j]*i;
		}
	}
	for(i=0;i>=1;i++)
	{
		if(x!=i) break;
	}
	printf("%d",i);
	fclose(stdin);fclose(stdout);
}


