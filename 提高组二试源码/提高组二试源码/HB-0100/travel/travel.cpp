#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, kotae[5010], itadaki;
struct Datta {
	int a, b;
} junbi[5010];
vector<int> shus[5010]; //shus[i]: the sons of vertex i

inline bool operator<(Datta a, Datta b) {
	return a.a == b.a ? a.b < b.b : a.a < b.a;
}

void dfs_in_tree(int x, int old) {
	kotae[itadaki++] = x;
	sort(shus[x].begin(), shus[x].end());
	for (int i = 0; i < shus[x].size(); ++i)
		if (shus[x][i] != old)
			dfs_in_tree(shus[x][i], x);
}

void kaiketu_tree() {
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		shus[a].push_back(b);
		shus[b].push_back(a);
	}
	dfs_in_tree(1, 0);
	for (int i = 0; i < n; ++i)
		printf("%d ", kotae[i]);
}

void kaiketu_treeplusone() {
	
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (m == n - 1) kaiketu_tree();
	else kaiketu_treeplusone();
	return 0;
}
