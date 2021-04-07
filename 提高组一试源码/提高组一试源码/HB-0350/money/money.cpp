#include <bits/stdc++.h>
using namespace std;
const int N = 106, A = 25006;
int t, n, a[N], maxa = 0;
bool v[A], vv[A];

void mny() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxa = max(maxa, a[i]);
	}
	sort(a + 1, a + n + 1);
	memset(v, 0, sizeof(v));
	int m = 0;
	for (int i = 1; i <= n; i++)
		if (!v[a[i]]) {
			m++;
			v[a[i]] = 1;
			memset(vv, 0, sizeof(vv));
			for (int j = 1; j <= maxa; j++)
				if (v[j])
					for (int k = 1; k * a[i] + j <= maxa; k++)
						vv[k*a[i]+j] = 1;
			for (int i = 1; i <= maxa; i++) v[i] = (v[i] | vv[i]);
		}
	printf("%d\n", m);
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &t);
	while (t--) mny();
	return 0;
}
