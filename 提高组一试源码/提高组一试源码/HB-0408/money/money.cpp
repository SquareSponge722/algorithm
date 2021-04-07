#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 110
#define M 25010
using namespace std;

int t, n, a[N], tot;
bool f[M];

inline void read(int &x) {
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	read(t);
	while (t--) {
		read(n);
		for (int i = 1; i <= n; ++i)
			read(a[i]);
		sort(a + 1, a + n + 1);
		if (a[1] == 1) {
			printf("1\n");
			continue;
		}
		tot = 0;
		memset(f, 0, sizeof f);
		f[0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (f[a[i]]) {
				++tot;
				continue;
			}
			for (int j = 0; j < a[n]; ++j)
				if (f[j])
					f[j + a[i]] = 1;
		}
		printf("%d\n", n - tot);
	}
	return 0;
}
