#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const int S=100100;
int v[S]; int n;
ll ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		if(v[i]-v[i-1]>0)
			ans+=(v[i]-v[i-1]);
	}
	printf("%lld\n",ans);

	return 0;
}

