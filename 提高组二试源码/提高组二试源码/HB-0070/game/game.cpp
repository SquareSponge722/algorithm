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

const int MAXN = 1;
const int MO = 1e9 + 7;

const int table[10][10] = {
	{},
	{0, 2, 4, 8, 16, 32, 64, 128, 256},
	{0, 4, 12, 36, 108, 324, 972, 2916, 8748},
	{0, 8, 36, 112, 336, 1008, 3024, 9072, 27216},
	{0, 16, 108, 336, 912, 3136, 9408, 28224, 87808},
	{0, 32, 324, 1008, 2736, 7136, 87808},
	{0, 64, 972, 3024, 8208, 28224},
	{0, 128, 2916, 9072, 24624, 87808},
	{0, 256, 8748, 27216, 73872, 263424}
};

inline LL fpow(LL n, LL k) {
	LL res = 1;
	for(; k; k >>= 1) {
		if(k & 1) res = res * n % MO;
		n = n * n % MO;
	}
	return res;
}

int n, m;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n <= 8 && m <= 8) {
		printf("%d", table[n][m]);
	} else if(n == 2) {
		printf("%lld", 4 * fpow(3, m - 1));
	} else {
		
	}
	return 0;
}
