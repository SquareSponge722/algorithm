#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>

#define N 100001

using namespace std;
typedef long long ll;

int n, d[N];

void init() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}

inline ll Search(int l, int r) {
	ll rtans = 0;
	if(r == l) {
		rtans = d[l];
		return rtans;
	}
	if(r < l)
		return 0;
	priority_queue <int, vector<int>, greater<int> > q;
	while(!q.empty())
		q.pop();
	for(int i = l; i <= r; i ++)
		q.push(d[i]);
	int dele = q.top();
	rtans += dele;
	int templ = l;
	for(int i = l; i <= r; i ++) {
		d[i] -= dele;
		if(d[i] == 0) {
			rtans += Search(templ, i - 1);
			templ = i + 1;
		}
	}
	return rtans + Search(templ, r);
}

int main() {
	init();
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &d[i]);
	printf("%lld\n", Search(1, n));
	return 0;
}
