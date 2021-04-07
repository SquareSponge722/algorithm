#include <bits/stdc++.h>
using namespace std;
#define IL inline
IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f;
}
const int mod = 1e9 + 7;
IL int pls(int x, int y) { x += y; return x >= mod ? x - mod : x; }
IL int mul(int x, int y) { return 1ll * x * y % mod; }
IL int fpw(int x, int y) {
	int r = 1;
	for (; y; y >>= 1, x = mul(x, x))
		if (y & 1) r = mul(r, x);
	return r;
}
int n, m;
int bit1[10], bit2[10];
bool cmp(int x, int y) {
	int t2 = 0;
	while (x) {
		bit1[++t2] = (x & 1);
		x >>= 1;
	}
	int t1 = 0;
	while (y) {
		bit2[++t1] = (y & 1);
		y >>= 1;
	}
	
	for (int i = 1; i < n; ++i) {
		if (bit1[i + 1] > bit2[i]) return false;
	}
	for (int i = 1; i <= n; ++i) bit1[i] = bit2[i] = 0;
	return true;
}
const int maxn = 1e6 + 10;
int f[(1 << 8) + 10], g[(1 << 8) + 10];
int mp[4][4], dfsans;
bool chk() {
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (mp[i][j] < mp[i - 1][j + 1]) return false;
		}
	}
	return true;
}
void dfs(int x, int y) {
	if (x == n + 1) { if (chk()) dfsans++; return; }
	int nxty = y + 1;
	int nxtx = x;
	if (nxty > m) nxtx++, nxty = 1;
	mp[x][y] = 1;
	dfs(nxtx, nxty);
	mp[x][y] = 0;
	dfs(nxtx, nxty);
}	
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	n = read(), m = read();
	if (n <= 3 && m <= 3) {
		dfs(1, 1);
		cout << dfsans;
		return 0;
	}
	for (int i = 0; i < (1 << n); ++i) f[i] = 1;
	for (int i = 2; i <= m; ++i) {
		memcpy(g, f, sizeof (g));
		memset(f, 0, sizeof (f));
		for (int j = 0; j < (1 << n); ++j) {
			for (int k = 0; k < (1 << n); ++k) {
				if (cmp(j, k)) {
					f[j] = pls(f[j], g[k]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) ans = pls(ans, f[i]);
	cout << ans << endl;
	return 0;
}
