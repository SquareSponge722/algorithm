#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[110], b[110];

bool can_biaoshi(int x, int dep) {
	if (dep == 1) return !(x % b[1]);
	while (x >= 0) {
		if (can_biaoshi(x, dep - 1)) return true;
		x -= b[dep];
	}
	return false;
}

void kaiketu() {
	int n; scanf("%d", &n);
	if (n == 2) {
		int a, b; scanf("%d%d", &a, &b);
		printf(!(a % b) || !(b % a) ? "1\n" : "2\n");
		return;
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	int ans = 1;
	b[ans] = a[0];
	for (int i = 0; i < n; ++i)
		if (!can_biaoshi(a[i], ans))
			b[++ans] = a[i];
	printf("%d\n", ans);
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) kaiketu();
	return 0;
}
