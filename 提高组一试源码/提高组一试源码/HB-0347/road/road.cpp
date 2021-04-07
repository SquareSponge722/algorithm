#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],d;
int road(int b,int e)
{
	if(b>e)
	return 0;
	for(int i=b;i<=e;i++)
	{
		if(a[i]==0)
		{
			road(b,i-1);
			road(i+1,e);
			return 0;
		}
	}
	for(int j=b;j<=e;j++)
	{
		a[j]--;
	}
	d++;
	road(b,e);
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	road(1,n);
	printf("%d",d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
