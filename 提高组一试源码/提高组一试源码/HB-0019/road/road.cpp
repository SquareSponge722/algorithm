#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxx=100010;
int n,a[maxx];
long long sum=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int t=a[i]-a[i-1];
		if(t>=0) sum+=t;
	}
	printf("%lld",sum);
	return 0;
}
