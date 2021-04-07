#include <cstdio>
#include <algorithm>
using namespace std;
int n,d[100001];
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int ans=0,pre=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&d[i]);
		if(d[i]>pre)
			ans+=d[i]-pre;
		pre=d[i];
	}
	printf("%d",ans);
	return 0;
}
