#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, head[maxn], cnt = 1, x, tx, y, ty, w[maxn], size[maxn];
LL f[maxn][2];
set<int> G[maxn];

char s[maxn];

struct Graph {
	int to, nt;
	Graph (int a = 0, int b = 0) {
		to = a; nt = b;
	}
} e[maxn << 1];

inline int read() {
	int x = 0;
	scanf("%d", &x);
	return x;
}

inline void ini(int x, int y) {e[++cnt] = Graph(y, head[x]); head[x] = cnt;}

inline void dfs(int now, int fr) {
	f[now][1] = max(1ll * w[now], f[now][1]);
	bool judge = false; int siz = 0;
	LL del = inf;
	for(register int i = head[now]; i; i = e[i].nt) {
		int v = e[i].to;
		if(v == fr) continue;
		siz++; dfs(v, now);
		f[now][1] += min(f[v][1], f[v][0]);
		if(f[v][1] < f[v][0] || !size[v]) {
			f[now][0] += f[v][1];
			judge = true;
		} else {
			f[now][0] += f[v][0];
			del = min(del, f[v][1] - f[v][0]);
		}
	}
	if(!judge && siz > 0)
		f[now][0] += del;
	size[now] = siz;
}

inline LL solve() {
	if(*(G[x].lower_bound(y)) == y && !tx && !ty) return -1;
	memset(f, 0, sizeof(f));
	//memset(df, 0x3f, sizeof(df));
	f[x][!tx] = f[y][!ty] = inf;
	dfs(1, 1);
	return min(f[1][1], f[1][0]); 
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	n = read(); m = read(); scanf("%s", s);
	
	for(register int i = 1; i <= n; i++) w[i] = read();
	
	for(register int i = 1; i < n; i++) {
		x = read(); y = read();
		ini(x, y); ini(y, x);
		G[x].insert(y); G[y].insert(x);
	}
	
	for(register int i = 1; i <= m; i++) {
		x = read(); tx = read(); y = read(); ty = read();
		printf("%lld\n", solve());
	}
	
	return 0;
}
