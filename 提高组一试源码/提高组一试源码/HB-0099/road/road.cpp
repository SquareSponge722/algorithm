#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;
const int N=3e5;
typedef long long ll;
ll a[N],b[N],l=1,r=1,ans;
set<ll>vis;
int main()
{	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
		{
			if (a[i]<=a[i-1]) r++;
			else
				{	if (!vis.count(a[l]))
					ans+=a[l],vis.insert(a[l]);
					l=r=i;
				}
		}
	printf("%lld",ans);
	return 0;
}
/*
6
4 3 2 5 3 5
*/
