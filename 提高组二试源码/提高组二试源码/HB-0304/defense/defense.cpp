#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#define MAX 999999999999999
#define MIN -999999999999999
#define INF 50000000000
#define ll long long
#define int long long
using namespace std;
inline void read(register int &x){
	x = 0; register int f = 1;
	register int ch = getchar();
	while (!(ch >= '0' && ch <= '9')){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
const int N = 100000 + 10;
const int M = 100000 + 10;
int n, m;
int p[N], e_num, prt[N], lian[N], cnt, val[N], x, y, f1, f2, fg[2][N];
int in[N], f[N][2];
struct Edge{int b, nt;} e[N * 2];
char s[5];
inline void anode(register int u, register int v){
	e[++e_num].b = v;
	e[e_num].nt = p[u];
	p[u] = e_num;
}

inline void dfs(register int u){
	f[u][1] = val[u];
	for (register int edge = p[u]; edge > 0; edge = e[edge].nt){
		register int v = e[edge].b;
		if (v != prt[u]){
			prt[v] = u;
			dfs(v);
			f[u][0] += f[v][1];
			f[u][1] += min(f[v][0], f[v][1]);
		}
	}
	if ((u == x && f1 == 0) || (u == y && f2 == 0)) f[u][1] = INF;
	else if ((u == x && f1 == 1) || (u == y && f2 == 1)) f[u][0] = INF;
}

signed main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%lld %lld %s", &n, &m, s + 1);
	for (register int i = 1; i <= n; i++) read(val[i]);
	for (register int i = 1; i < n; i++){
		register int u, v; read(u), read(v);
		anode(u, v); anode(v, u);
		in[u]++, in[v]++;
	}
	if (s[1] == 'A'){
		register int st = 0;
		for (register int i = 1; i <= n; i++){
			if (in[i] == 1){
				st = i;break;
			}
		}
		while (true){
			lian[++cnt] = st;
			bool fg = 0;
			for (register int edge = p[st]; edge > 0; edge = e[edge].nt){
				register int v = e[edge].b;
				if (v != prt[st]){
					fg = 1;
					prt[v] = st;
					st = v;
					break;
				}
			}
			if (fg == 0) break;
		}
		int sum0 = 0, sum1 = 0;
		for (register int j = 1; j <= n; j += 2){
			fg[0][j] = 1;
			sum0 += val[lian[j]];
		}
		for (register int j = 2; j <= n; j += 2){
			fg[1][j] = 1;
			sum1 += val[lian[j]];
		}
		for (register int i = 1; i <= m; i++){
			read(x), read(f1), read(y), read(f2);
			register int ans = MAX;
			if (fg[0][x] == f1 && fg[0][y] == f2){
				ans = min(ans, sum0);
			}
			if (fg[1][x] == f1 && fg[1][y] == f2){
				ans = min(ans, sum1);
			}
			if (ans == MAX) ans = -1;
			printf("%lld\n", ans);
		}
	}
	else{
		for (register int j = 1; j <= m; j++){
			read(x), read(f1), read(y), read(f2);
			memset(f, 0, sizeof(f));
			dfs(1);
			register int ans = min(f[1][0], f[1][1]);
			if (ans >= INF) ans = -1;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
