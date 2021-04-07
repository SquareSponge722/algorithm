#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q[5005];
bool mark[5005];
int ans[5005];
int tot;
int n, m, a, b;

void dfs(int i){
	if(tot == n){
		return;
	}
	while(q[i].size()){
		int v = -q[i].top();q[i].pop();
		if(!mark[v]){
			mark[v] = true;
			ans[tot++] = v;
			dfs(v);
		}
	}
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a);
		scanf("%d", &b);
		q[a].push(-b);
		q[b].push(-a);
	}
	ans[tot ++] = 1;
	mark[1] = true;
	dfs(1);
	for(int i = 0; i < tot; i ++){
		printf("%d ", ans[i]);
	}
}
