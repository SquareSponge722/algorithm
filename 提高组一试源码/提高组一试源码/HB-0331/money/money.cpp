#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105], tag[105];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void exgcd(int &x, int &y, int a, int b) {
	if (b == 0) {
		x = 1; y = 0; return;
	}
	exgcd(y, x, b, a % b);
	y -= (a / b) * x;
}
bool check(int a, int b, int c) {
	int x, y, g = gcd(a, b);
	if (c % g != 0) return false;
	c /= g; a /= g; b /= g;
	exgcd(x, y, a, b);
	x *= c; y *= c;
	if (y < 0) swap(a, b), swap(x, y);
	if (x < 0) {
		int t = y / a;
		x += t * b;
		y -= t * a;
	}
	return x >= 0 && y >= 0;
}
void solve() {
	memset(tag, 0, sizeof(tag));
	memset(a, 0, sizeof(a));
	int n, m = 0; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			if (a[j] % a[i] == 0) {
				tag[j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!tag[i]) a[++m] = a[i];
	n = m;
	if (n <= 2) {
		printf("%d\n", n);
		return;
	}
	sort(a + 1, a + 1 + n);
	m = n;	memset(tag, 0, sizeof(tag));
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j)  {
			for (int k = j + 1; k <= n; ++k) {
				if (check(a[i], a[j], a[k])) tag[k] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) m -= tag[i];
	printf("%d\n", m);
}
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}
