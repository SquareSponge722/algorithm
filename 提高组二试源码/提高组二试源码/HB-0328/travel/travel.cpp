#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>ve,g[5004];
int n,m,firstvis[5004],vis[5004];

void dfs(int u,int nvis) {
	if(nvis==n) {
		for(int i=0; i<ve.size(); i++)cout<<ve[i]<<" ";
		cout<<endl;
		exit(0);
	}
	/*for(int p=0; p<g[u].size(); p++) {
		int v=g[u][p];
		if(!cut[u][v])kasi=0;
	}
	if(kasi)return;*/
	int comepos=0;
	for(int p=0; p<g[u].size(); p++) {
		int v=g[u][p];
		//if(cut[u][v])continue;
		//cut[u][v]=1;
		if(firstvis[u]==v) {
			comepos=v;
			continue;
		}
		if(vis[v])continue;
		//if(!vis[v]) {
		vis[v]=1;
		ve.push_back(v);
		firstvis[v]=u;
		dfs(v,nvis+1);
		//dfs(v,nvis);
		ve.erase(ve.begin()+ve.size()-1);
		vis[v]=0;
		//cut[u][v]=0;
		firstvis[v]=0;
	}
	dfs(comepos,nvis);
}
bool cmp(int x,int y) {
	return x<y;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);

		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1; i<=n; i++)sort(g[i].begin(),g[i].end(),cmp);
	ve.push_back(1);
	dfs(1,1);

}
