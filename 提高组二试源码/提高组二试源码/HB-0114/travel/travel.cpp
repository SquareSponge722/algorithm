#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 5005
using namespace std;
vector<int> a[maxn];
vector<int> ans;
priority_queue< int, vector<int>, greater<int> > tmp;
int n, m;
bool vis[maxn], vis_ans[maxn];
void init() { for (int i = 0; i <= maxn - 2; i ++) vis[i] = vis_ans[i] = false; }
void dfs (int u, int cnt) {
	if (cnt == n || vis[u]) return;
//	if (!vis_ans[u]) vis_ans[u] = true, 
	ans.push_back(u); vis[u] = true;
	for (int i = 0; i < (int)a[u].size(); i ++) {
		int v = a[u][i];
		if (!vis[v]) tmp.push(v);
//		vis[v] = false;
	}
	while (tmp.size()) {
		int v = tmp.top(); tmp.pop();
		dfs(v, cnt + 1);
	}
}
void bfs (int u) {
	priority_queue< int, vector<int>, greater<int> > q; q.push(u);
	vector<int> t;
	while (q.size()) {
		int st = q.top(); q.pop(); 
		vis[st] = true; 
		if (!vis_ans[st]) vis_ans[st] = true, t.push_back(st);
		for (int i = 0; i < (int)a[st].size(); i ++) {
			int v = a[st][i];
			if (!vis[v]) {
				q.push(v);
			}
		}
	}
	for (int i = 0; i < (int)t.size(); i ++)
		cout << t[i] << " ";
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if (m == n - 1) init(), dfs(1, 1);
	for (int i = 0; i < (int)ans.size(); i ++) 
		cout << ans[i] << ' ';
	if (m == n) init(), bfs(1);
	fclose(stdin);
	fclose(stdout)
	return 0;
}

