#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=50001;
int n,m;
struct node {
	int to,val;
	node(int i,int j) {
		to=i;
		val=j;
	}
};
int indeg[maxn]={0};
vector<node> g[maxn];
bool vis[maxn]={false};
int ans=0;

void dfs(int start,int cur,int step) {
	if(indeg[cur]==1 && cur!=start) {
		ans=max(step,ans);
		return;
	}
	vis[cur]=true;
	for(int i=0;i<g[cur].size();i++) {
		int v=g[cur][i].to,w=g[cur][i].val;
		if(!vis[v])  {
			vis[v]=true;
			dfs(start,v,step+w);
			vis[v]=false;
		}
	}
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<n;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back(node(v,w));
		g[v].push_back(node(u,w));
		indeg[u]++;
		indeg[v]++;
	}
	for(int i=1;i<=n;i++) {
		if(indeg[i]==1) {
			fill(vis,vis+maxn,false);
			dfs(i,i,0);
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
