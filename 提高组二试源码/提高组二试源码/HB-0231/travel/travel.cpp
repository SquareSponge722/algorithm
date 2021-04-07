#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;

vector<int> g[maxn];
int n,m;
int x,y,c;

queue<int> s;
bool vis[maxn];

void dfs(int u,int fa){
    s.push(u);
    vis[u]=true;
	for (int i=0;i<g[u].size();i++){
		if(g[u][i]==fa||vis[g[u][i]])continue;
		dfs(g[u][i],u);
	}
	
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		//cin>>x>>y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	}
	dfs(1,0);
	while(!s.empty()){
		cout<<s.front()<<" ";
		s.pop();
	}
	
	return 0;
}
