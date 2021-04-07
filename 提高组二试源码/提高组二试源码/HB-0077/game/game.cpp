#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, m, ans = 1;
	cin >> n >> m;
	
	if(n == 2)
		for(int i = 1; i <= m + 1; i++)	
			if(i == m + 1 || i == 1)
				ans *= 2, ans %= mod;
			else
				ans *= 3, ans %= mod;
	cout << ans << endl;
	return 0;
}
