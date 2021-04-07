#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;
const int A = 25000 + 5;

int a[N];
bool f[A];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);	
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		memset(f, false, sizeof f);
		f[0] = true;
		int ans = n;
		for (int i = 1; i <= n; i++) {
			if (f[a[i]]) {
				ans--;
				continue;
			}
			for (int k = a[i]; k < A; k++) {
				f[k] |= f[k-a[i]];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
