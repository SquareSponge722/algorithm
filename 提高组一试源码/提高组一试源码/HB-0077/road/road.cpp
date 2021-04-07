#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, lst = 0, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		long long d;
		cin >> d;
		if(d > lst)
			ans += d - lst;
		lst = d;
	}
	
	cout << ans << endl;
	return 0;
}
