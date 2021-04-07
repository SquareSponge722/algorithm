#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,a[100001]={0},x=0,y=0,i=0;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	x=a[1],y=a[1];
	for(i=1;i<=n;i++)
	{
		if(a[i]<y) y=a[i];
		else if(a[i]>y)
		{
			ans=ans+x;
			ans=ans-y;
			x=a[i],y=a[i];
		}
	}
	if(x!=0) ans=ans+x;
	printf("%lld",ans);
	return 0;
}
