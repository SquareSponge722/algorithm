#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#define maxn 2000
#define inf 2147483647
using namespace std;

int n, m, qian[maxn];
char od[10];
vector<int>G[maxn];

struct query {
	int A, B, a, b, ans;
}q[maxn];

struct edge {
	int a, b;
}e[maxn];

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &n, &m, &od);
	for (int i = 1; i <= n; i++) scanf("%d", &qian[i]);
	for (int i = 1; i < n; i++) {
		int x, y;scanf("%d%d", &x, &y);
		e[i].a = x, e[i].b = y;
	}
	for (int i = 1; i <= m; i++) 
		scanf("%d%d%d%d", &q[i].A, &q[i].a, &q[i].B, &q[i].b), q[i].ans = inf;
	for (int state = (1 << (n + 1)) - 1; state; state--) {
		int sta = state, cost = 0; bool check = true;
		for (int i = 1; i <= n; i++) {
			if ((1 << i) & sta) cost += qian[i];
		}
		for (int i = 1; i <= n - 1; i++) {
			int u = e[i].a, v = e[i].b;
			if (!((1 << (u)) & sta))
				if (!((1 << (v)) & sta)) {
					check = false; break;
				}
		}
		if (check == false) continue;
		for (int i = 1; i <= m; i++) {
			int a = q[i].a, A = q[i].A;
			int b = q[i].b, B = q[i].B;
			bool fail = false;
			if (a == 0) {
				if (((1 << A) & sta) != 0) fail = true;
			} 
			if (a == 1) {
				if (((1 << A) & sta) == 0) fail = true;
			} 
			if (b == 0) {
				if (((1 << B) & sta) != 0) fail = true;
			} 
			if (b == 1) {
				if (((1 << B) & sta) == 0) fail = true;
			} 
			if (!fail) q[i].ans = min(q[i].ans, cost);		
		}
	}	
	for (int i = 1; i <= m; i++) {
		if (q[i].ans == inf) printf("-1\n");
		else printf("%d\n", q[i].ans);
	}
	return 0;
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/
