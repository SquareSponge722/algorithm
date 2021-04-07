#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
ll n,m;
const ll mod=(1e9)+7;

ll quickpow(ll x,ll y) {
	if(y==0) return 1;
	else if(y==1) return x;
	else {
		ll num=quickpow(x,y>>1)%mod;
		if(y%2==0) return (num*num)%mod;
		else return (((num*num)%mod)*x)%mod;
	}
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> m;
	cout << (quickpow((n*m)%mod,max(n,m))%mod)/(n*m) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
