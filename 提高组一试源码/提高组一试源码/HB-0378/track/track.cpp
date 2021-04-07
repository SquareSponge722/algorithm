#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 5e4 + 7;
int n, m, res, f[MAXN], d1[MAXN], d2[MAXN], dx[MAXN];

struct Edge{
	int v, w;
	Edge(int v = 0, int w = 0): v(v), w(w) {}
};
vector < Edge > G[MAXN];

inline void aE(int x, int y, int z){
	G[x].push_back(Edge(y, z));
}

int dfs(int x, int dep){
	int siz = G[x].size(), d = 0;
	dx[x] = dep;
	for (int i = 0; i < siz; ++i){
		Edge t = G[x][i];
		if (t.v != f[x]){
			f[t.v] = x, d = t.w + dfs(t.v, dep + t.w);
			if (d > d1[x]) d2[x] = d1[x], d1[x] = d;
			else if (d > d2[x]) d2[x] = d;
		}
	}
	return d1[x];
}

#define Max(a, b, c) max(max(a, b), c)
void work(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		aE(a, b, c), aE(b, a, c);
	}
	f[1] = 0;
	int tmp = dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		res = Max(res, d1[i] + d2[i], d1[i] + dx[i]);
	printf("%d\n", res);
}

int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	work(); 
	return 0;
}
