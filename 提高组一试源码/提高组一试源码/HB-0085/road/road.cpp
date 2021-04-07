#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll maxn = 100010,inf = 0x7ffffff;
ll n,a[maxn],ans,minn = inf;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld",&n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    minn = a[1];
    ans = a[1];
    for (ll i = 2; i <= n; i++)
    {
        if (a[i] <= minn)
            minn = a[i];
        else
        {
            ans += a[i] - minn;
            minn = a[i];
        }
    }
    printf("%lld\n",ans);

    return 0;
}
