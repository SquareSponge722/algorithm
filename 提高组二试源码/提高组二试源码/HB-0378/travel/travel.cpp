#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAXN 5007
using namespace std;
int n, m, cnt, f[MAXN], ans[MAXN];
bool vis[MAXN], used[MAXN];
vector < int > G[MAXN];

inline void aE(int x, int y){
	G[x].push_back(y);
}

void dfs1(int x){
	ans[++cnt] = x;
	int siz = G[x].size();
	for (int i = 0; i < siz; ++i){
		int t = G[x][i];
		if (t != f[x]) f[t] = x, dfs1(t);
	}
}

void dfs2(int x, int dep, bool fl){
	if (fl){
		if (ans[dep] <= x) return ;
		if (!used[x]) ans[dep] = x, used[x] = 1;
		if (dep == n) return ;
	}
	int siz = G[x].size();
	for (int i = 0; i < siz; ++i){
		int t = G[x][i];
		if (t == f[x]) 
			vis[t] = 1, dfs2(t, dep, false);
		else {
			f[t] = x;
			if (!vis[t]) 
				vis[t] = 1, dfs2(t, dep + 1, true), vis[t] = 0;
		}
	}
}

void work(){
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		aE(a, b), aE(b, a);
	}
	for (int i = 1; i <= n; ++i)
		sort(G[i].begin(), G[i].end());
	if (m == n - 1) f[1] = 0, dfs1(1);
	else {
		memset(ans, 0x3f, sizeof(ans));
		f[1] = 0, dfs2(1, 1, true);
	}
	for (int i = 1; i < n; ++i)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	work(); 
	return 0;
}
