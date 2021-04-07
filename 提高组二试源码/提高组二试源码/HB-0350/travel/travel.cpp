#include <bits/stdc++.h>
using namespace std;
const int N = 5006;
int n, m, w, tot;
bool vis[N];
priority_queue<pair<int, int> > e[N];
vector<pair<int, int> > ee[N];
int ans[N], s[N];

void dfs(int x) {
	vis[x] = 1;
	cout << x << " ";
	while (e[x].size()) {
		int y = -e[x].top().first;
		e[x].pop();
		if (vis[y]) continue;
		dfs(y);
	}
}

void m_n_1() {
	memset(vis, 0, sizeof(vis));
	dfs(1);
	cout << endl;
}

void dfss(int x) {
	vis[x] = 1;
	s[++tot] = x;
	for (unsigned int i = 0; i < ee[x].size(); i++) {
		int y = ee[x][i].first, id = ee[x][i].second;
		if (vis[y]) continue;
		if (id == w) continue;
		dfss(y);
	}
}

void m_n() {
	for (int i = 1; i <= n; i++) {
		sort(ee[i].begin(), ee[i].end());
		ans[i] = n + 1;
	}
	for (int i = 1; i <= m; i++) {
		w = i;
		tot = 0;
		memset(vis, 0, sizeof(vis));
		dfss(1);
		if (tot != n) continue;
		bool pd;
		for (int i = 1; i <= tot; i++) {
			if (s[i] > ans[i]) {
				pd = 0;
				break;
			}
			if (s[i] < ans[i]) {
				pd = 1;
				break;
			}
		}
		if (pd) memcpy(ans, s, sizeof(s));
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u].push(make_pair(-v, i));
		e[v].push(make_pair(-u, i));
		ee[u].push_back(make_pair(v, i));
		ee[v].push_back(make_pair(u, i));
	}
	if (m == n - 1) {
		m_n_1();
		return 0;
	} else m_n();
	return 0;
}
