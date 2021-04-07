#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=100020;
int n,a[N],b[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=a[i]-a[i-1];
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=b[i]>0?b[i]:0;
	printf("%lld\n",ans);
}
