#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5;

int n, m, head[maxn], cnt, judge = 1, judge0 = 1;
int w[maxn], fa[maxn], deep[maxn], in[maxn], root;

struct Graph {
	int to, nt, w;
	Graph (int a = 0, int b = 0, int c = 0) {
		to = a; nt = b; w = c;
	}
	bool operator < (const Graph &t) const {
		return w < t.w;
	}
} e[maxn << 1], t[maxn];

inline int read() {
	int x = 0;
	scanf("%d", &x);
	return x;
}

inline void ini(int x, int y, int w) {e[++cnt] = Graph(y, head[x], w); head[x] = cnt;}

inline void dfs(int now) {
	for(register int i = head[now]; i; i = e[i].nt) {
		int v = e[i].to;
		if(v == fa[now]) continue;
		fa[v] = now; deep[v] = deep[now] + 1;
		w[v] = e[i].w;
		dfs(v);
	}
}

namespace Subtask1 { // m = 1
	int u, d;
	inline void dfs(int now, int fr, int &u, int dis, int &d) {
		if(dis > d) {d = dis; u = now;}
		for(register int i = head[now]; i; i = e[i].nt) {
			int v = e[i].to;
			if(v == fr) continue;
			dfs(v, now, u, dis + e[i].w, d);
		}
	}
	
	inline void work() {
		u = 0; d = 0;
		dfs(1, 1, u, 0, d); d = 0;
		dfs(u, u, u, 0, d);
		cout << d;
	}
}

namespace Subtask2 { // a == 1
	inline void work() {
		sort(t + 1, t + n);
		cout << t[n - m].w;
	}
} 

namespace Subtask3 { // b = a + 1
	int maxd, M;
	
	inline bool check(int mid) {
		int x = M, cnt = 0, nowL = 0;
		while(fa[x] && cnt < m) {
			if(nowL < mid) nowL += w[x];
			else nowL = w[x], cnt++;
			x = fa[x];
		} return cnt >= m;
	}
	
	inline int Biniry(int l, int r) {
		int mid = (l + r) / 2, ans = 0;
		while(l <= r) {
			mid = (l + r) / 2;
			if(check(mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		} return ans;
	}
	
	inline void work() {
		maxd = 0; M = 0;
		
		for(register int i = 1; i <= n; i++)
			if(deep[i] > maxd) {maxd = deep[i]; M = i;}
		
		cout << Biniry(1, int(1e9));
	}
}

namespace Subtask4 {
	inline void work() {
		
	}
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(); m = read();
	
	for(register int i = 1; i < n; i++) {
		int x = read(), y = read(), w = read();
		ini(x, y, w); ini(y, x, w);
		if(x > y) swap(x, y);
		if(x != 1) judge = false;
		if(y != x + 1) judge0 = false;
		t[i] = Graph(x, y, w);
		in[x]++; in[y]++;
	}
	
	for(register int i = 1; i <= n; i++)
		if(in[i] < 2) {root = i; break;}
		
	deep[root] = 1;
	dfs(root);
	
	if(m == 1) Subtask1 :: work();
	else if(judge) Subtask2 :: work();
	else if(judge0) Subtask3 :: work();
	else Subtask4 :: work();
	
	return 0;
}
