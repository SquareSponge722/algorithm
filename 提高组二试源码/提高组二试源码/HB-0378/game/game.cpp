#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll n, m;

ll ksm(ll x, ll y){
	ll res = 1;
	while (y){
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void work(){
	if (n == 1) cout << ksm(2, m) % MOD << endl;
	else if (m == 1) cout << ksm(2, n) % MOD << endl;
	else cout << (12 * ksm(2, m - 1) - 12) % MOD << endl;
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m;
	work();
	return 0;
}
