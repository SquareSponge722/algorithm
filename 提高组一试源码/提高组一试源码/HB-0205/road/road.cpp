#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
const ll N=1e5+5;
ll sum[N];
ll ans=0;
ll d[N];
ll n;

int main()                   
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for (ll i=1; i<=n; i++)
		sum[i]=0,scanf("%lld",&d[i]);
	sum[1]=d[1];
	for (ll i=2; i<=n; i++)
		sum[i]=d[i]-d[i-1];
	ll ans=0;
	for (ll i=1; i<=n; i++)
		if (sum[i]>0)
			ans+=sum[i];
	printf("%lld\n",ans);
	return 0;
}
