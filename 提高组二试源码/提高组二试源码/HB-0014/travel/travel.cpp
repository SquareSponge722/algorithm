#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e3 + 5;
inline int read() {
	register int  x = 0, f = 1; register char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

vector<int> G[maxn];
inline void add(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}
int fa[maxn], n, m;
vector<int> seq;
void dfs(int u, int fat, int cnt) {
//	printf("%d\n", u);
	if (cnt == n) {
		exit(0);
	}
	if (!fa[u]) {
		seq.push_back(u);
		fa[u] = fat;
		for (int i = 0; i < G[u].size(); i++) {
			dfs(G[u][i], u, cnt + 1);
		}
	}
	else {
		if (u != 1)
		dfs(fa[u], fa[fa[u]], cnt);
	}
	return;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= m; i++) add(read(), read());
	for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	dfs(1, 1, 1);
/*
	for (int u = 1; u <= n; u++) {
		for (int i = 0; i < G[u].size(); i++) printf("%d ", G[u][i]);
		printf("\n");
	}
*/
	for (vector<int>::iterator it = seq.begin(); it != seq.end(); it++) {
		printf("%d ", *it);
	}
	return 0;
}

