#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#define NO 1000005
#define P 1000000007
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
	if(last == '-')
		return -ans;
	return ans;
}
//head

int n, m, cnt[NO];
//variable

ll fast(ll x, ll y)
{
	ll base = x, ans = 1;
	while(y)
	{
		if(y % 2)
			ans *= base, ans %= P;
		base *= base;
		base %= P;
		y /= 2;
	}
	return ans % P;
}
void init()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read();
}
//functions

int main()
{
	init();
	if(n == 1)
	{
		printf("%d\n", fast(2, m));
		return 0;
	}
	if(m == 1)
	{
		printf("%d\n", fast(2, n));
		return 0;
	}
	if(m == 2)
	{
		printf("%d\n", fast(3, n - 1) * 4 % P);
		return 0;
	}
	if(n == 2)
	{
		printf("%d\n", fast(3, m - 1) * 4 % P);
		return 0;
	}
	if(n == 3)
	{
		ll tot = fast(4, m - 2) * 4 % P * 9 % P, temp = 0;
		for(int i = m - 1; i >= 2; i--)
			cnt[i] = ((ll)cnt[i + 1] * 2 % P + fast(3, m - i - 1)) % P, temp += (ll)cnt[i] * 4 % P * fast(2, i - 1) % P, temp %= P;
		printf("%d\n", ((tot - 4 * (ll)temp % P) % P + P) % P);
		return 0;
	}
	return 0;
}
//main                 
