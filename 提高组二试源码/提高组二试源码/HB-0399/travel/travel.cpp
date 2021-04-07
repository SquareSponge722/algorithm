#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

const int maxn=5001;
int n,m;
vector<int> g[maxn];
bool vis[maxn];
bool fnd=false;
stack<int> st;
vector<int> ans;

void dfs(int cur) {
	if(cur==n) {
		fnd=true;
		return;
	}
	if(fnd) return;
	for(int i=0; i<g[cur].size(); i++) {
		int v=g[cur][i];
		if(!vis[v]) {
			vis[v]=true;
			if(!fnd) st.push(v);
			dfs(v);
			if(!fnd&&!vis[v]) st.pop();
			vis[v]=false;
		}
	}
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1; i<=n; i++) sort(g[i].begin(),g[i].end());
	for(int i=1; i<=n; i++) {
		st=stack<int>();
		fill(vis,vis+maxn,false);
		vis[i]=true;
		st.push(i);
		dfs(i);
		if(fnd) break;
	}
	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
