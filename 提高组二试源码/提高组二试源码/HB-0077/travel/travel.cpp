#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 5000 + 20;

vector<int> vec, ans;
vector<char> ban;
bool vis[maxN];
vector<pair<int, char*> > g[maxN];
void kaleido(int x) {
	vec.push_back(x);
	vis[x] = true;
	for(int i = 0; i < g[x].size(); i++) {
		if(vis[g[x][i].first] || *g[x][i].second)
			continue;
		kaleido(g[x][i].first);
	}
}

bool cmpStr(vector<int> &a, vector<int> &b) {
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i]) {
			if(a[i] < b[i])
				return true;
			else
				return false;
		}
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	ban.resize(m + 5);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(make_pair(v, &ban[i]));
		g[v].push_back(make_pair(u, &ban[i]));
	}
	
	for(int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());

	if(m == n) {
		for(int i = 0; i < m; i++) {w
			ban[i] = true;
			vec.clear();
			memset(vis, 0, (n + 1) * sizeof(bool));
			kaleido(1);
//			for(int j = 0; j < vec.size(); j++)
//				cout << vec[j] << ' ';
//			cout << endl;
			if(vec.size() == n && (ans.empty() || cmpStr(vec, ans)))
				ans = vec;
			ban[i] = false;
		}
	} else {
		kaleido(1);
		ans = vec;
	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
