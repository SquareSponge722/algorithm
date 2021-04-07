#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define gc getchar
#define MAXN 100007
using namespace std;
int n, m, p[MAXN], v[MAXN], f[MAXN];
char tp[3];
vector < int > G[MAXN];

template <class T>
inline void read(T &x){
	static char buf = gc(); x = 0;
	for (; !isdigit(buf); buf = gc());
	for (; isdigit(buf); buf = gc())
		x = (x << 3) + (x << 1) + buf - 48;
}

inline void aE(int x, int y){
	G[x].push_back(y);
}

int dfs(int x, int op){
	int siz = G[x].size(), res = 0;
	if (op) res += p[x];
	for (int i = 0; i < siz; ++i){
		int t = G[x][i];
		if (t == f[x]) continue ;
		if (v[t] == -1) res += max(dfs(t, 0), dfs(t, 1));
		else {
			if (v[t]) res += dfs(t, 1);
			else if (!op) return 0;
		} 
	}
	return res;
}

int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	read(n), read(m);
	scanf("%s", tp);
	for (int i = 1; i <= n; ++i) read(p[i]);
	for (int i = 1; i < n; ++i){
		int a, b;
		read(a), read(b);
		aE(a, b), aE(b, a);
	}
	memset(v, -1, sizeof(v));
	for (int i = 1; i <= m; ++i){
		int a, b, t1, t2;
		read(a), read(b), read(t1), read(t2);
		v[a] = t1, v[b] = t2;
		f[1] = 0;
		int mx = max(dfs(1, 0), dfs(1, 1));
		puts("-1");
	}
	return 0;
}
