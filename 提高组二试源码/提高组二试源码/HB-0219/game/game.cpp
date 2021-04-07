#include <cstdio>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int ans[4][4];
int pow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a = (a * 1ll * a) % MOD)
		if (b & 1)
			ans = (ans * 1ll * a) % MOD;
	return ans;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ans[1][1] = 2; ans[1][2] = 4;  ans[1][3] = 8;
	ans[2][1] = 4; ans[2][2] = 12; ans[2][3] = 36;
	ans[3][1] = 8; ans[3][2] = 36; ans[3][3] = 112;
	int n, m; scanf("%d %d", &n, &m);
	if (n <= 3 && m <= 3) printf("%d\n", ans[n][m]); else
	if (n == 2 || m == 2) {
		if (m == 2) swap(n, m);
		printf("%lld\n", (4 * 1ll * pow(3, m - 1)) % MOD);
	} else
	if (n == 3 || m == 3) {
		if (m == 3) swap(n, m);
		printf("%lld\n", (112 * 1ll * pow(3, m - 3)) % MOD);
	} else
	if (n == 4 || m == 4) {
		if (m == 4) swap(n, m);
		int t_ans[] = {0, 16, 108, 336, 912};
		if (m <= 4) printf("%d\n", t_ans[m]);
		else printf("%lld\n", (2688 * 1ll * pow(3, m - 5)) % MOD);
	} else
	if (n == 5 && m == 5) {
		printf("%d\n", 7136);
		return 0;
	} else
	if (n == 5 || m == 5) {
		if (m == 5) swap(n, m);
		printf("%lld\n", (53760 * 1ll * pow(3, m - 7)) % MOD);
	}
	return 0;
}
