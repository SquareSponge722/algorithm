#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 110;
int a[maxn];

namespace case1 {
	inline void solve(int n) {
		int x, y; scanf("%d%d", &x, &y);
		if (x % y == 0 || y % x == 0) puts("1");
		else puts("2");
	}
}

namespace case2 {
	inline void solve(int n) {
		int a[10];
		scanf("%d%d%d", &a[1], &a[2], &a[3]);
		sort(a + 1, a + 1 + 3);
		int ans = 3;
		int bei = a[3] / a[1] + 1;
		for (int i = 0 ; i <= bei ; i++) {
			if (i * a[1] <= a[3]) {
				int cdc = a[3] - a[1] * i;
				if (cdc % a[2] == 0) {
					ans -= 1; break;
				}
			}
		}
		if (a[2] % a[1] == 0) ans -= 1;
		printf("%d\n", ans);
	}
}

inline bool check1(int a, int b, int c) {
	int bei = c / a + 1;
	for (int i = 0; i <= bei; i++) {
		if (a * i <= c) {
			int cdc = c - a * i;
			if (cdc % b == 0) return true;
		}
		else break;
	}
	return false;
}

inline bool check2(int a, int b, int c, int d) {
	int b1 = d / a + 1, b2 = d / b + 1;
	for (int i = 0; i <= b1; i++) {
		for (int j = 0; j <= b2; j++) {
			if (a * i + b * j <= d) {
				int cdc = d - a * i - b * j;
				if (cdc % c == 0) return true;
			} 
			else break;
		}
	}
	return false;
}

inline bool check3(int a, int b, int c, int d, int e) {
	int b1 = e / a + 1, b2 = e / b + 1, b3 = e/ c + 1;
	for (int i = 0; i <= b1; i++) {
		for (int j = 0; j <= b2; j++) {
			for (int k = 0; k <= b3; k++) {
				if (i * a + j * b + k * c <= e) {
					int cdc = e - i * a - j * b - k * c;
					if (cdc % d == 0) return true;
				}
				else break;
			}
		}
	}
	return false;
}

namespace case3 {
	inline void solve(int n) {
		int a[10], ans = 4;
		scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
		sort(a + 1, a + 1 + 4);
		if (check1(a[1], a[2], a[4])) ans -= 1;
		else if (check1(a[1], a[3], a[4])) ans -= 1;
		else if (check1(a[2], a[3], a[4])) ans -= 1;
		else if (check2(a[1], a[2], a[3], a[4])) ans -= 1;
		
		
		if (check1(a[1], a[2], a[3])) ans -= 1;
		if (a[2] % a[1] == 0) ans -= 1;
		printf("%d\n", ans);
	}
}

namespace case4 {
	inline void solve(int n) {
		int a[10], ans = 5; bool vis[10];
		memset(vis, false, sizeof(vis));
		scanf("%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5]);
		sort(a + 1, a + 1 + 5);
		for (int i = n; i >= 3; i--) {
			for (int j = 1; j < i; j++) {
				bool flag = false;
				for (int k = j + 1; k < i; k++) {
					flag = check1(a[j], a[k], a[i]);
					if (flag) break;
				}
				if (flag) {vis[i] = true; break;}
			}
		}
		for (int i = n; i >= 3; i--) {
			if (vis[i]) continue;
			for (int j = 1; j < i; j++) {
				bool flag = false;
				for (int k = j + 1; k < i; k++) {
					for (int l = k + 1; l < i; l++) {
						flag = check2(a[j], a[k], a[l], a[i]);
						if (flag) break;
					}
					if (flag) {vis[i] = true; break;}
				}
				if (flag) break;
			}
		}
		if (check3(a[1], a[2], a[3], a[4], a[5])) vis[5] = true;
		for (int i = 1; i <= 5; i++) if (vis[i]) ans -= 1;
		printf("%d\n", ans);
	}
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T; scanf("%d",&T);
	while(T--) {
		int n; scanf("%d", &n);
		if (n == 1) puts("1");
		else if (n == 2) case1::solve(n);
		else if (n == 3) case2::solve(n);
		else if (n == 4) case3::solve(n);
		else if (n == 5) case4::solve(n);
		else {
			int a[110];
			for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
			puts("shout out to 88 rising, motherfvcker.");
		}
	}
	return 0;
}
