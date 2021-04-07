#include <bits/stdc++.h>
using namespace std;
#define IL inline
IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f;
}
const int maxn = 5005;
vector<int>e[maxn];
bool vis[maxn]; int ans[maxn], coc;
int from[maxn], cir[maxn], len, inc[maxn];
bool Lfl[maxn];
void dfs(int x) {
	vis[x] = 1; ans[++coc] = x;
	for (int i = 0; i < e[x].size(); ++i) {
		int v = e[x][i];
		if (!vis[v]) dfs(v);
	}
}
int L, R;
void dfs2(int x) {
	if (vis[x]) {
		int u = x;
		do {
			cir[++len] = u; inc[u] = 1;
			u = from[u];
		}while (u != x);
		return;
	}
	vis[x] = 1;
	for (int i = 0; i < e[x].size(); ++i) {
		int v = e[x][i];
		if (from[x] != v) {
			from[v] = x; dfs2(v);
		}
	}
}
int St, last;
priority_queue<int>q;
void Print(int x) {
	ans[++coc] = x;
	vis[x] = 1;
	int Min = INT_MAX;
	if (inc[x] || x == St) {
		for (int i = 0; i < e[x].size(); ++i) {
			int v = e[x][i];
			if (!vis[v] && !inc[v]) {
				q.push(-v);
			}
		}
		if (inc[x] || x == St) {
			if (L <= R) {
				q.push(-cir[L]); Lfl[cir[L]] = 1;
				q.push(-cir[R]);
			}
		}
		while (q.size()) {
			int u = -q.top(); q.pop();
			if (!vis[u]) {
				if (inc[u]) {
					if (Lfl[u]) L++;
					else R--;
				}
				Print(u);	
			}
		}
	}
	else {
		for (int i = 0; i < e[x].size(); ++i) {
			int v = e[x][i];
			if (!vis[v]) Print(v);
		}
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		int x = read(), y = read();
		e[x].push_back(y); e[y].push_back(x);
	}
	if (m == n - 1) {
		for (int i = 1; i <= n; ++i) {
			sort(e[i].begin(), e[i].end());
		}
		dfs(1);
		for (int i = 1; i <= coc; ++i)
			printf("%d ", ans[i]);
		return 0;
	}
	else {
		dfs2(1);
		for (int i = 1; i <= n; ++i) sort(e[i].begin(), e[i].end());
		memset(vis, 0, sizeof (vis));
		inc[cir[1]] = 0; St = cir[1];
		L = 2, R = len;
		Print(1);
		for (int i = 1; i <= coc; ++i)
			printf("%d ", ans[i]);
		return 0;
	}
	return 0;
}
