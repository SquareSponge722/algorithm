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
int n, m;
vector<pair<int,int> >e[maxn];
int dis[maxn], fa[maxn], g[maxn], f[maxn];
void dfs(int x) {
	for (int i = 0; i < e[x].size(); ++i) {
		int v = e[x][i].first;
		if (!dis[v]) { dis[v] = dis[x] + e[x][i].second, dfs(v); }
	}
}
IL void Solve1() {
	for (int i = 1; i < n; ++i) {
		int x = read(), y = read(), w = read();
		e[x].push_back(make_pair(y, w)); 
		e[y].push_back(make_pair(x, w));
	}
	memset(dis, 0, sizeof dis);
	dfs(1);
	int S1; int maxdis = 0;
	for (int i = 1; i <= n; ++i) if (dis[i] > maxdis) maxdis = dis[i], S1 = i;
	memset(dis, 0, sizeof dis);
	dfs(S1);
	int E1; maxdis = 0;
	for (int i = 1; i <= n; ++i) if (dis[i] > maxdis) maxdis = dis[i], E1 = i;
	printf("%d", maxdis);
}

int Chk, Rtn;
void dp(int x) {
	f[x] = 0, g[x] = 0;
	for (int i = 0; i < e[x].size(); ++i) {
		int v = e[x][i].first; int w = e[x][i].second;
		if (fa[x] == v) continue;
		fa[v] = x, dp(v);
		if (f[v] + w > f[x]) {
			g[x] = f[x]; f[x] = f[v] + w;
		}
		else if (f[v] + w > g[x]) {
			g[x] = f[v] + w;
		}
	}
	if (f[x] >= Chk && g[x] >= Chk) { Rtn += 2; f[x] = g[x] = 0; }
	else if (f[x] >= Chk && g[x] < Chk) { Rtn++; f[x] = g[x]; g[x] = 0; }
	else if (f[x] + g[x] >= Chk) { Rtn++; f[x] = g[x] = 0; }  
}
bool chk(int x) {
	Chk = x; Rtn = 0;
	dp(1);
	return Rtn >= m;
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(), m = read();
	if (m == 1) {
		Solve1();
		return 0;
	}
	else {
		int L = 1, R = 10000;
		for (int i = 1; i < n; ++i) {
			int x = read(), y = read(), w = read();
			e[x].push_back(make_pair(y, w)); 
			e[y].push_back(make_pair(x, w));
		}
		int ans = 0;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (chk(mid)) L = mid + 1, ans = mid;
			else R = mid - 1;
		}
		printf("%d", ans);
	}
	return 0;
}
/*
5 3
1 2 3
1 3 4
2 4 1
2 5 2
*/
