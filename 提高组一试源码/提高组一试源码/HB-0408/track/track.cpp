#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define N 50010
using namespace std;

int n, m, a, b, c, tot, l[N], d[N], f[N][16], ans;
struct node {
	int id, l;
	node(int a, int b) {
		id = a, l = b;
	}
};
vector<node> v[N];

inline void read(int &x) {
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
}

inline void dfs(int x, int len, int dep) {
	l[x] = l[f[x][0]] + len;
	d[x] = dep;
	for (int i = 0; i < v[x].size(); ++i)
		if (v[x][i].id != f[x][0]) {
			f[v[x][i].id][0] = x;
			dfs(v[x][i].id, v[x][i].l, dep + 1);
		}
}

inline int lca(int a, int b) {
	if (d[a] > d[b])
		swap(a, b);
	int dep = d[b] - d[a];
	for (int i = 15; i >= 0 && dep; --i)
		if (dep & (1 << i))
			b = f[b][i], dep -= (1 << i);
	if (a == b)
		return a;
	for (int i = 15; i >= 0; --i)
		if (d[a] > (1 << i) && f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	return f[a][0];
}

inline bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i < n; ++i) {
		read(a), read(b), read(c);
		v[a].push_back(node(b, c));
		v[b].push_back(node(a, c));
		if (b == a + 1)
			++tot;
	}
	dfs(1, 0, 0);
	if (m == 1) {
		int maxn = 0;
		for (int i = 2; i <= n; ++i)
			if (l[i] > maxn)
				maxn = l[i], a = i;
		for (int j = 1; j < 16; ++j)
			for (int i = 2; i <= n; ++i)
				f[i][j] = f[f[i][j - 1]][j - 1];
		for (int i = 1; i <= n; ++i)
			ans = max(ans, l[i] + l[a] - 2 * l[lca(a, i)]);
	} else if (v[1].size() == n - 1) {
		sort(l + 2, l + n + 1, cmp);
		if (m > (n - 1) / 2) {
			ans = l[m * 2 - n + 2];
			for (int i = m * 2 - n + 3; i <= m + 1; ++i)
				ans = min(ans, l[i] + l[i - m * 2 - 3]);
		} else {
			ans = l[2] + l[m * 2 + 1];
			for (int i = 3; i <= m + 1; ++i)
				ans = min(ans, l[i] + l[m * 2 + 3 - i]);
		}
	}
	printf("%d", ans);
	return 0;
}
