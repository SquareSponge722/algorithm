#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,e[50005],d[50005],dist[50005],f[50005][21],dep[50005],vis[50005],sum,b[50005];
struct node {
	int to;
	int v;
	node(int x,int y) {
		to=x;
		v=y;
	}
};
vector<node>v[50005];
void dfs(int x) {
	for(int i=1; i<=17; i++) {
		f[x][i]=f[f[x][i-1]][i-1];
	}
	vis[x]=true;
	for(int i=0; i<v[x].size(); i++) {
		int y=v[x][i].to;
		int z=v[x][i].v;
		if(vis[y]) continue;
		f[y][0]=x;
		dep[y]=dep[x]+1;
		dist[y]=dist[x]+z;
		dfs(y);
	}
}
int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=17; i>=0; i--) {
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	}
	if(x==y) return x;
	for(int i=17; i>=0; i--) {
		if(f[x][i]!=f[y][i]) {
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main() 
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1; i<=n-1; i++) {
		scanf("%d %d %d",&x,&y,&z);
		sum+=z;
		if(y==x+1) cnt++;
		v[x].push_back(node(y,z));
		v[y].push_back(node(x,z));
	}
	if(v[1].size()==n-1) {
		int tot=0;
		for(int i=0; i<v[1].size(); i++) {
			e[++tot]=v[1][i].v;
		}
		sort(e+1,e+tot+1);
		cout<<e[tot-m+1]<<endl;
		return 0;
	}
	if(m==1) {
		int maxn=0;
		dfs(1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				maxn=max(maxn,dist[i]+dist[j]-dist[lca(i,j)]);
			}
		cout<<maxn<<endl;
		return 0;
	}
	return 0;
}
