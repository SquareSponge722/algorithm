#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,tot,ans,head[50005],dis[50005],vis[50005];
struct edge {
	int v,w,next;
} edge[100005];
inline void add(int u,int v,int w) {
	edge[++tot].v=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot;
}
inline void dfs(int u) {
	if(vis[u])return;
	vis[u]=1;
	for(int i=head[u]; i; i=edge[i].next) {
		int v=edge[i].v,w=edge[i].w;
		if(!vis[v]) {
			dis[v]=dis[u]+w;
			dfs(v);
		}
	}
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1; i<n; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	int l=1;
	dfs(l);
	for(register int i=1; i<=n; i++) {
		if(dis[i]>dis[l])l=i;
	}
	//cout<<l;
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dfs(l);
	for(register int i=1; i<=n; i++) {
		ans=max(ans,dis[i]);
	}
	printf("%d\n",ans);
	return 0;
}
