#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
#define nc getchar
using namespace std;
const int N = 5005;
vector < int > g[N];
inline void read(int &x) {
	char b = nc(); x = 0;
	for (; !isdigit(b); b = nc());
	for (; isdigit(b); b = nc()) x = x * 10 + b - '0';
}
int n, m, s[N], vis[N];
struct A {
	void dfs(int u) {
		vis[u] = 1; s[++m] = u;
		for (int v, i = 0; i < g[u].size(); ++i) {
			v = g[u][i];
			if (!vis[v]) dfs(v);
		}
	}
	void main() {
		m = 0;
		dfs(1);	
	}
};
struct B {
	int tot, onc[N];
	void cir(int u, int f) {
		if (vis[u]) {
			for (int i = tot; i >= 1; --i) {
				onc[s[i]] = 1;
				if (s[i] == u) break;
			}
			return;
		}
		vis[u] = 1; s[++tot] = u;
		for (int v, i = 0; i < g[u].size(); ++i) {
			v = g[u][i];
			if (v != f) {
				cir(v, u);
			}
		}
		vis[u] = 0; --tot;
	}
	int c, bt;
	void dfs(int u) {
		vis[u] = 1; s[++tot] = u;
		if (c == 0 && onc[u]) {
			int f = 0;
			for (int v, i = 0; i < g[u].size(); ++i) {
				v = g[u][i];
				if (onc[v]) ++f;
				if (f == 2) {
					bt = v;
					break;
				}
			}
			c = 1;
		}
		
		if (bt) for (int v, i = 0; i < g[u].size(); ++i) {
			v = g[u][i];
			if (!vis[v]) {
				if (bt < v) {
					bt = 99999;
					return;
				} else dfs(v);
			}
		}
		else for (int v, i = 0; i < g[u].size(); ++i) {
			v = g[u][i];
			if (!vis[v]) dfs(v);
		}
	}
	void main() {
		memset(this, 0, sizeof(*this));
		cir(1, 1);
		tot = 0;
		dfs(1);
	}		
};
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n); read(m);
	for (int u, v, i = 0; i < m; ++i) {
		read(u); read(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	for (int i = 1; i <= n; ++i)
		sort(g[i].begin(), g[i].end());
	if (m == n - 1) (new A)->main();
	else (new B)->main();	
	for (int i = 1; i <= n; ++i)
		printf("%d ", s[i]);
	return 0;
}
