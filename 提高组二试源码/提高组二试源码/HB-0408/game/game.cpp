#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define N 5010
using namespace std;

int n, m, tot, ans[N];
bool vis[N];
struct node {
	int a, b;
	bool operator < (const node &x) const {
		return a == x.a ? b < x.b : a < x.a;
	}
} g[N];
vector<int> v[N];

inline void read(int &x) {
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
}

inline void dfs(int x) {
	if (vis[x])
		return;
	vis[x] = 1, ans[tot++] = x;
	for (int i = 0; i < v[x].size(); ++i)
		dfs(v[x][i]);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; ++i) {
		read(g[i].a), read(g[i].b);
		if (g[i].a < g[i].b)
			swap(g[i].a, g[i].b);
	}
	sort(g + 1, g + m + 1);
	for (int i = 1; i <= m; ++i) {
		v[g[i].a].push_back(g[i].b);
		v[g[i].b].push_back(g[i].a);
	}
	dfs(1);
	printf("%d", 1);
	for (int i = 1; i < n; ++i)
		printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
