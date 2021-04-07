#include <algorithm>
#include <iostream>
#include <cstdio>
#define OPEN(n) freopen(n".in","r",stdin); freopen(n".out","w",stdout);
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define FR(i,n,m) for(int i=n;i>=m;--i)
#define re register
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
#define ll long long
const int INF=(1<<28),N=100100;
int a[N],n;
ll ans=0;

void tian(int r,int l) {
	if(r>l) return;
	if(r==l) {
		ans+=a[r];
		return;
	}
	int _min=INF;
	FOR(i,r,l) {
		if(a[i]<_min) _min=a[i];
	}
	ans+=_min;
	int k=r;
	FOR(i,r,l) {
		a[i]-=_min;
		if(a[i]==0) {
			tian(k,i-1),k=i+1;
		}
	}
	if(k<=l)	tian(k,l);
}

int main() {
	OPEN("road")
	n=read();
	FOR(i,1,n) a[i]=read();
	tian(1,n);
	cout<<ans<<endl;
	return 0;
}
