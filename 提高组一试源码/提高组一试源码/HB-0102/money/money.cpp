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
int n;
int a[110];

void p2() {
	int x,y;
	x=read();
	y=read();
	if((x%y==0)||(y%x==0)) cout<<1<<endl;
	else cout<<2<<endl;
}

#define bi(x,y) if((x%y==0)||(y%x==0))
#define bi2(x,y,z) if(z>(x*y-x-y))
void p3() {
	int x=read(),y=read(),z=read();
	if(x>y) swap(x,y);
	if(x>z) swap(x,z);
	if(y>z) swap(y,z);
	bool b1=0,b2=0,b3=0;
	bi(x,y) b1=1;
	bi(y,z) b2=1;
	bi(x,z) b3=1;
	if(b1&&b2&&b3) {
		cout<<1<<endl;
		return;
	}
	if((b1&&b2)||(b1&&b3)||(b2&&b3)) {
		cout<<2<<endl;
		return;
	}
	bi2(x,y,z) {
		cout<<2<<endl;
		return;
	}
	for(int i=1; i*y<=z; i++) {
		if((z-i*y)%x==0) {
			cout<<2<<endl;
			return;
		}
	}
	cout<<3<<endl;
}

const int N=110000;
const int INF=(1<<28);
int b[N],_max,c[N];
void bao() {
	FOR(i,1,100000) b[i]=0;
	FOR(i,1,n) {
		a[i]=read();
	}
	sort(a+1,a+1+n);
//	FOR(i,1,n) cout<<a[i]<<" ";
//	cout<<endl<<endl;
	int x1=1,x2=2;
	while((a[x1]==a[x2])||(a[x2]%a[x1]==0)) x2++;
	_max=a[x1]*a[x2]-a[x1]-a[x2];
//	cout<<_max<<"   ";
	FOR(i,x2+1,n) if(a[i]>_max) {
		n=i-1;
//		cout<<a[i]<<" ";
		break;
	}
//	cout<<n<<" ";
	FOR(i,1,100000) c[i]=0;
	int l=INF,r=0;
	FOR(i,1,n) {
		b[a[i]]=1;
		c[a[i]]=1;
		r=max(r,a[i]);
		l=min(l,a[i]);
	}
	int ans=n;
	FOR(x,l,r) FOR(y,l,r) {
		if(c[x]&&c[y]) {
			for(int i=1; i*x<=_max; i++)
				for(int j=1; i*x+j*y<=_max; j++) {
					c[i*x+j*y]=1;
					if(b[i*x+j*y]) --ans,b[i*x+j*y]=0;
				}
		}
	}
	cout<<ans<<endl;
}

void work() {
	n=read();
	if(n==2) {
		p2();
		return;
	}
	if(n==3) {
		p3();
		return;
	} else {
		bao();
		return;
	}
}

int main() {
	OPEN("money")
	int t;
	t=read();
	while(t--) work();
	return 0;
}
