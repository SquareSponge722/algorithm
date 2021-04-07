#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#define INF 0x3f3f3f3f
#define MAX 0x7fffffff
#define MIN 0x80000000
#define ll long long
using namespace std;
inline void read(register int &x){
	x = 0; register int f = 1;
	register char ch = getchar();
	while (!(ch >= '0' && ch <= '9')){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
const int N = 50000 + 10;
const int M = 50000 + 10;
int n, m, rt;
int tot[N];
int p[N], e_num, d1[N], d2[N], prt[N];
int node[N], ct, in[N];
struct Edge{int b, nt, w;} e[M];
inline void anode(register int u, register int v, register int w){
	e[++e_num].b = v;
	e[e_num].w = w;
	e[e_num].nt = p[u];
	p[u] = e_num;
}

inline int dfs(register int u, register int dis){
	for (register int edge = p[u]; edge > 0; edge = e[edge].nt){
		register int v = e[edge].b;
		if (v != prt[u]){
			prt[v] = u;
			register int a = dfs(v, e[edge].w);
			if (a > d1[u]){
				d2[u] = d1[u]; d1[u] = a;
			}
			else if (a > d2[u]) d2[u] = a;
		}
	}
	return dis + d1[u];
}
int chain[N], cnt;
inline void gozao(register int u){
	for (register int edge = p[u]; edge > 0; edge = e[edge].nt){
		register int v = e[edge].b;
		if (prt[u] != v){
			prt[v] = u;
			chain[++cnt] = e[edge].w;
			gozao(v);
		}
	}
}
inline bool check(register int x){
	register int sum = 0, cut = 0;
	for (register int i = 1; i <= cnt; i++){
		sum += chain[i];
		if (sum >= x && i != cnt) cut++, sum = 0;
	}
	if (sum < x && cut <= m) return false;
	if (cut >= m) return true;
	return false;
}

int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	register int mn = MAX, l = 0, r = 0;
	read(n), read(m);
	for (register int i = 1; i < n; i++){
		register int u, v, w; read(u), read(v), read(w);
		if (in[u] == 0) in[u] = 1, node[++ct] = u;
		if (in[v] == 0) in[v] = 1, node[++ct] = v;
		r += w;
		tot[u]++, tot[v]++;
		if (rt == 0) rt = u;
		mn = min(mn, w);
		anode(u, v, w); anode(v, u, w);
	}
	if (m == n - 1){
		printf("%d\n", mn);
	}
	else if (m == 1){
		dfs(rt, 0);
		register int ans = 0;
		for (register int i = 1; i <= ct; i++) ans = max(ans, d1[node[i]] + d2[node[i]]);
		printf("%d\n", ans);
	}
	else{
		m--;
		int one = 0, two = 0, id = 0;
		for (register int i = 1; i <= ct; i++){
			register int nd = node[i];
			if (tot[nd] > 2) return 0;
			if (tot[nd] == 2) two++;
			else if (tot[nd] == 1){
				one++;
				if (id == 0) id = nd;
			}
		}
		if (two + one == n && two == n - 2 && one == 2){
			gozao(id);
			while (l <= r){
				int mid = (l + r) / 2;
				if (check(mid) == true) l = mid + 1;
				else r = mid - 1;
			}
			printf("%d\n", r);
		}
	}
	return 0;
}
