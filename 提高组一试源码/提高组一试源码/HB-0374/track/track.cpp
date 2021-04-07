#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
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

const int NMX = 5 * 1e5 + 7;
const int inf = 0x7fffffff;
int n, m;
int ai, bi, li;

int head[NMX], en;
struct Edge { int to, nx, w; } e[NMX<<1];
inline void add(int u, int v, int w) {
	e[en] = Edge{v, head[u], w};
	head[u] = en++;
}

bool vis[NMX<<1];
int out[NMX], opt[NMX<<1];
int minl = inf;
ll low, high, mid, tol;
ll ans = 0;

inline bool ok(long long x, int u, int goal) {
	if(goal == m) {
		ans = max(ans, mid);
		return 1;
	} 
	if(x >= mid) return ok(0, 0, goal + 1);
	if(!out[u] && u) return 0;
	for(rg i = head[u]; ~i; i = e[i].nx) {
		int v = e[i].to, w = e[i].w;
		if(vis[i]) continue;
		if(u) vis[opt[i]] = vis[i] = 1; 
		if(ok(x + w, v, goal)) {
			if(u) vis[opt[i]] = vis[i] = 0;
			return 1;
		}
		else vis[opt[i]] = vis[i] = 0;
		if(x + w >= mid) break;
	}
	return 0;
}

int main() {
	File("track");
	int x;
	mes(head, -1); qrd(n), qrd(m);
	fr(i, 1, n-1) {
		qrd(ai), qrd(bi), qrd(li); 
		tol += li, minl = min(minl, li);
		add(ai, bi, li); opt[en - 1] = en;
		add(bi, ai, li); opt[en - 1] = en - 2;
		out[ai]++, out[bi]++;
		if(out[ai] == 1) add(0, ai, 0); 
		if(out[bi] == 1) add(0, bi, 0);
	}
	low = minl;
	high = tol + 1;
	while(low + 1 < high) {
		mid = (low + high)>>1;
		if(ok(0, 0, 0)) low = mid;
		else high = mid;
	}
	printf("%lld\n", ans); 
	return 0;
}
