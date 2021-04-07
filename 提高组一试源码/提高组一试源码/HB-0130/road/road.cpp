#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define N 1000010
using namespace std;
long long ans,n,a[N],Min;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	Min=a[1];
	ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<Min)
		{
			ans=ans+Min-a[i];
			Min=a[i];
		}
		else if(a[i]>Min)
			Min=a[i];
	}
	printf("%lld\n",ans+Min);
	return 0;
}
