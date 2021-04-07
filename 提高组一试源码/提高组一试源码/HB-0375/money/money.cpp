#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,m,total=0;
	int a[1001];
	a[1001]=0;
	scanf("%d",&m);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]%a[j]!=0)
				total++;
		}
	}
	if(total==n*n-n)
		printf("%d",total);
	int max=0,min=99999;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	int bas[1001];
	bas[1001]=0;
	int o,p,q;
	for(int i=0;i<n;i++)
	{
		bas[a[i]]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(bas[i]!=0)
		{
			o=bas[i];
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(bas[i]!=0&&bas[i]!=a)
		{
			p=bas[i];
			break;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(bas[i]!=0)
		{
			q=bas[i];
			break;
		}
	}
	if(o*p-o-p<q)
		printf("2");
	return 0;
}












