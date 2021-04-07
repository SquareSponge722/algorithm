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

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

const int MAXN = 105;

int T, n, a[MAXN];

namespace SP1 {
	inline void main() {
		if(a[2] % a[1] == 0 || a[1] % a[2] == 0) {
			puts("1");
		} else {
			puts("2");
		}
	}
}

namespace SP2 {
	inline bool check(int x, int a, int b) {
		for(int i = 0; i <= x / a; i++) {
			if((x - i * a) % b == 0) return true;
		}
		return false;
	}
	inline void main() {
		int g = gcd(gcd(a[1], a[2]), a[3]);
		if(g == a[1] || g == a[2] || g == a[3]) {
			puts("1");
		} else if(check(a[1], a[2], a[3]) || check(a[2], a[1], a[3]) || check(a[3], a[1], a[2])) {
			puts("2");
		} else {
			puts("3");
		}
	}
}

namespace SP3 {
	bool del[MAXN];
	bool dfs(int step, int sum, int goal) {
		if(step == n) return del[n] ? sum == goal : ((goal - sum) % a[n] == 0);
		for(int i = 0; i <= (del[step] ? 0 : ((goal - sum) / a[step])); i++) {
			if(dfs(step + 1, sum + i * a[step], goal)) return true;
		}
		return false;
	}
	inline void main() {
		memset(del, 0, sizeof(del));
		for(int i = 1; i <= n; i++) {
			del[i] = true;
			if(!dfs(1, 0, a[i])) del[i] = false;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!del[i]) cnt++;
			//else printf("%d ", a[i]);
		}
		//puts("");
		printf("%d\n", cnt);
	}
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if(n == 1) {
			puts("1");
		} else if(n == 2) {
			//puts("SP1!");
			SP1::main();
		} else if(n == 3) {
			//puts("SP2!");
			SP2::main();
		} else {
			//puts("SP3!");
			SP3::main();
		}
	}
	return 0;
}
