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

const int MAXN = 100005;

int n, d[MAXN];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		ans += std::max(d[i] - d[i - 1], 0);
	}
	printf("%d", ans);
	return 0;
}
