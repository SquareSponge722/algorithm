#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int n,m,en,head[N];
bool vis[N]={0};//1:
int dep=0,aim=1,dist[N]={0};//1:
struct Edge{
	int to,nxt,wei;
}edge[N<<1];

void addedge(int u,int v,int w){
	edge[++en].to=v,edge[en].nxt=head[u],edge[en].wei=w,head[u]=en;
}

void dfs(int o){
	vis[o]=1;
	for(int i=head[o],v,w;i;i=edge[i].nxt){
		v=edge[i].to,w=edge[i].wei;
		if(vis[v]) continue;
		dist[v]=dist[o]+w;
		if(dist[v]>dep) dep=dist[v],aim=v;
		dfs(v);
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		for(int i=1,a,b,l;i<n;i++){
			scanf("%d%d%d",&a,&b,&l);
			addedge(a,b,l);
			addedge(b,a,l);
		}
		dist[1]=0;
		dfs(1);
		memset(vis,0,sizeof vis);
		memset(dist,0,sizeof dist);
		dfs(aim);
		printf("%d\n",dep);
	}//树中最长路
	
	
	return 0;
}
