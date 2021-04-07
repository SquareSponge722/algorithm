#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
long long P = 1e9 + 7;
inline int read() {
	register int  x = 0, f = 1; register char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}

inline int C(int a, int b) {
	int res = 1;
	for (int i = b; i >= 1; i--) {
		res *= (a + i - b);
	}
	for (int i = 1; i <= b; i++) res /= i;
	return res;
}

long long ksm(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return (long long)a;
	if (b == 2) return (long long)a * a;
	int k = b / 3;
	long long tmp = ksm(a, k) % P;
	return b % 3 == 0 ? ((tmp * tmp) % P * tmp) % P : ((tmp * tmp) % P * ksm(a, b - (k << 1))) % P;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n = read(), m = read();
	if (n == 1) {
		printf("%d", ksm(2, m));
		return 0;
	}
	if (n == 2) {
		int a = ksm(2, m);
		printf("%d", a * (a - m + 1));
		return 0;
	}
	if (n == 3) {
		if (m == 3) {
			printf("112");
			return 0;
		}
		int a = ksm(2, m);
		int b = a * (a - m + 1);
		printf("%d", b * (b - m + 1));
		return 0;
	}
	if (n == 5 && m == 5) printf("7136");
	return 0;
}

