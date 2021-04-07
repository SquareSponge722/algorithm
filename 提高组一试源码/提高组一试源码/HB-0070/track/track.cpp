// Code by KSkun, 2018/11
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
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

const int MAXN = 50005;

int n, m;

struct Edge {
	int to, w, nxt;
} gra[MAXN << 1];
int head[MAXN], tot;

inline void addedge(int u, int v, int w) {
	gra[tot].to = v; gra[tot].w = w; gra[tot].nxt = head[u]; head[u] = tot++;
	gra[tot].to = u; gra[tot].w = w; gra[tot].nxt = head[v]; head[v] = tot++;
}

namespace SP1 { // m=1
	LL dis[MAXN];
	bool vis[MAXN];
	LL lu;
	inline void bfs(int st) {
		memset(vis, 0, sizeof(vis));
		std::queue<int> que;
		dis[st] = 0; que.push(st);
		while(!que.empty()) {
			int u = que.front(); que.pop();
			vis[u] = true;
			for(int i = head[u]; ~i; i = gra[i].nxt) {
				int v = gra[i].to, w = gra[i].w;
				if(vis[v]) continue;
				dis[v] = dis[u] + w;
				que.push(v);
			}
		}
	}
	inline void main() {
		bfs(1);
		for(int i = 1; i <= n; i++) {
			if(dis[i] > dis[lu]) lu = i;
		}
		bfs(lu);
		LL mx = 0;
		for(int i = 1; i <= n; i++) {
			mx = std::max(mx, dis[i]);
		}
		printf("%lld", mx);
	}
}

namespace SP3 { // ¾Õ»¨Í¼ 
	std::vector<int> len, tmp;
	inline bool check(int mid) {
		int cnt = 0;
		tmp = len;
		for(int i = 0; i < tmp.size(); i++) {
			if(tmp[i] >= mid) {
				cnt++; continue;
			}
			int nxt = std::lower_bound(tmp.begin() + i + 1, tmp.end(), mid - tmp[i]) - tmp.begin();
			if(nxt >= tmp.size()) continue;
			cnt++;
			tmp.erase(tmp.begin() + nxt);
		}
		return cnt >= m;
	}
	inline void main() {
		int mx = 0;
		for(int i = head[1]; ~i; i = gra[i].nxt) {
			len.push_back(gra[i].w);
			mx = std::max(mx, gra[i].w);
		}
		std::sort(len.begin(), len.end());
		LL l = 0, r = mx * 2 + 5, mid;
		while(r - l > 1) {
			mid = (l + r) >> 1;
			if(check(mid)) l = mid; else r = mid;
		}
		printf("%lld", l);
	}
}

namespace SP2 { // Á´
	std::vector<int> len;
	inline bool check(int mid) {
		int cnt = 0, lst = 0;
		for(int i = 0; i < len.size(); i++) {
			if(len[i] - len[lst] >= mid) {
				cnt++; lst = i;
			}
		}
		return cnt >= m;
	}
	LL sum = 0;
	void dfs(int u, int fa) {
		for(int i = head[u]; ~i; i = gra[i].nxt) {
			int v = gra[i].to, w = gra[i].nxt;
			if(v == fa) continue;
			len.push_back(w);
			sum += w;
			dfs(v, u);
		}
	}
	inline void main() {
		dfs(1, 0);
		for(int i = 1; i < len.size(); i++) {
			len[i] += len[i - 1];
		}
		LL l = 0, r = sum + 5, mid;
		while(r - l > 1) {
			mid = (l + r) >> 1;
			if(check(mid)) l = mid; else r = mid;
		}
		printf("%lld", l);
	}
}

bool issp2 = true, issp3 = true;;

int main() {
	memset(head, -1, sizeof(head));
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = readint(); m = readint();
	for(int i = 1, u, v, w; i < n; i++) {
		u = readint(); v = readint(); w = readint();
		if(v != u + 1) issp2 = false;
		if(u != 1) issp3 = false;
		addedge(u, v, w);
	}
	if(m == 1) {
		//puts("SP1!");
		SP1::main();
	} else if(issp2) {
		//puts("SP2!");
		SP2::main();
	} else if(issp3) {
		//puts("SP3!");
		SP3::main();
	} else {
		
	}
	return 0;
}
