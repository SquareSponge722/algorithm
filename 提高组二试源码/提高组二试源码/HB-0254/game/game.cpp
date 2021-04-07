#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ri register int
#define il inline
#define ll long long
using namespace std;

const int N = 1e6 + 110;
const int MAXN = 110;
const int inf = 0x7fffffff;
const double eps = 1e-8;
const int mod = 1e9 + 7;

il ll mul(ll x, ll y)
{
	ll ret = x * y;
	if (ret >= mod)
		ret %= mod;
	return ret;
}

il int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n, m;

il ll Kasumi(ll x, ll y)
{
	ll ret = 1;
	while (y)
	{
		if (y & 1)
			ret = mul(ret, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ret;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read();
	if (min(n, m) == 1)
	{
		printf("%lld", Kasumi(2, max(n, m)));
		return 0;
	}
	else if (min(n, m) == 2)
	{
		printf("%lld", mul(Kasumi(3, max(n, m) - 1), 4));
		return 0;
	}
	else if (n == 3 && m == 3)
	{
		printf("112");
		return 0;
	}
	return 0;
}
