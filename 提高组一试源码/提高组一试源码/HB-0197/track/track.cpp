#include <cstdio>#include <cstdlib>#include <algorithm>#include <vector>const int N = 50005;using namespace std;int n, m, root, num[N], vis[N], outgree[N], ans, s, ans_[N], block[N], fa[N];struct node {int a, b;};vector <node> E[N];inline void dfs(int u, int dep, int f){	for (int i = 0; i < E[u].size(); i++)	{		int v = E[u][i].a;		if (!vis[v])		{			vis[v] = 1; outgree[u]++;			if (dep == 0) {fa[v] = v; f = v;}			else fa[v] = f;			num[v] = max(num[v], num[u] + E[u][i].b);			dfs(v, dep + 1, f);		}	}}inline void init(){	freopen("track.in", "r", stdin);	freopen("track.out", "w", stdout);}int main(){	init();	scanf("%d %d", &n, &m); int f = 0;	for (int i = 1; i < n; i++)	{		int x, y, z;		scanf("%d %d %d", &x, &y, &z);		s += z;		if (x != 1 && y != 1) f = 1;		E[x].push_back((node){y, z}); E[y].push_back((node){x, z});	}	if (m == 1)	{		root = 1; vis[root] = 1;		dfs(root, 0, 0); int dfn = 0;		for (int i = 1; i <= n; i++)		{			if (!outgree[i])				if (!block[fa[i]])				{					block[fa[i]] = ++dfn;					ans_[block[fa[i]]] = max(ans_[block[fa[i]]], num[i]);				}				else ans_[block[fa[i]]] = max(ans_[block[fa[i]]], num[i]);		}		int x = 0; int y = 0; int o; 		for (int i = 1; i <= dfn; i++)			{if (x < ans_[i]) o = i; x = max(x, ans_[i]);}		for (int i = 1; i <= dfn; i++)			if (i != o) y = max(y, ans_[i]);		ans = x + y;	}	if (m != 1 && !f) ans = s / m;		printf("%d", ans);	return 0;}