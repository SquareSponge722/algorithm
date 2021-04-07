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

int n, m, cnt;
int head[N];
bool foo = 1;

struct edge
{
	int to, nxt, weight;
};
edge e[N];

il void add_edge(int u, int v, int w)
{
	e[++cnt] = (edge) {v, head[u], w};
	head[u] = cnt;
}
il void Insert(int u, int v, int w)
{
	add_edge(u, v, w);
	add_edge(v, u, w);
}

namespace Brute_Force1
{
	int ans = 0, st = 0;
	
	il void DFS(int x, int pre, int now)
	{
		if (now > ans)
			ans = now, st = x;
		for (ri i = head[x]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (v == pre)
				continue;
			DFS(v, x, now + e[i].weight);
		}
	}

	il void main()
	{
		DFS(1, 1, 0);
		ans = 0;
		DFS(st, st, 0);
		printf("%d\n", ans);
	}
}

namespace Brute_Force2
{
	int a[N];
	int ans;
	
	il void DFS(int now, int last, int ViXbob)
	{
		if (now > m)
		{
			ans = max(ans, ViXbob);
			return;
		}
		int bar = 0;
		for (ri i = last + 1; i < n - m + now; i++)
		{
			bar += a[i];
			if (bar > ViXbob)
				DFS(now + 1, i, ViXbob);
			else
				DFS(now + 1, i, bar);
		}
	}
	il void main()
	{
		for (ri i = 1; i < 2 * n - 1; i += 2)
			a[(i + 1) / 2] = e[i].weight;
		DFS(1, 0, inf);
		printf("%d", ans);
	}
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(), m = read();
	for (ri i = 1; i < n; i++)
	{
		int u = read(), v = read(), w = read();
		if (v != u + 1)
			foo = 0;
		Insert(u, v, w);
	}
	if (m == 1)
	{
		Brute_Force1 :: main();
		return 0;
	}
	else if (n <= 100 && foo)
	{
		Brute_Force2 :: main();
		return 0;
	}
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7

6 3
1 2 2
2 3 4
3 4 5
4 5 1
5 6 8

*/
