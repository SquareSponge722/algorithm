#include <bits/stdc++.h>
using namespace std;

inline int read(int u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = u * 10 + c - '0';
	return f ? -u : u;
}

const int maxn = 5000 + 10;

bool same;
int ban = -1;
int now_ans[maxn], now_pos;

vector<pair<int, int> >G[maxn];

bool dfs(int u, int fa) {
	now_pos++;
	if (same && now_ans[now_pos] < u) return false;
	same &= now_ans[now_pos] == u;
	now_ans[now_pos] = u;
	for (int i = G[u].size() - 1; ~i; --i) {
		int v = G[u][i].first;
		if (v == fa) continue;
		int w = G[u][i].second;
		if (w == ban) continue;
		if (!dfs(v, u)) return false;
	}
	return true;
}

vector<int>loop;
vector<int>stk;
bool ins[maxn], vis[maxn];
int out[maxn];

void get_loop(int u) {
	ins[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		if (vis[G[u][i].second]) continue;
		vis[G[u][i].second] = true;
		out[u] = G[u][i].second;
		stk.push_back(out[u]);
		if (ins[v]) {
			int e = out[v];
			int p = stk.size() - 1;
			loop.push_back(e);
			while (stk[p] != e)
				loop.push_back(stk[p--]);
		} 
		else get_loop(v);		
		stk.pop_back();
	}
	ins[u] = false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 0; i < m; i++) {
		int u = read(), v = read();
		G[u].push_back(make_pair(v, i));
		G[v].push_back(make_pair(u, i));
	}
	for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	for (int i = 1; i <= n; i++) reverse(G[i].begin(), G[i].end());
	for (int i = 1; i <= n; i++) now_ans[i] = n;
	if (m == n - 1) {
		now_pos = 0;
		dfs(1, -1);
	}
	else {
		get_loop(1);
		//for (int i = 0; i < loop.size(); i++) 
		//	cout << loop[i] << ' '; cout << endl;
		for (int i = 0; i < loop.size(); i++) 
			same = true, now_pos = 0, ban = loop[i], dfs(1, -1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", now_ans[i]);
		return 0;
}

/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6

*/
