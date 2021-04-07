#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define vd void
#define il inline
#define re register

#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define ROF(i,a,b) for(re int i(a);i>=(b);--i)
#define REP(u) for(re int i(head[u]),v;v=edge[i].to,i;i=edge[i].nex)

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,1<<17,in),pa==pb)?EOF:*pa++
//#define gc getchar()

using namespace std;
typedef long long ll;

char buf[1<<17],*pa(buf),*pb(buf);

FILE *in=fopen("defense.in","r");
ofstream fout("defense.out");

il int read() {
	re int s(0);
	re char c(gc);
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') s=10*s+(c^48),c=gc;
	return s;
}

il int rcha() {
	re char c(gc);
	while(c<'A'||c>'Z') c=gc;
	return c;
}

const int N=1e5+7;
const ll INF=1059142299591422;
int n,m,ty;
int u,v;
int p[N];
int cnt,head[N];
int a,b,x,y;
char ch;
ll f[N][2];

struct Edge {
	int to,nex;
} edge[N<<1];

il vd add(int u,int v) {
	edge[++cnt]=(Edge) {v,head[u]},head[u]=cnt;
}

vd dfs(int u,int fa) {
	ll sumin(0),suma(0);
	REP(u) {
		if(v==fa) continue;
		dfs(v,u);
		suma+=f[v][1];
		sumin+=min(f[v][0],f[v][1]);
	}
	f[u][0]=suma;
	f[u][1]=sumin+p[u];
	if(u==a) {
		if(x) f[u][0]=INF;
		else f[u][1]=INF;
	}
	if(u==b) {
		if(y) f[u][0]=INF;
		else f[u][1]=INF;
	}
}

vd Main() {
	n=read(),m=read(),ch=rcha(),ty=read();
	FOR(i,1,n) p[i]=read();
	FOR(i,2,n) u=read(),v=read(),add(u,v),add(v,u);
	ll ans;
	while(m--) {
		a=read(),x=read(),b=read(),y=read();
		dfs(1,0);
		ans=min(f[1][0],f[1][1]);
		if(ans<INF) fout<<ans<<'\n';
		else fout<<-1<<'\n';
	}
}
int main() {
	Main();
	return 0;
}/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0

*/
