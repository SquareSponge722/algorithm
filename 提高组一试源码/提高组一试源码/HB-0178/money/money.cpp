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
#define REP(u) for(re int i(head[u]),v;v=edge[i].to,i;i=edge[i].nex)

#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,1<<17,in),pa==pb)?EOF:*pa++
//#define gc getchar()

using namespace std;
typedef long long ll;

char buf[1<<17],*pa(buf),*pb(buf);

FILE *in=fopen("money.in","r");
ofstream fout("money.out");

il int read() {
	re int s(0);re char c(gc);
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') s=10*s+(c^48),c=gc;
	return s;
}

const int N=110;
int T,n,d,p,ans;
int x,y;
int a[N];
int b[N];
int vis[25100];

il vd dfs(int now) {
	if(now>d) return;
	vis[now]=1;
	dfs(now+x);
	dfs(now+y);
}

vd Main() {
	T=read();
	while(T--) {
		FOR(i,1,d) *(vis+i)=0;
		n=read();
		FOR(i,1,n) *(a+i)=read();
		sort(a+1,a+n+1);
		b[ans=1]=a[1];
		for(p=2;p<=n;++p) {
			if(a[p]%b[1]) {
				b[++ans]=a[p];
				d=b[1]*b[2]-b[1]-b[2];
				x=b[1],y=b[2];
				dfs(0);
				break;
			}
		}
		FOR(i,p+1,n) {
			if(a[i]>d) break;
			if(!vis[a[i]]) {
				b[++ans]=y=a[i];
				FOR(j,1,d) {
					if(!vis[j]) continue;
					x=j;
					dfs(0);
				}
			}
		}
		fout<<ans<<'\n';
	}
}
int main()
{
	Main();
	return 0;
}
