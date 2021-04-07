#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,aa,bb;
priority_queue<int,vector<int>,greater<int> > q[maxn],pq;
vector<int> path[maxn];
bool vis[maxn];
void dfs(int x) {
	while(!q[x].empty()) {
		int v=q[x].top();
		q[x].pop();
		if(vis[v])continue;
		vis[v]=1;
		printf("%d ",v);
		dfs(v);
	}
}
void dfs2(){
	while(!pq.empty()){
		int u=pq.top();
		pq.pop();
		while(!q[u].empty()){
			int v=q[u].top();
			q[u].pop();
			if(vis[v])continue;
			vis[v]=1;
			printf("%d ",v);
			pq.push(v);
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==m-1) {
		for(int i=1; i<=m; i++) {
			scanf("%d%d",&aa,&bb);
			q[aa].push(bb);
			q[bb].push(aa);
		}
		printf("1 ");
		vis[1]=1;
		dfs(1);
	}
	else {
		for(int i=1;i<=m;i++){
			scanf("%d%d",&aa,&bb);
			q[aa].push(bb);
			q[bb].push(aa);
		}
		printf("1 ");
		pq.push(1);
		vis[1]=1;
		dfs2();
	}
}
