#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cstring>
const int N = 5005;
using namespace std;
int n, m, map[N][N], vis[N], fa[N], begin, color[N], biao, ff, fir, k;
stack <int> S;
inline void dfs(int u)
{
	printf("%d ", u);
	for (int i = 1; i <= map[u][0]; i++)
	{
		int v = map[u][i];
		if (!vis[v])
		{
			vis[v] = 1;
			dfs(v);
		}
	}
}
inline void dfs2(int u, int f)
{
	for (int i = 1; i <= map[u][0]; i++)
	{
		int v = map[u][i];
		if (v == f) continue;
		if (!vis[v])
		{
			vis[v] = 1; fa[v] = u; dfs2(v, u);
		}
		else if (vis[v])
			if (!fir) {fir = 1; begin = v; vis[v] = 2; fa[v] = u;}
	}
}
inline void dfs3(int u)
{
	if (color[u] && !ff) {biao = map[u][2]; ff = 1;}
	printf("%d ", u);
	for (int i = 1; i <= map[u][0]; i++)
	{
		int v = map[u][i];
		if (ff && v > biao && !k) {k = 1; return ;}
		if (!vis[v])
		{
			vis[v] = 1; dfs3(v);
		}
	}
}
inline void init()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
}
int main()
{
	init();
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][++map[a][0]] = b; map[b][++map[b][0]] = a;
	}
	for (int i = 1; i <= n; i++) sort(&map[i][1], &map[i][map[i][0] + 1]);
	vis[1] = 1;
	if (m == n - 1)
		dfs(1);
	if (m == n)
	{
		fa[1] = 0;
		dfs2(1, 0);
		color[begin] = 1;
		for (int i = fa[begin]; vis[i] != 2; i = fa[i])
			color[i] = 1;
		memset(vis, 0, sizeof(vis)); vis[1] = 1;
		dfs3(1);
	}
	return 0;
}
