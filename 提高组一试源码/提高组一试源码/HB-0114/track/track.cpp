#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define maxn 30005
#define max(a, b) (a) > (b) ? (a) : (b)
#define ll long long
using namespace std;
struct pr { int w, to, next; } e[maxn];
int n, m, cur, dis[maxn], hd[maxn];
bool vis[maxn];
ll ans, tmax;
void add (int u, int v, int w) {
	e[++ cur].next = hd[u];
	e[cur].to = v;
	e[cur].w = w;
	hd[u] = cur;
}
void spfa (int st) {
	for (int i = 1; i <= n; i ++) 
		vis[i] = 0, dis[i] = 1e9;
	vis[st] = 1; dis[st] = 0;
	queue<int> q; q.push(st);
	while (q.size()) {
		int u = q.front(); q.pop(); vis[u] = false;
		for (int i = hd[u]; i; i = e[i].next) {
			int v = e[i].to, w = e[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) vis[v] = true, q.push(v);
			}
		}
	}
	tmax = 0;
	for (int i = 1; i <= n; i ++)
		if (st == i) continue;
		else tmax = max(tmax, dis[i]);
	ans = max(ans, tmax);
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i ++) {
		int u, v, w; cin >> u >> v >> w;
		add (u, v, w); add (v, u, w);
	}
	for (int i = 1; i <= n; i ++) spfa(i);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
