#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,book;
int a[100010];

bool brim(int x)
{
	if(x==0 || x==1) return false;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		book=0;int cur=n;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			if(!brim(a[j])) book=1;
		}
		if(book==0)
		{
			printf("%d\n",n);
		}
		else 
		{
			sort(a+1,a+1+n);
			
		}
	}
	return 0;
}
