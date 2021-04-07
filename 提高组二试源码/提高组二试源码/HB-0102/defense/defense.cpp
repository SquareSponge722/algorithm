#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define OPEN(n) freopen(n".in","r",stdin);freopen(n".out","w",stdout);
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define FR(i,n,m) for(int i=n;i>=m;--i)
const int N=100010;
const int INF=(1<<28);
#define re register
#define gc getchar()
inline int read() {
	re int x=0,f=1;
	re char c=gc;
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=gc;
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=gc;
	}
	return x*f;
}
struct node {
	int next;
	int to;
} e[N<<1];
int h[N<<1],cnt;
inline void add(int u,int v) {
	e[++cnt]=(node) {
		h[u],v
	};
	h[u]=cnt;
}
#define QXX(u) for(int i=h[u],v;v=e[i].to,i;i=e[i].next)
int aa[N][5];
int n,m,ans,ai[N],p[N],_min=INF,f[N][5];
inline int minn(int a,int b,int c) {
	a=(a<b?a:b);
	return a<c?a:c;
}
void sou() {
	if(ai[1]==0) {
		f[1][1]=p[1];
		f[1][2]=INF;
		f[1][3]=INF;
	}
	if(ai[1]==-1) {
		f[1][1]=p[2];
		f[1][2]=0;
		f[1][3]=0;
	}
	if(ai[1]==1) {
		f[1][1]=p[1];
		f[1][2]=INF;
		f[1][3]=INF;
	}
	FOR(i,2,n) {
		if(ai[i]==0) {
			f[i][1]=minn(f[i-1][2],f[i-2][1],f[i-1][3])+p[i];
			f[i][2]=f[i-1][1];
			f[i][3]=f[i-1][2];
		}
		if(ai[i]==1&&!ai[i-1]) {
//			cout<<f[i-1][2]<<"---"<<f[i-2][2]<<"---"<<f[i-1][3]<<"   ";
			f[i][1]=minn(f[i-1][2],f[i-2][2],f[i-1][3])+p[i];
//			cout<<f[i][1]<<" ";
			f[i][2]=INF;
			f[i][3]=INF;
		}
		if(ai[i]==1&&ai[i-1]) {
			f[i][1]=f[i-1][1]+p[i];
//			cout<<f[i][1]<<" ";
			f[i][2]=INF;
			f[i][3]=INF;
		}
		if(ai[i]==-1) {
			f[i][1]=INF;
			f[i][2]=f[i-1][1];
			f[i][3]=f[i-1][2];
		}
	}
}

void p1() {
	f[0][3]=INF;
//	FOR(i,1,n) cout<<p[i]<<" ";
	if(n<=2000) {
		FOR(i,1,m) {
			int a=read();
			int x=read();
			int b=read();
			int y=read();
			if(a>b) swap(a,b),swap(x,y);
			if(b==a+1) {
				if(x==0&&y==0) {
					cout<<-1<<endl;
					continue;
				} else {
					_min=INF;
					FOR(j,1,n) ai[j]=0;
					if(x==1) ai[a]=1;
					else ai[a]=-1;
					if(y==1) ai[b]=1;
					else ai[b]=-1;
					ai[0]=1;
//				FOR(i,1,n) cout<<ai[i]<<" ";
					sou();
					cout<<min(f[n][1],f[n][2])<<endl;
				}
			} else {
				_min=INF;
				FOR(j,1,n) ai[j]=0;
				if(x==1) ai[a]=1;
				else ai[a]=-1;
				if(y==1) ai[b]=1;
				else ai[b]=-1;
				ai[0]=1;
//			FOR(i,1,n) cout<<ai[i]<<" ";
				sou();
				cout<<min(f[n][1],f[n][2])<<endl;
			}
		}
	}
}


void p2() {
	ai[1]=1;
	sou();
	FOR(i,0,n) FOR(j,1,3) aa[i][j]=f[i][j];
	FOR(i,1,m) {
		int a=read();
		int x=read();
		int b=read();
		int y=read();
		if(a>b) swap(a,b),swap(x,y);
		if(b==a+1) {
			if(x==0&&y==0) {
				cout<<-1<<endl;
				continue;
			} else {
				FOR(j,1,n) ai[j]=0;
				if(x==1) ai[a]=1;
				else ai[a]=-1;
				if(y==1) ai[b]=1;
				else ai[b]=-1;
				ai[0]=1;
				FOR(i,a-1,n) {
					if(ai[i]==0) {
						aa[i][1]=minn(aa[i-1][2],aa[i-2][1],aa[i-1][3])+p[i];
						aa[i][2]=aa[i-1][1];
						aa[i][3]=aa[i-1][2];
					}
					if(ai[i]==1&&!ai[i-1]) {
						aa[i][1]=minn(aa[i-1][2],aa[i-2][2],aa[i-1][3])+p[i];
						aa[i][2]=INF;
						aa[i][3]=INF;
					}
					if(ai[i]==1&&ai[i-1]) {
						aa[i][1]=aa[i-1][1]+p[i];
						aa[i][2]=INF;
						aa[i][3]=INF;
					}
					if(ai[i]==-1) {
						aa[i][1]=INF;
						aa[i][2]=aa[i-1][1];
						aa[i][3]=aa[i-1][2];
					}
				}
				cout<<min(aa[n][1],aa[n][2])<<endl;
			}
		}
	}

}

void p3() {
	FOR(i,1,m) {
		int a=read();
		int x=read();
		int b=read();
		int y=read();
		if(y==1) ai[b]=1;
		else ai[b]=-1;
		ai[0]=1;
		FOR(i,b-1,n) {
			if(ai[i]==0) {
				f[i][1]=minn(f[i-1][2],f[i-2][1],f[i-1][3])+p[i];
				f[i][2]=f[i-1][1];
				f[i][3]=f[i-1][2];
			}
			if(ai[i]==1&&!ai[i-1]) {
				f[i][1]=minn(f[i-1][2],f[i-2][2],f[i-1][3])+p[i];
//			cout<<f[i][1]<<" ";
				f[i][2]=INF;
				f[i][3]=INF;
			}
			if(ai[i]==1&&ai[i-1]) {
				f[i][1]=f[i-1][1]+p[i];
//			cout<<f[i][1]<<" ";
				f[i][2]=INF;
				f[i][3]=INF;
			}
			if(ai[i]==-1) {
				f[i][1]=INF;
				f[i][2]=f[i-1][1];
				f[i][3]=f[i-1][2];
			}
		}
	}
}
int main() {
	OPEN("defense")
	n=read(),m=read();
	string ss;
	cin>>ss;
	FOR(i,1,n) p[i]=read();
	FOR(i,1,n-1) {
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	if(ss[0]=='A') {
		if(n<=2000)	p1();
		else if(ss[1]=='1')p2();
		else p3();
		return 0;
	}
	return 0;
}
