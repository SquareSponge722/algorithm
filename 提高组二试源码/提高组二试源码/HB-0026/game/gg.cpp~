#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}


const int P = 1e9 + 7;

int add(int a, int b) {
	a += b;
	return a >= P ? a - P;
}
int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + P;
}
int mul(int a, int b) {
	return int(1ll * a * b % P);
}
int fpw(int a, int b, int c = 1) {
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) c = mul(a, c);
	return c;
}
int inv(int a) { return fpw(a, P - 2); }
int f[128], g[128];



int main() {
	int n = read(), m = read(), M = 1 << n - 1;
	if (n == 1 || m == 1) {
		cout << fpw(2, n + m - 1) << endl;
		return 0;
	}
	f[0] = 2;
	f[1] = 4;
	for (int i = 2; i < n; i++) {
		memset(g, 0, sizeof g);
		for (int s = 0; s < 1 << i; s++) {
			for (int t = 0; t < 1 << (i + 1); t++) {
				
			}
		}
	}
}
