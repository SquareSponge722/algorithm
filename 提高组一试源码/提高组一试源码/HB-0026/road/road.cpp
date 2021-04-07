#include <bits/stdc++.h>
using namespace std;

inline long long read(long long u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}

const int maxn = 100000 + 10;

long long a[maxn];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n = read();
	long long ans = 0, now = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		ans += max(0ll, a[i] - now);
		now = a[i];
	}
	cout << ans << endl;
}
