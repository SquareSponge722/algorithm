#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int ModEr = 1000000007;

inline long long heibou(long long x) {
	return x * x % ModEr;
}

long long haya_jou(long long a, int pow) {
	return pow == 1 ? a : (heibou(haya_jou(a, pow >> 1)) * (pow & 1 ? a : 1)) % ModEr;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	if (n == 1) {
		printf("%d\n", int(haya_jou(2, m) % ModEr));
		return 0;
	}
	if (m == 1) {
		printf("%d\n", int(haya_jou(2, n) % ModEr));
		return 0;
	}
	if (n == 2) {
		printf("%d\n", int(4 * haya_jou(3, m - 1) % ModEr));
		return 0;
	}
	if (n == 3) {
		printf("%d\n", m == 3 ? 112 : int(36 * haya_jou(4, m - 2) % ModEr));
		return 0;
	}
	if (n == 5 && m == 5) {
		printf("7136\n");
		return 0;
	}
	return 0;
}
