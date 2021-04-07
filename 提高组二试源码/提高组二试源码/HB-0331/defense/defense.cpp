#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100005;
int n, m, w[N];
vector < int > g[N];
char type[10];
int a, b, x, y;
typedef long long ll;
ll dp[N][2];
inline ll min(ll a, ll b, ll c) {
	return min(a, min(b, c));
}
void dfs(int u, int f) {
	int isleaf = 1;
	for (int v, i = 0; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v != f) {
			dfs(v, u);
			isleaf = 0;
		}
	}
	if (isleaf) {
		dp[u][1] = w[u];
		dp[u][0] = 0;
	} else {
		dp[u][1] = w[u];
		dp[u][0] = 0;
		for (int v, i = 0; i < g[u].size(); ++i) if ((v = g[u][i]) != f) {
			dp[u][1] += min(dp[v][0], dp[v][1]);
			dp[u][0] += dp[v][1];
		}
	}
	if (u == a) {
		if (x) {
			dp[u][0] = 1e16;
		} else {
			dp[u][1] = 1e16;
		}
	}
	if (u == b) {
		if (y) {
			dp[u][0] = 1e16;
		} else {
			dp[u][1] = 1e16;
		}
	}
}
void solve() {
	if (x == 0 && y == 0) {
		for (int i = 0; i < g[a].size(); ++i) {
			if (g[a][i] == b) {
				printf("-1\n"); return;
			}
		}
	}
	dfs(1, 0);
	printf("%lld\n", min(dp[1][0], dp[1][1]));
}
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &n, &m, type);
	for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
	for (int u, v, i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &a, &x, &b, &y);
		solve();
	}
	return 0;
}
