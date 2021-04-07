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

FILE *in=fopen("travel.in","r");
ofstream fout("travel.out");

il int read() {
	re int s(0);re char c(gc);
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') s=10*s+(c^48),c=gc;
	return s;
}

const int N=5e3+7;
int n,m;
int u,v;
int cnt,head[N];
int cg[N],vis[N];
int cp[N],ans[N];

struct Edge {
	int to,nex;
} edge[N<<1];

il vd add(int u,int v) {
	edge[++cnt]=(Edge) {v,head[u]},head[u]=cnt;
}

namespace task1{
	
	il int cmp(int x,int y) {
		return x>y;
	}
	
	vd pre(int u,int fa) {
		REP(u) {
			if(v==fa) continue;
			cg[++cnt]=v;
		}
		sort(cg+1,cg+cnt+1,cmp);
		REP(u) {
			if(v==fa) continue;
			edge[i].to=cg[cnt--];
		}
		REP(u) {
			if(v==fa) continue;
			pre(v,u);
		}
	}
	
	vd dfs(int u,int fa) {
		ans[++cnt]=u;
		REP(u) {
			if(v==fa) continue;
			dfs(v,u);
		}
	}
	
	il vd solve() {
		cnt=0;
		pre(1,0);
		dfs(1,0);
		FOR(i,1,n) fout<<ans[i]<<' ';
	}
	
}

namespace task2{
	
	int flag,pd,now;
	
	il int cmp(int x,int y) {
		return x>y;
	}
	
	vd pre(int u) {
		vis[u]=1;
		REP(u) cg[++cnt]=v;
		sort(cg+1,cg+cnt+1,cmp);
		REP(u) edge[i].to=cg[cnt--];
		REP(u) {
			if(vis[v]) continue;
			pre(v);
		}
	}
	
	vd dfs(int u) {
		vis[cp[++cnt]=u]=1;
		if(u<ans[cnt]) pd=1;
		if(!pd&&u>ans[cnt]) {flag=1;return;}
		REP(u) {
			if(vis[v]||i==now) continue;
			dfs(v);
			if(flag) return;
		}
	}
	
	il vd solve() {
		cnt=0;
		pre(1);
		FOR(i,1,n) ans[i]=5989;
		for(now=1;now<=m;++now) {
			pd=cnt=flag=0;
			FOR(i,1,n) vis[i]=0;
			dfs(1);
			if(!flag&&cnt==n) FOR(i,1,n) ans[i]=cp[i];
		}
		FOR(i,1,n) fout<<ans[i]<<' ';
	}
	
}

vd Main() {
	n=read(),m=read();
	FOR(i,1,m) u=read(),v=read(),add(u,v),add(v,u);
	if(m==n-1) task1::solve();
	else task2::solve();
}
int main()
{
	Main();
	return 0;
}/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6


*/
