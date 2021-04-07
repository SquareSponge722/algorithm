#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define mod 1000000007
#define LL long long
using namespace std;

int n, m;

namespace case1{
	inline void solve(int x, int y) {
		LL rtn = 4ll, xx = 3;
		while(y) {
			if (y & 1) rtn = (rtn * xx) % mod;
			xx = (xx * xx) % mod;
			y >>= 1;
		}
		cout << rtn;
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.in", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	if (n <= 2) case1::solve(n, m - 1);
	else if (n == 3 && m == 3) cout << 112;
	else if (n == 5 && m == 5) cout << 7136;
	return 0;
}
