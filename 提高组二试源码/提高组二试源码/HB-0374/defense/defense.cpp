#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <string>
#define rg register int
#define fr(i, A, B) for(rg i = A; i <= B; i++)
#define mes(arr, i) memset(arr, i, sizeof arr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;

typedef long long ll;

template <class T>
inline void qrd(T &x) {
	x = 0; char ch; T y = 1;
	while(!isdigit(ch = getchar())) (ch == '-')&&(y = -1);
	while(isdigit(ch)) { x = (x*10) + (ch^48); ch = getchar(); }
	x *= y;
}

const int NMX = 1e5 + 7;
const int inf = 0x7fffffff;
int n, m, val[NMX];
int u, v;
int a, x, b, y;
int col[NMX];
ll ans;
char c[3];

int head[NMX], en;
struct Edge { int to, nx, w; } e[NMX<<1];
inline void add(int u, int v) {
	e[en] = Edge{v, head[u]};
	head[u] = en++;
}

int dep[NMX], dp[NMX];
int valdep[NMX];
inline void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	valdep[dep[u]] += val[u];
	for(rg i = head[u]; ~i; i = e[i].nx) {
		int v = e[i].to;
		if(v != fa) dfs(v, u);
	}
}

inline void work(int u, int fa) {
	if(ans == -1) return;
	if(col[fa] == 0) {
		if(col[u] == -1) col[u] = 1;
		else if(col[u] == 0 && fa) {
			int tmp = val[fa], tmpv;
			for(rg i = head[u]; ~i; i = e[i].nx) {
				int v = e[i].to;
				if(v == fa) continue;	
				if(val[v] <= tmp) {
					tmp = val[v];
					tmpv = v;
				}
			}
			if(tmp == val[fa]) col[fa] = 1, ans = ans + tmp;
			else col[tmpv] = 1;
		}
	}
	else if(col[u] == -1) col[u] = 0;
	if(col[u] == 1) ans += val[u];
	for(rg i = head[u]; ~i; i = e[i].nx) {
		int v = e[i].to;
		if(v == fa) continue;	
		if(u == a && v == b && !x && !y) {
			ans = -1;
			return;
		}
		work(v, u);
	}
}

int main() {
	File("defense");
	mes(head, -1);
	qrd(n), qrd(m); 
	scanf(" %s", c);
	fr(i, 1, n) qrd(val[i]);
	fr(i, 1, n - 1) {
		qrd(u), qrd(v);
		add(u, v), add(v, u);
	}
//	dfs(1, 0);
	while(m--) {
		ans = 0;
		mes(col, -1);
		qrd(a), qrd(x), qrd(b), qrd(y);
		col[b] = y;
		work(a, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
