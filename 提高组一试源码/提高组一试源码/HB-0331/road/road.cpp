#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l, m, ls
#define rson m + 1, r, rs
using namespace std;
const int N = 100005;
int n, d[N], f[N*4], m, ans, s[N];
vector < int > a[10005];
inline int lowbit(int x) {
	return x & (-x);
}
inline void add(int p, int x) {
	for (; p <= n; p += lowbit(p))
		s[p] += x;
}
inline int qsum(int p) {
	int res = 0;
	for (; p; p -= lowbit(p))
		res += s[p];
	return res;
}
int findL(vector < int > &a, int L) {
	int l = 0, r = a.size() - 1;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (a[m] < L) l = m;
		else r = m;
	}
	for (int i = l; i <= r; ++i)
		if (a[i] >= L) return i;
	return -1;
}
int findR(vector < int > &a, int R) {
	int l = 0, r = a.size() - 1;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (a[m] > R) r = m;
		else l = m;	
	}
	for (int i = r; i >= l; --i)
		if (a[i] <= R) return i;
	return -1;
}
int findmn(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return f[rt];
	int m = (l + r) >> 1, res = 99999;
	if (L <= m) res = min(res, findmn(L, R, lson));
	if (m <  R) res = min(res, findmn(L, R, rson));
	return res;
}
void solve(int l, int r) {
	if (l > r) return;
	int num = findmn(l, r, 1, n, 1);
	int x = num - qsum(l);
	ans += x;
	add(l, x);
	add(r + 1, -x);
	int L = findL(a[num], l);
	int R = findR(a[num], r);
	int pre = l;
	for (int i = L; i <= R; ++i) {
		solve(pre, a[num][i] - 1);
		pre = a[num][i] + 1;
	} solve(pre, r);
		
}
void build(int l, int r, int rt) {
	if (l == r) {
		f[rt] = d[l]; return;
	}
	int m = (l + r) >> 1;
	build(lson); build(rson);
	f[rt] = min(f[ls], f[rs]);	
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int x, i = 1; i <= n; ++i) {
		scanf("%d", &x);
		d[i] = x;
		a[x].push_back(i);
	}
	build(1, n, 1);	
	solve(1, n);
	printf("%d\n", ans);
	return 0;
}
