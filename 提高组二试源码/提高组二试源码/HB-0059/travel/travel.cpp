#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x,i) for(register int i=head[x];i;i=h[i].next)
using namespace std;
struct edge{
	int next,to;
}h[10005];
int n,m;
int head[5005],tot,deep[5005],fa[5005],no1,no2;
bool vis[5005],ff,ok[10005];
void add(int u,int v){
	h[++tot].to=v;
	h[tot].next=head[u];
	head[u]=tot;
}
void dfs(int u){
	if (!vis[u]) cout<<u<<" ";
	vis[u]=1;
	int minto=0x3f3f3f3f;
	TU(u,j){
		TU(u,i)
			if (!vis[h[i].to]&&!ok[i]) minto=min(minto,h[i].to);
		if (minto!=0x3f3f3f3f)dfs(minto),minto=0x3f3f3f3f;
		else break;
	} 
}
void dfs1(int u,int f){
	if (!deep[u]) {
		deep[u]=deep[f]+1;
		fa[u]=f;
	}
	else {
		ff=1;
		if (abs(u-fa[u])<abs(u-f)) no1=f,no2=u;
		else {
			no1=fa[u],no2=u;
			fa[u]=f;deep[u]=deep[f]+1;
		}
	}
	if (ff) return;
	TU(u,i){
		if (h[i].to!=f) dfs1(h[i].to,u);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	int u,v;
	FOR(i,1,m){
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	if (m==n-1){
		dfs(1);
		return 0;
	}
	if (m==n){
		memset(vis,0,sizeof(vis));
		dfs1(1,0);//cout<<no1<<" "<<no2;
		TU(no1,i) if (h[i].to==no2) ok[i]=1;
		TU(no2,i) if (h[i].to==no1) ok[i]=1;
		dfs(1);
		return 0;
	}
	return 0;
}

