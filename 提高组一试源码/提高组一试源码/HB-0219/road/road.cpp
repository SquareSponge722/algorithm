#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
inline void read(int &x) {
	static char buf = getchar(); register int f = 1; x = 0;
	for (; !isdigit(buf); buf = getchar()) if (buf == '-') f = -1;
	for (;  isdigit(buf); buf = getchar()) x = x * 10 + buf - 48; x *= f;
}
int data[N], n;
int search(int l, int r, int tot) {
	if (l == r) {
		int res = data[l] - tot;
		data[l] = 0;
		return res;
	}
	if (l > r) return 0;
	int res = 0;
	int mn = *min_element(data + l, data + r + 1); res += mn - tot;
	int last = l;
	for (int i = l; i <= r; ++i)
		if (data[i] == mn) {
			res += search(last, i - 1, mn);
			last = i + 1;
		} res += search(last, r, mn);
	return res;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i) read(data[i]);
	printf("%d\n", search(1, n, 0));
	return 0;
}
