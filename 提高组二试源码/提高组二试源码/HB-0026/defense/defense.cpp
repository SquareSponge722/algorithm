#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}

const int maxn = 1e5 + 10;
typedef long long ll;

ll _p[maxn];
ll oo = ll(1e18);

namespace GG {

ll f[maxn << 2][4];

#define ls p << 1
#define rs p << 1 | 1

ll min(ll a, ll b, ll c, ll d) {
	return std::min(std::min(a, b), std::min(c, d));
}

void maintain(int p) {
	f[p][0] = min(
		f[ls][0] + f[rs][1],
		f[ls][2] + f[rs][0],
		f[ls][2] + f[rs][1],
		oo
	);
	f[p][1] = min(
		f[ls][1] + f[rs][1],
		f[ls][3] + f[rs][0],
		f[ls][3] + f[rs][1],
		oo
	);
	f[p][2] = min(
		f[ls][0] + f[rs][3],
		f[ls][2] + f[rs][2],
		f[ls][2] + f[rs][3],
		oo
	);
	f[p][3] = min(
		f[ls][1] + f[rs][3],
		f[ls][3] + f[rs][2],
		f[ls][3] + f[rs][3],
		oo
	);
}

void build(int p, int l, int r) {
	if (l == r) {
		f[p][0] = 0;
		f[p][1] = f[p][2] = oo;
		f[p][3] = _p[p];
	}
	else {
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		maintain(p);
	}
}

void update(int p, int l, int r, int a, int x) {
	if (l == r) {
		f[p][0] = 0;
		f[p][3] = _p[p];
		if (x < 2) f[p][x ^ 1] = 0;
	} else {
		int mid = l + r >> 1;
		if (a <= mid) update(ls, l, mid, a, x);
		else update(rs, mid + 1, r, a, x);
		maintain(p);
	}
}

void solve(int n, int m) {
	build(1, 1, n);
	while (m--) {
		int a = read(), x = read(), b = read(), y = read();
		update(1, 1, n, a, x);
		update(1, 1, n, b, y);
		ll ans = min(f[1][0], f[1][1], f[1][2], f[1][3]);
		if (ans > ll(1e16)) puts("-1");
		else printf("%lld\n", ans);
		update(1, 1, n, a, 2);
		update(1, 1, n, b, 2);
	}
}
	
}

vector<int>G[maxn];

ll f[maxn][2];



int a, b, x, y;

void dfs(int u, int fa) {
	f[u][0] = 0;
	f[u][1] = _p[u];
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == fa) continue;
		dfs(v, u);
		f[u][0] += f[v][1];
		f[u][1] = min(f[u][1] + f[v][0], f[u][1] + f[v][1]);
	}
	if (u == a) f[u][x ^ 1] = oo;
	if (u == b) f[u][y ^ 1] = oo;
}
/*
5 5 A
2 1 4 1 3
1 2
2 3
3 4
4 5
1 0 2 0
1 0 3 0
2 0 3 1
1 1 5 1
3 1 4 0

*/

int main() {	
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int n = read(), m = read();
	string type; cin >> type;
	if (type[0] != 'A' || n <= 10000) {
		for (int i = 1; i <= n; i++) _p[i] = read();
		for (int i = 1; i <= n - 1; i++) {
			int u = read(), v = read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		while (m--) {
			a = read(), x = read(), b = read(), y = read();
			dfs(1, -1);
			ll ans = min(f[1][0], f[1][1]);
			if (ans > ll(1e16)) puts("-1");
			else printf("%lld\n", ans);
		}
		return 0;
	} else GG::solve(n, m);
	return 0;
}
