#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 5e4 + 5;
const int inf = 0x3f3f3f3f;
inline int read() {
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

struct Edge {
	int from, to, cost, has;
	Edge (int u, int v, int w, int has = 0) {
		this->from = u, this->to = v, this->cost = w, this->has = w * ((from + 1000000007) / to);
	}
	bool operator <(const Edge b) const {return has < b.has;}
};
vector<Edge> E;
vector<int> G[maxn];
inline void add(int u, int v, int w) {
	E.push_back(Edge(u, v, w));
	E.push_back(Edge(v, u, w));
	register int M = E.size();
	G[u].push_back(M - 2);
	G[v].push_back(M - 1);
}

int n, m, vis[maxn], M, res;
set<Edge> s;
void dfs(int u, int fa, int cur, int cnt) {
	for (int i = 0; i < G[u].size(); i++) {
		Edge &e = E[G[u][i]];
		if (!s.count(e) && e.to != fa) {
			s.insert(e), s.insert(E[G[u][i] ^ 1]);
			vis[e.to]++;
//			printf("	to %d\n", e.to);
			dfs(e.to, u, cur + e.cost, cnt);
//			printf("	Returned from %d\n", e.to);
			--vis[e.to];
			s.erase(e);
			if (s.count(E[G[u][i] ^ 1])) s.erase(E[G[u][i] ^ 1]);
		}
	}
	M = min(M, cur);
	if (cnt < m - 1)
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
//			printf("New road starts at P %d:\n", i);
			vis[i]++;
			dfs(i, i, 0, cnt + 1);
//			printf("  Road terminated at P %d\n", u);
			--vis[i];
		}
	res = max(res, M);
//	printf("  RES = %d, at P %d\n", res, u);
	return;
}

int dep[maxn], _t, _s;
inline int bfs(int s) {
	memset(dep, 0, sizeof(dep));
	dep[s] = 0;
	queue<int> q;
	q.push(s);
	int maxd = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			Edge &e = E[G[u][i]];
			if (!dep[e.to] && e.to != s) {
				dep[e.to] = dep[u] + e.cost;
				q.push(e.to);
				if (maxd < dep[e.to]) {
					maxd = dep[e.to];
					_t = e.to;
				}
			}
		}
	}
	return maxd;
}

inline int getd(int s) {
	bfs(s);
	_s = _t;
	return bfs(_s);
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(), m = read();
	for (register int i = 1; i < n; i++) {
		register int u = read(), v = read(), w = read();
		add(u, v, w);
	}
	if (m == 1) {
		printf("%d", getd(1));
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		M = inf, res = 0, vis[i] = 1;
//		printf("Rarely new start point %d:\n", i);
		dfs(i, i, 0, 0);
	}
	printf("%d", res);
	return 0;
}
