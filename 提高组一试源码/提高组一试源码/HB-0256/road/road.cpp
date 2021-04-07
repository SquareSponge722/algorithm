#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100001
using namespace std;
int a[N],n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
	if(a[i]!=a[n])
	{
		printf("%d\n",a[n]+a[i]);
		return 0;
	}
}
