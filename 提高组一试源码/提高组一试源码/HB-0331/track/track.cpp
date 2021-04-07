#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 50005;
struct Edge {
	int v, w;
};
int n, m, dis[N];
vector < Edge > g[N];
void dfs(int u, int f) {
	for (int v, w, i = 0; i < g[u].size(); ++i) {
		v = g[u][i].v; w = g[u][i].w;
		if (v == f) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
	}
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int u, v, w, i = 1; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back((Edge){v, w});
		g[v].push_back((Edge){u, w});
	}
	dfs(1, 1);
	int mx = 0, a;
	for (int i = 1; i <= n; ++i) {
		if (dis[i] > mx) {
			a = i; mx = dis[i];
		} dis[i] = 0;
	}
	mx = 0;
	dfs(a, a); 
	for (int i = 1; i <= n; ++i)
		mx = max(mx, dis[i]);
	printf("%d\n", mx);	
	return 0;
}
