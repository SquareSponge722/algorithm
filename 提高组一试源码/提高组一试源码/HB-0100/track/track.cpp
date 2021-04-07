#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[50010], n, m;

bool nice(int x) {
	int c = 0, curr = 0, ac = 0;
	while (curr < n - 1)
		if ((ac += a[curr++]) >= x)
			ac = 0, ++c;
	return c >= m;
}

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	//pretend it's a chain
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; ++i) {
		int x, y; scanf("%d%d%d", &x, &y, a + i);
	}
	int l = 0, r = 1073741824, mid = 536870912;
	while (l <= r)
		nice(mid = (l + r >> 1)) ? (l = mid + 1) : (r = mid - 1);
	printf("%d\n", r);
	return 0;
}
