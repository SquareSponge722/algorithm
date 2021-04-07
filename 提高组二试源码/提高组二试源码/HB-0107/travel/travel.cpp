#include<bits/stdc++.h>
using namespace std;
struct node {
	int p[5001];
};
node q[5001];
queue<int> ans;
int m,n;
int r[10005],cnt,ls[5001];
int fa[5005],pass[5005],pd;
vector<int> path[5005];
void dfs(int x) {
	pass[x]=1;
	ans.push(x);
	for(register int i=0; i<path[x].size(); i++) {
		if(path[x][i]==fa[x]) continue;
		fa[path[x][i]]=x;
		q[x].p[++ls[x]]=path[x][i];
		sort(q[x].p+1,q[x].p+ls[x]+1);
//		printf("%d\n",q[x].p[1]);
	}
	for(int i=1; i<=ls[x]; i++) {
		dfs(q[x].p[i]);
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1; i<=m; i++) {
		int from,to;
		scanf("%d%d",&from,&to);
		path[from].push_back(to);
		path[to].push_back(from);
		r[++cnt]=from;
		r[++cnt]=to;
	}
	sort(r+1,r+cnt+1);
	if(m==n-1) {
		dfs(r[1]);
	}
	while(!ans.empty()) {
		printf("%d ",ans.front());
		ans.pop();
	}
	return 0;
}
/*
6 5
1 3
2 1
6 5
3 4
3 6

*/
