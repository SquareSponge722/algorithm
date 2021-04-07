#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 5010;
const int inf  = 9000000;

inline int read() {
	int rtn = 0; char ch = getchar(); bool f = false;
	for (; !isdigit(ch); ch = getchar()) f |= ch == '-';
	for (;  isdigit(ch); ch = getchar()) rtn = (rtn << 1) + (rtn << 3) + ch - '0';
	return f ? -rtn : rtn;
}

vector<int>G[maxn];
int ans[maxn];

namespace case1 {
	bool vis[maxn];
	inline void solve(int k, int f) {
		vis[k] = true;
		ans[++ans[0]] = k;
		for (int i = 0; i < G[k].size(); i++) {
			int kk = G[k][i];
			if (vis[kk]) continue;
			solve(kk, k);
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		G[x].push_back(y); G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	case1::solve(1, 0);
	for (int i = 1; i <= ans[0]; i++) printf("%d ", ans[i]);
	return 0;
}
