#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=100100;
long long n,ans,minn;
long long d[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		if(i==1) minn=d[i];
		else
		{
			if(d[i]<minn)
			{
				ans+=minn-d[i];
				minn=d[i];
			}
			else if(d[i]>minn)
			{
				long long tmp=max((long long)0,d[i]-minn-(d[i-1]-minn));
				ans+=tmp;
			}
		}
	}
	ans+=minn;
	printf("%lld\n",ans);
	return 0;
}
