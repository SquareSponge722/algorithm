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

int T, n;
int a[N];
bool flag[N], vis[N];
bool f;

il void DFS(int now, int foo, int id)
{
	if (now > a[id] || foo == id)
		return;
	if (f)
		return;
	for (ri i = 0; now + a[foo] * i <= a[id]; i++)
	{
		if (now + a[foo] * i == a[id])
		{
			f = 1;
			return;
		}
		DFS(now + a[foo] * i, foo + 1, id);
	}
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	T = read();
	while (T--)
	{
		memset(flag, 0, sizeof(flag));
		memset(a, 0, sizeof(a));
		f = 0;
		n = read();
		for (ri i = 1; i <= n; i++)
			a[i] = read();
		sort(a + 1, a + 1 + n);
		int ans = n;
		for (ri i = 1; i <= n; i++)
		{
			f = 0;
			DFS(0, 1, i);
			if (f)
			{
				flag[i] = 1;
				ans--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17

*/
