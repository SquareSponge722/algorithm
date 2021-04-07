#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 5e3 + 10;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int N, M;
vector<int> g[MAXN];
vector<P> edges;

bool vis[MAXN]; P Ban;
int ans[MAXN], pa, res[MAXN], pr;
void dfs(int u) {
	vis[u] = true; res[++pr] = u;
	for(int i = 0; i < (int) g[u].size(); i++) {
		int &v = g[u][i];
		if(N == M && (P(u, v) == Ban || P(v, u) == Ban)) continue;
		if(!vis[v])	dfs(v);
	}
}

inline bool check() {
	if(pr != N) return false;
	for(int i = 1; i <= N; i++) {
		if(ans[i] > res[i]) return true;
		if(ans[i] < res[i]) return false;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>N>>M;
	for(int i = 1, u, v; i <= M; i++) {
		u = read(), v = read();
		g[u].push_back(v); g[v].push_back(u);
		edges.push_back(P(u, v));
	}
	for(int i = 1; i <= N; i++)
		sort(g[i].begin(), g[i].end());
	if(M == N - 1) {
		dfs(1);
		for(int i = 1; i <= N; i++) {
			printf("%d", res[i]); 	
			if(i != N) putchar(' ');
		}	
	}
	else {
		for(int i = 0; i < M; i++) {
			Ban = edges[i]; pr = 0;
			dfs(1);
			if(pr == N && (pa == 0 || check())) 
				memcpy(ans, res, sizeof(ans)), pa = N;
			memset(vis, false, sizeof(vis));
		}
		for(int i = 1; i <= N; i++) {
			printf("%d", ans[i]);
			if(i != N) putchar(' ');
		}
				
	}
	return 0;
}
