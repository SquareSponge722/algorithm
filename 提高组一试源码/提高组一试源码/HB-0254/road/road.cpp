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

int n, ans, pos;
int a[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	for (ri i = 1; i <= n; i++)
		a[i] = read();
	for (ri i = 1; i <= n; i++)
		if (a[i] > a[i - 1])
			ans += a[i] - a[i - 1];
	printf("%d", ans);
	return 0;
}
/*
6
4 3 2 5 3 5

*/
