#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100006;
int n, d[N];
bool v[N];
ll ans = 0;
priority_queue<pair<int, int> > pq;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	while (pq.size()) pq.pop();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		pq.push(make_pair(-d[i], i));
	}
	int num = 1, k = 0;
	memset(v, 0, sizeof(v));
	v[0] = v[n+1] = 1;
	while (pq.size()) {
		int x = pq.top().second;
		pq.pop();
		ans += (ll)(d[x] - k) * num;
		k = d[x];
		v[x] = 1;
		if (v[x+1] && v[x-1]) num--;
		else if (!v[x+1] && !v[x-1]) num++;
	}
	printf("%lld\n", ans);
	return 0;
}
