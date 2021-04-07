#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>

#define N 50010
#define inf 0x3f3f3f3f

using namespace std;

int n, m, cnt, ans;
int head[N], dis[N], in[N];
queue <int> q;

struct Edge{
	int v, w, next;
	Edge() {}
	Edge(int v, int w, int next): v(v), w(w), next(next) {}
}e[N << 2];

void init() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
}

void add(int u, int v, int w) {
	e[++ cnt] = Edge(v, w, head[u]);
	head[u] = cnt;
} 

void spfa(int s) {
	while(!q.empty())
		q.pop();
	for(int i = 1; i <= n; i ++)
		dis[i] = inf, in[i] = 0;
	dis[s] = 0;
	q.push(s);
	in[s] = 1;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(int k = head[u]; k != -1; k = e[k].next) {
			int v = e[k].v, w = e[k].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				ans = max(ans, dis[v]);
				if(in[v])
					continue;
				q.push(v);
				in[v] = 1;
			}
		}
	}

}

int main() {
	init();
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for(int i = 1; i <= n; i ++)
		spfa(i);
	printf("%d\n", ans);
	return 0;
}
