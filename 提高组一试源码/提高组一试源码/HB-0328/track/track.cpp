#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int u1,u2,zj,n,m,nson[50004],e,head[50004],anc[50004][17],dis[50004][17],deep[50004],d;
bool vis[50004];
    struct node {
	int v,next,w;
} a[100004];
void insert(int u,int v,int w) {
	a[++e].v=v;
	a[e].next=head[u];
	head[u]=e;
	a[e].w=w;
}
void dfs(int u) {
	for(int i=1; i<=16; i++) {
		anc[u][i]=anc[anc[u][i-1]][i-1];
		dis[u][i]=dis[anc[u][i-1]][i-1]+dis[u][i-1];;
	}
//	cout<<u<<"u"<<endl;
	for(int p=head[u]; p; p=a[p].next) {
		int v=a[p].v;
//		cout<<v<<"v ";
		if(deep[v])continue;
		nson[u]++;
//		cout<<nson[u]<<endl;
		deep[v]=deep[u]+1;
		anc[v][0]=v;
		dis[v][0]=a[p].w;
		dfs(v);
	}
}
void swim(int u,int &v) {
	for(int i=16; i>=0; i--) {
		if(deep[anc[v][i]]>deep[u])d+=dis[v][i],v=anc[v][i];
	}
	if(deep[u]<deep[v])d+=dis[v][0],v=anc[v][0];
}
int lca(int u,int v) {
	d=0;
	if(deep[u]>deep[v])swap(u,v);
	if(deep[u]!=deep[v])swim(u,v);
	for(int i=16; i>=0; i--) {
		if(anc[u][i]) {
			d+=dis[u][i]+dis[v][i];
			u=anc[u][i],v=anc[v][i];
		}
	}
	if(u!=v)d+=dis[u][0]+dis[v][0],u=anc[u][0],v=anc[v][0];
	return d;
}
int dfszj(int u0,int u,int dep) {
	if(!nson[u]&&u!=u0) {
		zj=max(zj,dep);
		if(zj<dep)zj=dep,u2=u;
	}
	for(int p=head[u]; p; p=a[p].next) {
		int v=a[p].v;
		if(vis[v])continue;
		vis[v]=1;
		dfszj(u0,v,dep+a[p].w);
	}
}
/*void bs(int l,int r){
	while(l<r){
		int mid=(l+r)/2;
		if(){
			
		}
	}
}*/
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	bool uv=1;
	for(int i=1; i<=n-1; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
//		nson[u]++;
		if(v!=u+1)uv=0;
		insert(u,v,w);
		insert(v,u,w);
	}
	dfs(1);
/*	if(uv) {
		
	}*/
//	for(int i=1;i<=n;i++)cout<<nson[i]<<"i "<<endl;
	if(m==1) {
		for(int i=1; i<=n; i++)if(!nson[i]) {
				dfszj(i,i,0);
				break;
			}
		for(int i=1;i<=n;i++)vis[i]=0;
		dfszj(u2,u2,0);
		cout<<zj<<endl;
		return 0;
	}
	if(m==2&&uv){
		int anss=inf;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			anss=min(anss,lca(1,i)+lca(j,n));
		}
		cout<<anss<<endl;
	}
	
}


