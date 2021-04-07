#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
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

int n, m;
vector <int> vec[N];

namespace Case1
{
	bool flag[N];
	
	il void DFS(int x)
	{
		printf("%d ", x);
		flag[x] = 1;
		for (ri i = 0; i < vec[x].size(); i++)
		{
			if (flag[vec[x][i]])
				continue;
			DFS(vec[x][i]);
		}
	}
	
	il void main()
	{
		for (ri i = 1; i <= m; i++)
		{
			int u = read(), v = read();
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for (ri i = 1; i <= n; i++)
			sort(vec[i].begin(), vec[i].end());
		DFS(1);
	}
}

namespace Case2
{
	int pos, id, top = 0;
	int dfn[N], st[N];
	bool f, foo, flag[N];
	
	il void Tarjan(int x, int pre)
	{
		dfn[x] = ++id;
		st[++top] = x;
		for (ri i = 0; i < vec[x].size(); i++)
		{
			int v = vec[x][i];
			if (v == pre || foo)
				continue;
			if (!dfn[v])
				Tarjan(v, x);
			else
			{
				do {
					pos = max(pos, st[top]);
				} while (st[top--] != v);
				foo = 1;
			}
		}
		top--;
	}
	
	il void Solve(int x, int pre)
	{
		printf("%d ", x);
		flag[x] = 1;
		for (ri i = 0; i < vec[x].size(); i++)
		{
			int v = vec[x][i];
			if (v == pre || flag[v])
				continue;
			if (v == pos && !f && v > vec[x][i + 1])
			{
				f = 1;
				continue;
			}
			Solve(v, x);
		}
	}
	
	il void main()
	{
		for (ri i = 1; i <= m; i++)
		{
			int u = read(), v = read();
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		Tarjan(1, 1);
		for (ri i = 1; i <= n; i++)
			sort(vec[i].begin(), vec[i].end());
		Solve(1, 0);
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(), m = read();
	if (m == n - 1)
	{
		Case1 :: main();
		return 0;
	}
	else
	{
		Case2 :: main();
		return 0;
	}
	return 0;
}
/*
6 5
1 3
2 3
2 5
3 4
4 6

6 6
1 3
2 3
2 5
3 4
4 5
4 6

*/
