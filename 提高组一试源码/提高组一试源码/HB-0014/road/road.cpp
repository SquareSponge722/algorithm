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
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define len(x) (t[x].r - t[x].l + 1)
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
inline int read() {
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

int n;
struct node {
	int l, r;
	long long tag, min, max;
//	node(long long tag = 0) {}
} t[maxn << 2];

inline void update(int k) {
	t[k].min = min(t[ls(k)].min, t[rs(k)].min);
	t[k].max = max(t[ls(k)].max, t[rs(k)].max);
}

inline void pushdown(int k) {
	t[ls(k)].tag += t[k].tag;
	t[rs(k)].tag += t[k].tag;
	t[ls(k)].min += t[k].tag;
	t[rs(k)].min += t[k].tag;
	t[ls(k)].max += t[k].tag;
	t[rs(k)].max += t[k].tag;
	t[k].tag = 0;
}

inline void build(int k, int l, int r) {
	t[k].l = l, t[k].r = r;
	if (l == r) {
		t[k].max = t[k].min = read();
		t[k].tag = 0;
		return;
	}
	int M = l + r >> 1;
	build(ls(k), l, M);
	build(rs(k), M + 1, r);
	update(k);
}

inline void addv(int k, int l, int r, long long val) {
	if (l <= t[k].l && t[k].r <= r) {
		t[k].tag += val;
		t[k].min += val;
		t[k].max += val;
		return;
	}
	pushdown(k);
	int M = t[k].l + t[k].r >> 1;
	if (l <= M) addv(ls(k), l, r, val);
	if (M < r) addv(rs(k), l, r, val);
	update(k);
}

inline long long query(int k, int l, int r) {
	if (l <= t[k].l && t[k].r <= r) {
		return t[k].min;
	}
	pushdown(k);
	int M = t[k].l + t[k].r >> 1;
	long long res = inf;
	if (l <= M) res = min(res, query(ls(k), l, r));
	if (M < r) res = min(res, query(rs(k), l, r));
	return res;
}

inline long long query2(int k, int l, int r) {
	if (l <= t[k].l && t[k].r <= r) {
		return t[k].max;
	}
	pushdown(k);
	int M = t[k].l + t[k].r >> 1;
	long long res = 0;
	if (l <= M) res = max(res, query2(ls(k), l, r));
	if (M < r) res = max(res, query2(rs(k), l, r));
	return res;
}

struct nod {
	int l, r;
	nod(int l, int r) : l(l), r(r) {}
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	build(1, 1, n);
	long long cnt = 0;
	queue<nod> q;
	q.push(nod(1, n));
	while (!q.empty()) {
		register int x = q.front().l, y = q.front().r, p;
		q.pop();
		register long long Min = query(1, x, y);
		cnt += Min;
		addv(1, x, y, -Min);
		for (register int i = x; i <= y; i++) if (!query(1, i, i)) {
			p = i;
			break;
		}
		if (p > x) q.push(nod(x, p - 1));
		if (p < y) q.push(nod(p + 1, y));
	}
	printf("%lld", cnt);
	return 0;
}
