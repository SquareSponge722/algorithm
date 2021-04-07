#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#define maxn 105
using namespace std;
int t, n, a[maxn];
set<int> s;
int gcd (int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		s.clear();
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) if (a[i] != a[j]) {
				s.insert(gcd(a[i], a[j]));
			}
		}
		if (!(s.size() - 1)) cout << n << endl;
		else cout << s.size() - 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
