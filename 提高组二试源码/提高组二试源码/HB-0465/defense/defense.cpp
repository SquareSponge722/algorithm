#include <cstdio>
#include <algorithm>
#define maxn 100005
#define inf 1000000000

/*
dp[i][0/1]表示i选/不选时子树内完全覆盖的最小值
dp[i][1]=sigma(min(dp[s][0/1]))+vi
dp[i][0]=sigma(dp[s][1])
*/

int dp[maxn][2], a, x, b, y, val[maxn], fa[maxn], n, q;

struct edge {
	int v, nxt;
}edges[maxn<<1];
int head[maxn]={0}, tail=0;
void add_edge(int u, int v) {
	edges[++tail].v=v;
	edges[tail].nxt=head[u];
	head[u]=tail;
}
char type[100];

int dfs(int u, int f) {
	fa[u]=f;dp[u][0]=dp[u][1]=0;
	int tmp=0, tmp2=0;
	for (int i=head[u];i;i=edges[i].nxt) {
		if (edges[i].v!=f) {
			dfs(edges[i].v, u);
			tmp+=std::min(dp[edges[i].v][0], dp[edges[i].v][1]);
			tmp2+=dp[edges[i].v][1];
			if (tmp2>inf) tmp2=inf;
		}
	}dp[u][1]=tmp+val[u];
	dp[u][0]=tmp2;
	if (u==a) dp[u][x^1]=inf;
	if (u==b) dp[u][y^1]=inf;
//	printf("%d: %d %d\n", u, dp[u][0], dp[u][1]);
	return 0;
}
	

int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	int u, v;
	scanf("%d %d %s", &n, &q, type+1);
	for (int i=1;i<=n;++i) scanf("%d", &val[i]);
	for (int i=1;i<n;++i) {
		scanf("%d %d", &u, &v);
		add_edge(u, v); add_edge(v, u);
	}dfs(1, 0);
	while (q--) {
		scanf("%d %d %d %d", &a, &x, &b, &y);
		if (x==0&&y==0&&(fa[a]==b||fa[b]==a)) {
			printf("-1\n"); continue;
		} dfs(1, 0);
		printf("%d\n", std::min(dp[1][0], dp[1][1]));
	}
	return 0;
}
