#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#define NO 1005
#define INF 0x3f3f3f3f
#define p pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
typedef long long ll;
typedef double db;
//by Oliver
using namespace std;
ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while(ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while(ch >= '0' && ch <= '9')
		ans *= 10, ans += ch - '0', ch = getchar();
	if(ch == '-')
		return -ans;
	return ans;
}
//head

ll n, last, ans;
//variable

void init()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
}
//functions

int main()
{
	init();
	last = 0;
	for(int i = 1; i <= n; i++)
	{
		ll x = read();
		if(x > last)
			ans += (x - last);
		last = x;
	}
	printf("%lld\n", ans);
	return 0;
}
//main
