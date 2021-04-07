//居然是树剖。。毒瘤出题人
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
const ll N=5e5+5;
vector <ll> v[N];
vector <ll> c[N];
ll vis[N];
ll dp[N];
ll n,m;

ll get_int()
{
	ll f=0;
	char ch=getchar();
	while (!isdigit(ch))ch=getchar();
	while (isdigit(ch))f=(f<<3)+(f<<1)+ch-'0',ch=getchar();
	return f;
}

void dfs(ll now)
{
	if (vis[now])return;
	vis[now]=1;
	for (ll i=0; i<v[now].size(); i++)
	{
		dp[now]=max(dp[now],dp[v[now][i]]+c[now][i]);
		dfs(v[now][i]);
	}
	return;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=get_int();
	m=get_int();
	ll minn=(1<<30);
	for (ll i=1; i<n; i++)
	{
		ll x,y,z;
		x=get_int(),y=get_int(),z=get_int();
		v[x].push_back(y);
		v[y].push_back(x);
		c[x].push_back(z);
		c[y].push_back(z);
		minn=max(minn,z);
	}
	if (m==1)
	{
		for (ll i=1; i<=n; i++)
			vis[i]=0,dp[i]=0;

		dfs(1);
		ll ans=0;
		for (ll i=1; i<=n; i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
		return 0;
	}
	if (m==(n-1))
	{
		printf("%d\n",minn);
		return 0;
	}
	printf("%d\n",minn);
	return 0;
}
