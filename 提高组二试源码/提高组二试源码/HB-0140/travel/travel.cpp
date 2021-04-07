#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 5;

int n, m, head[maxn], cnt = 1, vis[maxn], fa[maxn], ans[maxn], tmp[maxn], tot;

set<int> G[maxn];

struct Graph {
	int to, nt;
	Graph (int a = 0, int b = 0) {
		to = a; nt = b;
	}
} e[maxn];

inline int read() {
	int x = 0;
	scanf("%d", &x);
	return x;
}

inline int findx(int x) {return x == fa[x] ? fa[x] : fa[x] = findx(fa[x]);}

inline void cmp(int *tmp, int *ans) {
	bool judge = true;
	for(register int i = 1; i <= n && judge; i++)
		if(tmp[i] < ans[i]) judge = false;
		else if(tmp[i] > ans[i]) break;
	if(!judge)
		for(register int i = 1; i <= n; i++) ans[i] = tmp[i];
}

inline void dfs(int now, int fr) {
	tmp[++tot] = now;
	set<int> :: iterator it;
	for(it = G[now].begin(); it != G[now].end(); it++) {
		int v = (*it);
		if(v == fr) continue;
		dfs(v, now);
	}
}

inline bool judge() {
	if(m < n) return true;
	for(register int i = 1; i <= n; i++) fa[i] = i;
	
	for(register int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int x = e[i].to, y = e[i].nt;
		int rtx = findx(x), rty = findx(y);
		if(rtx == rty) return false;
		fa[rtx] = rty;
	} return true;
}

inline void Work() {
	if(!judge()) return;
	tot = 0;
	dfs(1, 1);
	cmp(tmp, ans);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(); m = read();
	
	for(register int i = 1; i <= n; i++) G[i].clear();
	
	for(register int i = 1; i <= m; i++) {
		int x = read(), y = read();
		e[i] = Graph(x, y);
		G[x].insert(y); G[y].insert(x);
	}
	
	/* for(it = G[2].begin(); it != G[2].end(); it++)
		cerr << *it << " "; */
	
	memset(ans, 0x3f, sizeof(ans));
	if(m < n) Work();
	
	if(m >= n) {
		for(register int i = 1; i <= n; i++) {
			int x = e[i].to, y = e[i].nt;
			G[x].erase(y); G[y].erase(x);
			vis[i] = 1; Work(); vis[i] = 0;
			G[x].insert(y); G[y].insert(x);
		}
	}

	for(register int i = 1; i <= n; i++) {
		printf("%d", ans[i]);
		if(i != n) putchar(' ');
	}
		
	return 0;
}
