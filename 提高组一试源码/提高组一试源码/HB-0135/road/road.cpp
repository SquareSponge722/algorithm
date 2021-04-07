#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;
const int D = 10000 + 5;

long long bit[D];

int lowbit(int x) {
	return x & -x;
}

void add(int p, int v) {
	for (; p < D; p += lowbit(p)) {
		bit[p] += v;
	}
}

long long sum(int p) {
	long long ret = 0;
	for(; p; p -= lowbit(p)) {
		ret += bit[p];
	}
	return ret;
}

int n;
int d[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] > d[i-1]) {
			add(d[i-1] + 1, 1);
			add(d[i] + 1, -1);
		}
	}
	long long ans = 0;
	for (int i = 1; i < D; i++) {
		ans += sum(i);
	}
	printf("%lld\n", ans);
	return 0;
}
