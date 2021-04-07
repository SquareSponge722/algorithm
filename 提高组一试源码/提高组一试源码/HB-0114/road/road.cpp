#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 100005
#define ll long long
#define inf 2147483647
using namespace std;
int n, last, a[maxn];
ll ans;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n); a[0] = inf;
	for (int i = 1; i <= n; i ++) 
		scanf("%d", &a[i]);
	last = a[1];
	for (int i = 2; i <= n; i ++) {
		if (last <= a[i]) ans += (a[i] - last), a[i] -= last;
		else ans += 1, last = a[i];
	} 
	if (!ans) { printf("1\n"); return 0; }
	else printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
