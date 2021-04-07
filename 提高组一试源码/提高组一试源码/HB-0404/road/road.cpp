#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int a[1000010];
long long ans;
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=max(a[i-1]-a[i],0);
	}
	ans+=a[n];
	printf("%lld",ans);
	return 0;
}
