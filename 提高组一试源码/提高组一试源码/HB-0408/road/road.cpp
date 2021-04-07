#include <cstdio>
#include <iostream>
#define N 100010
using namespace std;

int n, d[N], ans;

inline void read(int &x) {
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(d[i]);
		if (d[i] < d[i - 1])
			ans += d[i - 1] - d[i];
	}
	printf("%d\n", ans + d[n]);
	return 0;
}
