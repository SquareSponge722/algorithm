#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[100010];
long long fill(int l,int r)
{
	if(l==r)
	{
		long long rt=a[l];
		a[l]=0;
		return rt;
	}
	long long d=20000,ans=0;
	for(int i=l;i<=r;i++)
		d=min(a[i],d);
	int li=l;
	while(!li)l++;
	for(int i=l;i<=r;i++)
	{
		a[i]-=d;
		if(!a[i] && i>li)
		{
			ans+=fill(li,i-1);
			li=i;
		}
	}
	if(a[r] && li+1<=r)ans+=fill(li+1,r);
	ans+=d;
	return ans;
}
int main()
{
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	printf("%lld\n",fill(1,n));
	return 0;
}
