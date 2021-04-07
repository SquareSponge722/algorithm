#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int d[maxn], ans, n;

inline int read() {
	int x = 0;
	scanf("%d", &x);
	return x;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	//cin >> a >> b;
	n = read();
	
	for(register int i = 1; i <= n; i++) d[i] = read();
	
	for(register int i = 1; i <= n; i++) 
		if(d[i] > d[i - 1])
			ans += (d[i] - d[i - 1]);
	
	cout << ans;
	return 0;
}
