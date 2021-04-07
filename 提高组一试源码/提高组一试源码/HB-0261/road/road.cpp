#include<cstdio>
#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
int a[100050],book[100050];
int xunzhao(int i,int y)
{
	int l,min=999999;
	for(int p=i;p<=y;++p)
	{
		if(a[p]<min) min=a[p],l=p;
	}
	return l;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,min=1000001,l,k=0,today=0,geshu=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) 
	{
		scanf("%d",&a[i]);
		book[i]++;
	}
	for(;geshu<n;)
	{
		for(int i=1;i<=n+1;i++)
		{
			if(book[i]==0)
			{
				l=xunzhao(k+1,i-1);
				min=a[l];
				for(int u=k+1;u<=i-1;++u)
				{
					a[u]-=min;
					if(a[u]==0) book[u]--,geshu++;
				}
				today+=min;
				k=i;
			}
		}
		k=0;
	}
	printf("%d",today);
	return 0;
}
