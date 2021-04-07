#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 100005
#define ll long long
using namespace std;
vector<int> g[maxn];
string opt;
int n, m, cost[maxn], tag[maxn];
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d", &n, &m); cin >> opt;
	for (int i = 1; i <= n; i ++)
		scanf("%d", &cost[i]);
	for (int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	for (int i = 1; i <= m; i ++) {
		memset(tag, -1, sizeof tag);
		int a, x, b, y, flag = 0;
		scanf("%d%d%d%d", &a, &x, &b, &y);
		tag[a] = x; tag[b] = y;
		queue<int> q; q.push(a); q.push(b);
		while (q.size()) {
			int t = q.front(); q.pop();  
			for (int i = 0; i < (int)g[t].size(); i ++) {
				int v = g[t][i], col = !(tag[t]);
				if (tag[v] == -1) tag[v] = col, q.push(v);
				else if (tag[v] != col && tag[v] != -1) { cout << -1 << endl, flag = 1; break; }
			}
			if (flag) break;
		}
		if (!flag) {
			ll ans = 0;
			for (int i = 1; i <= n; i ++)
				if (tag[i] == 1) ans += cost[i];
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
