#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define OPEN(n) freopen(n".in","r",stdin);freopen(n".out","w",stdout);
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define FR(i,n,m) for(int i=n;i>=m;--i)
const int N=5010;
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
int n,m;
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

int a[N],c[N];
int tt=0;
void dfs(int now,int fa) {
	a[++tt]=now;
	int b[N];
	int tot=0;
	QXX(now) {
		if(v!=fa&&!c[v]) {
			b[++tot]=v;
		}
	}
	sort(b+1,b+tot+1);
	FOR(i,1,tot) {
		c[b[i]]=1,dfs(b[i],now);
	}
}
void shu() {
	a[1]=1;
	c[1]=1;
	dfs(1,0);
	FOR(i,1,tt) cout<<a[i]<<" ";
	cout<<endl;
}

int du[N];
void dfs1(int now,int fa) {
	if(du[now]==2) {
		c[now]=1;
		return;
	}
	du[now]++;
	QXX(now) {
		if(v!=fa&&!c[v]) {
			dfs1(v,now);
		}
	}
}


void dffs() {
	int m1,m2,t=0;
	QXX(1) {
//		cout<<v<<" ";
		if(++t==1)m1=v;
		else m2=v;
	}
//	cout<<m1<<" "<<m2<<" ";
	a[++tt]=1;
	int last2=1,last1=1;
	while(c[m1]&&c[m2]) {
		if(m1<m2) {
			a[++tt]=m1;
			QXX(m1) if(v!=last1) {
				last1=m1;
				m1=v;
			}
		}
		if(m1>m2) {
			a[++tt]=m2;
			QXX(m1) if(v!=last1) {
				last1=m2;
				m2=v;
			}
		}
	}
	if(!c[m1]) {
		while(m2<=m1) {
			a[++tt]=m2;
			QXX(m1) if(v!=last2) {
				last2=m2;
				m2=v;
			}
		}
		c[m1]=1;
		dfs(m1,last1);
		dfs(m2,last2);
	}
	if(!c[m1]) {
		while(m2>m1) {
			a[++tt]=m1;
			QXX(m1) if(v!=last1) {
				last1=m1;
				m1=v;
			}
		}
		c[m2]=1;
		dfs(m2,last2);
		dfs(m1,last1);
	}
}

void huan() {
	du[1]=1;
	dfs1(1,0);
	if(c[1]) dffs();
	FOR(i,1,n) cout<<a[i]<<" ";
	cout<<endl;
}

int main() {
	OPEN("travel")
	n=read(),m=read();
	FOR(i,1,m) {
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	if(m==n-1) shu();
	else huan();
	return 0;
}
