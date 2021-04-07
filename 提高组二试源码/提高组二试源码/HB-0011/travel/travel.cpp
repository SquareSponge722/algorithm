#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<queue>
#include<vector>

#define N 5001
#define inf 0x3f3f3f3f

using namespace std;

int n, m;
bool vis[N];
vector <int> e[N];


void init() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
}

void dfs(int u) {
	if(vis[u])
		return;
	printf("%d ", u);
	vis[u] = 1;
	
	priority_queue <int, vector<int>, greater<int> > q;
	while(!q.empty())	q.pop();
	
	for(int i = 0; i < e[u].size(); i ++) 
		q.push(e[u][i]);
	while(!q.empty()) {
		int v = q.top();
		q.pop();
		dfs(v);
	}
	return;
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	return 0;
}
