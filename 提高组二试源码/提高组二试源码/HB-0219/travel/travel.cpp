#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
void read(int &x) {
	static char buf = getchar(); register int f = 1; x = 0;
	for (; !isdigit(buf); buf = getchar()) if (buf == '-') f = -1;
	for (;  isdigit(buf); buf = getchar()) x = x * 10 + buf - 48; x *= f;
}
const int N = 5e3 + 10;
set<int> edge[N];
int n, m;
void init() {
	read(n), read(m);
	for (int i = 1, u, v; i <= m; ++i) {
		read(u), read(v);
		edge[u].insert(v);
		edge[v].insert(u);
	}
}
namespace condition_tree {
	vector<int> ans;
	void dfs(int u, int f) {
		ans.push_back(u);
		for (set<int>::iterator it = edge[u].begin(); it != edge[u].end(); ++it) {
			if (*it == f) continue;
			dfs(*it, u);
		}
	}
	int main() {
		dfs(1, -1);
		for (int i = 0; i < ans.size(); ++i)
			printf("%d ", ans[i]);
		puts("");
		return 0;
	}
}
namespace condition_graph {
	int main() {
		return 0;
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	init();
	if (m == n - 1) condition_tree::main();
	else condition_graph::main();
	return 0;
}
