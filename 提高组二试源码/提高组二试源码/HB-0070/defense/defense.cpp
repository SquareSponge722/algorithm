// Code by KSkun, 2018/11
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <functional>

typedef long long LL;
typedef std::pair<int, int> PII;

inline char fgc() {
	static char buf[100000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline LL readint() {
	register LL res = 0, neg = 1; register char c = '*';
	for(; !isdigit(c); c = fgc()) if(c == '-') neg = -1;
	for(; isdigit(c); c = fgc()) res = res * 10 + c - '0';
	return res * neg;
}

inline char readchar() {
	register char c;
	while(!isgraph(c = fgc())) {}
	return c;
}

const int MAXN = 100005;
const LL INF = 1e15;

struct Edge {
	int to, nxt;
} gra[MAXN << 1];
int head[MAXN], tot = 0;

inline void addedge(int u, int v) {
	gra[tot].to = v; gra[tot].nxt = head[u]; head[u] = tot++;
	gra[tot].to = u; gra[tot].nxt = head[v]; head[v] = tot++;
}

int n, m, w[MAXN];
LL dp[MAXN][2];
int quer[MAXN];

void dfs(int u, int fa) {
	bool hass = false;
	for(int i = head[u]; ~i; i = gra[i].nxt) {
		int v = gra[i].to;
		if(v == fa) continue;
		hass = true;
		dfs(v, u);
		if(quer[u] != -1) {
			if(quer[u] == 0) {
				dp[u][0] += dp[v][1];
				dp[u][1] = INF;
			} else {
				dp[u][0] = INF;
				dp[u][1] += std::min(dp[v][0], dp[v][1]);
			}
		} else {
			dp[u][0] += dp[v][1];
			dp[u][1] += std::min(dp[v][0], dp[v][1]);
		}
	}
	dp[u][1] += w[u];
	if(!hass) {
		if(quer[u] != -1) {
			if(quer[u] == 0) {
				dp[u][0] = 0;
				dp[u][1] = INF;
			} else {
				dp[u][0] = INF;
				dp[u][1] = w[u];
			}
		} else {
			dp[u][0] = 0;
			dp[u][1] = w[u];
		}
	}
	//printf("u %d dp0 %lld dp1 %lld\n", u, dp[u][0], dp[u][1]);
}

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	memset(head, -1, sizeof(head));
	memset(quer, -1, sizeof(quer));
	n = readint(); m = readint();
	readchar(); readchar();
	for(int i = 1; i <= n; i++) {
		w[i] = readint();
	}
	for(int i = 1, u, v; i < n; i++) {
		u = readint(); v = readint();
		addedge(u, v);
	}
	while(m--) {
		for(int i = 1; i <= n; i++) {
			dp[i][0] = dp[i][1] = 0;
		}
		int a = readint(), x = readint(), b = readint(), y = readint();
		quer[a] = x;
		quer[b] = y;
		dfs(1, 0);
		LL res = std::min(dp[1][0], dp[1][1]);
		printf("%lld\n", res >= INF ? -1 : res);
		quer[a] = -1;
		quer[b] = -1;
	}
	return 0;
}
