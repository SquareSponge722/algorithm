#include <bits/stdc++.h>
using namespace std;
#define IL inline
IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f;
}
const int maxn = 1e5 + 10;
const int INF = int(1e9);
char type[5];
int p[maxn];
vector<int>e[maxn];
int f[maxn][2], a, b, curx, cury;
void dp(int x, int fa) {
	f[x][0] = 0; f[x][1] = p[x];
	for (int i = 0; i < e[x].size(); ++i) {
		int v = e[x][i];
		if (v == fa) continue;
		dp(v, x);
		f[x][1] += min(f[v][0], f[v][1]);
		f[x][1] = min(f[x][1], INF);
		f[x][0] += f[v][1];
		f[x][0] = min(f[x][0], INF);
	}
	if (x == a) {
		if (curx) f[x][0] = INF;
		else f[x][1] = INF;	
	}	
	if (x == b) {
		if (cury) f[x][0] = INF;
		else f[x][1] = INF;
	}
}
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	int n = read(), m = read();
	scanf("%s", type);
	for (int i = 1; i <= n; ++i) p[i] = read();
	for (int i = 1; i < n; ++i) {
		int u = read(), v = read();
		e[u].push_back(v); e[v].push_back(u);
	}
	for (int i = 1; i <= m; ++i) {
		a = read(), curx = read();
		b = read(), cury = read();
		dp(1, 0);
		int t = min(f[1][0], f[1][1]);
		if (t == INF) printf("-1\n");
		else printf("%d\n", t);
	}
	return 0;
}	
