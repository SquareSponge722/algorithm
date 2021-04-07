#include <bits/stdc++.h>

#define maxn 100100

#define ll long long

using namespace std;

ll n, ans, a[maxn];

inline ll read() {
	ll f = 1, k = 0; char c = getchar();
	while(c > '9' || c < '0') {if(f == '-') f = -1; c = getchar();}
	while(c <= '9' && c >= '0') {k = k * 10 + c - '0'; c = getchar();}
	return k * f;
}

struct node {
	ll value, where;
}b[maxn];

ll cmp(node x, node y) {
	return x.value < y.value;
}

void search(ll l, ll r) {
	//cout << "27#: " << l << " " << r << endl;
	if(l == r) {
		ans += a[l];
		return ;
	}
	if(l > r) return ;
	for(int i = l; i <= r; i ++) {
		b[i].value = a[i]; //cout << "34#: " << "b[i].value: " << b[i].value << endl;
		b[i].where = i; //cout << "35#: " << "b[i].where: " << b[i].where << endl;
	} //for(int i = l; i <= r; i ++) {cout << "36#: " << b[i].value << " " << b[i].where << endl;}
	sort(b + l, b + r + 1, cmp); //for(int i = l; i <= r; i ++) {//cout << "37#: " << b[i].value << " " << b[i].where << endl;}
	ll k = b[l].value; ll z = b[l].where; //cout << "38#: " << "value: " << k << " " << "where: " << z << endl;
	//cout << "38#: " << k << " " << z << endl;
	ans += k;
	for(int i = l; i <= r; i ++) {
		a[i] -= k;
	}
	//cout << "#44#: ";
	//for(int i = l; i <= r; i ++) {
	//	cout << a[i] << " " ;
	//}
	//cout << endl;
	search(l, z - 1);
	search(z + 1, r);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	search(1, n);
	printf("%lld", ans);
	return 0;
}
