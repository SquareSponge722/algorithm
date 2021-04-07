#include<iostream>
#include<cstdio>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=hd[u],v;v=e[i].v,i;i=e[i].n)
using namespace std;
typedef long long ll;
const int N=100100,M=200200;
const ll INF=1e10;
struct edge{int n,v;}e[M];
int n,T,fl,a,x,b,y,u,v,hd[N],fa[N];
ll p[N],ans,f[N][3];
char tip[10];
void add(int u,int v){e[++fl]=(edge){hd[u],v};hd[u]=fl;}
void dfs1(int u){
	REP(u)if(v!=fa[u]) fa[v]=u,dfs1(v);
}
void dfs2(int u){
	f[u][1]=p[u];
	f[u][0]=0;
	REP(u)if(v!=fa[u]){
		dfs2(v);
		if(f[u][0]<INF) f[u][0]+=f[v][1];
		if(f[u][1]<INF) f[u][1]+=min(f[v][0],f[v][1]);
	}
	if(u==a && x==1 || u==b && y==1) f[u][0]=INF;
	if(u==a && x==0 || u==b && y==0) f[u][1]=INF;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&T);
	scanf("%s",tip+1);
	FOR(i,1,n) scanf("%d",&p[i]);
	FOR(i,2,n) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs1(1);
	while(T--){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		FOR(i,1,n)FOR(j,0,1) f[i][j]=INF;
		dfs2(1);
		ans=min(f[1][1],f[1][0]);
		cout<<(ans>=INF?-1:ans)<<'\n';
	}
}/*

*/
