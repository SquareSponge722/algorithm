#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> E[5010];
int n,m,vis[5010],road[5010],nodesum,come[5010];
void dfs(int now,int last){
	if(!vis[now]){vis[now]=1; road[++nodesum]=now;}
	if(nodesum==n){
		for(int i=1;i<=n;i++) printf("%d ",road[i]);
		exit(0);
	}
	for(int i=0;i<E[now].size();i++) if(E[now][i]!=last) dfs(E[now][i],now);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(int i=1;i<=n;i++) sort(E[i].begin(),E[i].end());
	dfs(1,0);
}
