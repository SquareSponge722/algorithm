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

FILE *in=fopen("road.in","r");
ofstream fout("road.out");

il int read() {
	re int s(0);re char c(gc);
	while(c<'0'||c>'9') c=gc;
	while(c>='0'&&c<='9') s=10*s+(c^48),c=gc;
	return s;
}

const int N=100007;
int n;
ll ans;
int b[N];
struct node {
	int x;
	int num;
	bool operator < (const node & h) 
	const
	{
		if(x!=h.x) return x<h.x;
		return num<h.num;
	}
} a[N];

vd Main() {
	n=read();
	FOR(i,1,n) a[i].x=*(b+i)=read(),a[i].num=i;
	sort(a+1,a+n+1);
	re int d;
	FOR(i,1,n) {
		d=0;
		FOR(j,a[i].num+1,n) {
			if(b[j]<a[i].x) {
				d=b[j];
				break;
			}
			if(b[j]==a[i].x) ++i;
		}
		ROF(j,a[i].num-1,1) {
			if(b[j]<a[i].x) {
				d=max(d,b[j]);
				break;
			}
		}
		ans+=a[i].x-d;
	}
	fout<<ans;
}
int main()
{
	Main();
	return 0;
}
