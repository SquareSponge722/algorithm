#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
const int INF=999999999;
const int N=100005;
typedef long long ll;
struct node
{
	ll num,pos;
}d[N];
bool cmp(node a,node b)
{
	return a.num<b.num;
}
ll a[N],n,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		d[i].num=a[i];
		d[i].pos=i;
	}
	sort(d+1,d+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		ll pos=d[i].pos;
		ll num=a[pos];
		a[pos]-=num;
		for(ll i=pos-1;i>=1;i--)
		{
			if(a[i]!=0)
				a[i]-=num;
			else
				break;
		}
		for(ll i=pos+1;i<=n;i++)
		{
			if(a[i]!=0)
				a[i]-=num;
			else
				break;
		}
		ans+=num;
	}
	printf("%lld\n",ans);
}
