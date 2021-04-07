#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#define MAX 0x7fffffff
#define MIN 0x80000000
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
inline void read(register int &x){
	x = 0; register int f = 1;
	register int ch = getchar();
	while (!(ch >= '0' && ch <= '9')){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
const int N = 5000 + 10;
const int M = 5000 + 10;
int n, m, ans[N], cnt;
int prt[N], fa[N];
int p[N], e_num = 1;
struct Edge{int b, nt;} e[M];
inline void anode(register int u, register int v){
	e[++e_num].b = v;
	e[e_num].nt = p[u];
	p[u] = e_num;
}

inline int getfa(register int x){
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
inline void join(register int x, register int y){
	register int fx = getfa(x), fy = getfa(y);
	if (fx != fy) fa[fx] = fy;
}

inline void dfs(register int u){
	ans[++cnt] = u;
	int tmp[5000 + 10] = {0}, tot = 0;
	for (register int edge = p[u]; edge > 1; edge = e[edge].nt){
		register int v = e[edge].b;
		if (v != prt[u]){
			prt[v] = u;
			tmp[++tot] = v;
		}
	}
	sort(tmp + 1, tmp + 1 + tot);
	for (register int i = 1; i <= tot; i++){
		dfs(tmp[i]);
	}
}
int vis[N], st[N], top;
inline bool dfs1(register int u){
	vis[u] = 1;
	for (register int edge = p[u]; edge > 0; edge = e[edge].nt){
		register int v = e[edge].b;
		if (v != prt[u]){
			prt[v] = u;
			st[++top] = edge;
			if (vis[v] == 1) return true;
			if (dfs1(v) == true) return true;
			top--;
		}
	}
	return false;
}
int now, ans1[N];
inline void dfs2(register int u){
	ans[++cnt] = u;
	int tmp[5000 + 10] = {0}, tot = 0;
	for (register int edge = p[u]; edge > 1; edge = e[edge].nt){
		if (edge == (now ^ 1) || edge == now) continue;
		register int v = e[edge].b;
		if (v != prt[u]){
			prt[v] = u;
			tmp[++tot] = v;
		}
	}
	sort(tmp + 1, tmp + 1 + tot);
	for (register int i = 1; i <= tot; i++){
		dfs2(tmp[i]);
	}
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n), read(m);
	register int node = 0;
	for (register int i = 1; i <= n; i++) fa[i] = i;
	for (register int i = 1; i <= m; i++){
		register int u, v; read(u), read(v);
		register int fu = getfa(u), fv = getfa(v);
		if (fu != fv) join(u, v);
		else if (node == 0) node = u;
		anode(u, v); anode(v, u);
	}
	if (m == n - 1){
		dfs(1);
		for (register int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
		putchar('\n');
	}
	else{
		memset(ans1, 0x3f, sizeof(ans1));
		dfs1(node);
		for (register int i = 1; i <= top; i++){
			memset(prt, 0, sizeof(prt));
			cnt = 0;
			now = st[i];
			dfs2(1);
			if (cnt != n) continue;
			bool fg = 0;
			for (register int i = 1; i <= cnt; i++){
				if (ans[i] < ans1[i]) {
					fg = 1; break;
				}
				else if (ans1[i] < ans[i]) break;
			}
			if (fg == 1) for (register int i = 1; i <= cnt; i++) ans1[i] = ans[i];
		}
		for (register int i = 1; i <= cnt; i++) printf("%d ", ans1[i]);
		putchar('\n');
	}
	return 0;
}
