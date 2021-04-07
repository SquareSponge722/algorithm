#include <algorithm>
#include <iostream>
#include <cstdio>
#define OPEN(n) freopen(n".in","r",stdin); freopen(n".out","w",stdout);
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define FR(i,n,m) for(int i=n;i>=m;--i)
#define re register
#define ll long long
using namespace std;
inline int read() {
	re int x=0,f=1;
	re char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	};
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=100100;
const ll INF=(1<<29);
int n,m;
//-------------------------------------------------------------------------
struct node {
	int next,to,val;
} e[N];
int h[N],cnt;
inline void add(int u,int v,int w) {
//	if(==4) cout<<"L_L";
	e[++cnt].to=v;
	e[cnt].next=h[u];
	e[cnt].val=w;
	h[u]=cnt;
}
#define QXX(u) for(int i=h[u],v,w;v=e[i].to,w=e[i].val,i;i=e[i].next)
int f[N];
void dfs(int now,int fa,int len) {
	f[now]=len;
	QXX(now) if(v!=fa) dfs(v,now,w+len);
}
void zhijing() { //1,4,5,6Ê÷µÄÖ±¾¶
	FOR(i,1,n-1) {
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0,0);
	int _max=-INF,k;
	FOR(i,1,n) {
		if(f[i]>_max) k=i,_max=f[i];
	}
	dfs(k,0,0);
	_max=0;
	FOR(i,1,n) {
		if(f[i]>_max) _max=f[i];
	}
	cout<<_max<<endl;
}
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
int a[N],b[N];
struct road {
	int a,b,w;
} r[N];

void lian() { //b=a+1
	int l=0,rr=0,mid;
	FOR(i,1,n) rr+=r[i].w;
	while(l<rr) {
		bool flag=0;
		mid=(l+rr)>>1;
		int k=0,w,_min=INF;
		FOR(i,1,n) {
			if(k+a[i]<mid) k+=a[i];
			else {
				w++;
				_min=min(_min,k);
				k=0;
				if(a[i]<=mid) k=a[i];
			}
			if(w==m) {
				flag=1;
			}
		}
		if(flag) rr=mid-1;
		else l=mid+1;
	}
	cout<<mid;
}

bool cmp(road x,road y) {
	return x.w>y.w;
}
void fang() { //a=1,·ÅÉä×´
	sort(r+1,r+n,cmp);
	int ans=INF;
	int _r,rr;
	if((m<<1)>=n)
		_r=n>>1,rr=n;
	else _r=m<<1,rr=m;
	FOR(i,1,_r) ans=min(a[i]+a[rr-i],ans);
	cout<<endl;
}


void work() {
	FOR(i,1,n) r[i].a=read(),r[i].b=read(),r[i].w;
	if((r[1].a==1)&&(r[2].a==1)&&(r[3].a==1)) fang();
	else if((r[1].a==r[1].b-1)&&(r[2].a==r[2].b-1)&&(r[3].a==r[3].b-1)) lian();
//	else bao();
}
//-------------------------------------------------------------------------

int main() {
	OPEN("track")
	n=read(),m=read();
	if(m==1) {
		zhijing();
		return 0;
	} else {
		work();
		return 0;
	}
	return 0;
}
