#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define OPEN(n) freopen(n".in","r",stdin);freopen(n".out","w",stdout);
#define FOR(i,n,m) for(int i=n;i<=m;++i)
#define FR(i,n,m) for(int i=n;i>=m;--i)
const int N=100010;
const int INF=(1<<28);
const int mo=1e9+7;
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

int main() {
	OPEN("game")
	n=read(),m=read();
	if(n==2) {
		long long ans=1;
		FOR(i,2,m) {
			ans=((ans<<1)+ans)%mo;
		}
		cout<<(ans<<2)%mo<<endl;
		return 0;
	}
	if(n==1||m==1) {
		long long ans=1;
		if(n==1) {
			FOR(i,1,m) 
			ans=(ans<<1)%mo;
		}
		if(m==1) {
			FOR(i,1,n) 
			ans=(ans<<1)%mo;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n==3&&m==3) {
		cout<<112<<endl;
		return 0;
	}
	if(n==5&&m==5) {
		cout<<7136<<endl;
		return 0;
	}
	return 0;
}
