#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn = 1000100;
const int inf  = 2147483647;

int n, ans = 0, sum = 0;
int a[maxn];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while (true){
		int mini = inf, pos;
		for (int i = 1; i <= n; i++) if (mini > a[i] && a[i]) mini = a[i], pos = i;
		int l = pos - 1, r = pos + 1;
		while (l >= 1 && a[l]) a[l--] -= a[pos];
		while (r <= n && a[r]) a[r++] -= a[pos];
		ans += a[pos];
		a[pos] = 0;
		bool check = false;
		for (int i = 1; i <= n; i++) if (a[i]) check = true;
		if (!check) break;
	}
	cout << ans;
	return 0;
}
