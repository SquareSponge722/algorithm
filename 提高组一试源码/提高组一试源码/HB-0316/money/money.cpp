#include <bits/stdc++.h>
using namespace std;
#define IL inline
IL int read() {
	char ch = getchar(); int u = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
	return u * f;
}
const int INF = 1e9;
int T, Mn, ans, a[105];
int f[int(1e6 + 10)], g[int(1e6 + 10)];
int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	T = read();
	while (T--) {
		f[0] = 1; 
		ans = INF;
		Mn = int(1e6);
		int n = read(); 
		f[0] = 1;
		for (int i = 1; i <= n; ++i) a[i] = read();
		if (n == 1) {
			printf("1\n");
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int t1 = a[i]; int t2 = a[j];
				int G = gcd(t1, t2);
				if (G == 1) Mn = min(Mn, t1 * t2 - t1 - t2);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = a[i]; j <= Mn; ++j) {
				if (f[j - a[i]]) f[j] = 1;
			}
		}
		for (int i = 1; i < (1 << n); ++i) {
			for (int j = 0; j <= Mn; ++j) g[j] = 0;
			int tot = 0; g[0] = 1;
			for (int j = 1; j <= n; ++j) {
				if (i & (1 << (j - 1))) {
					int t = a[j]; tot++;
					for (int k = t; k <= Mn; ++k) if (g[k - t]) g[k] = 1;
				}
			}
			bool suc = true;
			for (int j = 1; j <= Mn; ++j) if (f[j] != g[j]) suc = false;
			if (suc) {
				ans = min(ans, tot);
			}
		}	
		for (int i = 0; i <= Mn; ++i) f[i] = 0;
		printf("%d\n", ans);
	}
	return 0;
}
/*
2
4
3 19 10 6
*/
