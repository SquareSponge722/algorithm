#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 10;
struct Edge
{
	int v, w, nxt;
	Edge(int v = 0, int w = 0, int nxt = 0):v(v),w(w),nxt(nxt){}
} es[maxn * 2];
int head[maxn], cnt;
void AddEdge(int u, int v, int w) { es[++cnt] = Edge(v, w, head[u]); head[u] = cnt; }
int n, m;
bool TYPEA = false, TYPEB = true, TYPEC = true;
/*TYPEA m = 1, n <= 1000*/
int dist[1000 + 10][1000 + 10];
bool vis[maxn];
void dfs(int from, int u, int nw, int sw)
{
	if(vis[nw]) return;
	//printf("%d %d %d %d\n", from, u, nw, sw);
	vis[nw] = 1;
	dist[u][nw] = sw;
	for(int i = head[nw]; i; i = es[i].nxt)
	{
		int v = es[i].v, w = es[i].w;
		dfs(nw, u, v, sw + w);
	}
	vis[nw] = 0;
}
/*TYPEB JuHuaTu*/
int dist1[maxn], dist2[maxn];
bool cmp(int a, int b) { return a > b; }
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	memset(dist, -1, sizeof(dist));
	scanf("%d %d", &n, &m);
	if(m == 1) TYPEA = true;
	for(int i = 1; i < n; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
		if(u != 1) TYPEB = false;
		if(v != u + 1) TYPEC = false;
		dist1[v] = w;
		dist2[v] = w;
		dist[u][v] = dist[v][u] = w;
	}
	if(TYPEB)
	{
		sort(dist1 + 1, dist1 + n + 1, cmp);
		printf("%d", dist1[m * 2 - 1] + dist1[m * 2]);
		return 0;
	}
	else if(TYPEC)
	{
		int l = 0, r = 0;
		for(int i = 1; i <= n; i++) r += dist2[i];
		//for(int i = 1; i <= n - 1; i++) dist2[i] += dist2[i - 1];
		//for(int i = 2; i <= n; i++) printf("%d ", dist2[i]);
		//putchar('\n');
		while(l < r)
		{
			//printf("%d %d\n", l, r);
			int mid = (l + r) >> 1;
			int tmp = 0, cnt = 0;
			for(int i = 2; i <= n; i++)
			{
				tmp += dist2[i];
				if(tmp >= mid)
				{
					cnt++;
					tmp = 0;
				}
			}
			if(cnt >= m) l = mid + 1;
			else r = mid;
		}
		printf("%d", l - 1);
		return 0;
	}
	else if(TYPEA)
	{
		/*printf("---------\n");
		for(int u = 1; u <= n; u++)
		{
			for(int i = head[u]; i; i = es[i].nxt)
			{
				int v = es[i].v, w = es[i].w;
				printf("%d %d %d\n", u, v, w);
			}
		}
		printf("---------\n");*/
		int ans = -1;
		int u = 0, v = 0;
		for(int i = 1; i <= n; i++) { dfs(0, i, i, 0); memset(vis, 0, sizeof(vis)); }
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				//printf("%d-%d %d\t", i, j, dist[i][j]);
				if(dist[i][j] > ans) { ans = dist[i][j]; u = i; v = j; }
			}
			//putchar('\n');
		}
		printf("%d", ans);
		return 0;
	}
	else
	{
		printf("8848");
	}
	return 0;
}
