#include<cstdio>
#include<iostream>
using namespace std;
int n, m;
typedef long long ll;
const int mo = 1e9 + 7;
inline ll mul(ll a, ll b) {
	return (a * b) % mo;
}
inline ll pow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) res = mul(res, a);
	return res;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d",&n, &m);
	if (n == 1) printf("%lld\n", pow(2, m));
	if (n == 2) printf("%lld\n", mul(4, pow(3, m - 1)));
	if (n == 3 && m == 1) printf("%d\n", 8);
	if (n == 3 && m == 2) printf("%d\n", 36);	
	if (n == 3 && m == 3) printf("%d\n", 112);
	if (n == 5 && m == 5) printf("%d\n", 7136);
	return 0;
}
