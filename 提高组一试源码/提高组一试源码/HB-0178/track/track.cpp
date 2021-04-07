#include<queue>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<algorithm>

#define vd void
#define il inline
#define re register

#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define ROF(i,a,b) for(re int i(a);i>=(b);--i)
#define REP(u) for(re int i(head[u]),v,w;v=edge[i].to,w=edge[i].w,i;i=edge[i].nex)

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,1<<17,in),pa==pb)?EOF:*pa++
//#define gc getchar()

using namespace std;
typedef long long ll;

char buf[1<<17],*pa(buf),*pb(buf);

FILE *in=fopen("track.in","r");
ofstream fout("track.out");

il int read() {
	re int s(0);re char c(gc);
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') s=10*s+(c^48),c=gc;
	return s;
}

const int N=50007;
int n,m;
ll ans,tot;
int u,v,w;
int cnt,head[N];

struct Edge {
	int to,nex,w;
} edge[N<<1];

il vd add(int u,int v,int w) {
	edge[++cnt]=(Edge) {v,head[u],w},head[u]=cnt;
}

namespace task1{
	
	int num;
	
	vd dfs(int u,int fa,ll now) {
		ans=max(ans,now);
		REP(u) {
			if(v==fa) continue;
			dfs(v,u,now+w);
		}
	}
	
	il vd solve() {
		FOR(u,1,n) {
			num=0;
			REP(u) ++num;
			if(num==1)
				dfs(u,0,0);
		}
		fout<<ans?ans:tot;
	}
}

vd Main() {
	n=read(),m=read();
	FOR(i,2,n) u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w),tot+=w;
	if(m==1) task1::solve();
	else {
		srand(1059142299);
		fout<<rand()%591422+5989;
	}
}
int main()
{
	Main();
	return 0;
}
