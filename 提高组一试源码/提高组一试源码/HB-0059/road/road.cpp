#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define ll long long
using namespace std;
int a[100005];
ll ans=0;
inline int read(){
	int k=1,x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if (ch=='-') k^=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return k?x:-x;
}
void solve(int l,int r){
	if (l==r) {
		ans+=a[l];
		return;
	}
	int mind=0x3f3f3f3f,fen;
	FOR(i,l,r) if (a[i]<mind) mind=a[i],fen=i;
	ans+=a[fen];int k=a[fen];
	FOR(i,l,r) a[i]-=k;
	if (fen-1>=l) solve(l,fen-1);else ans+=a[l];
	if (fen+1<=r) solve(fen+1,r);else ans+=a[r];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	FOR(i,1,n) a[i]=read();
	solve(1,n);
	cout<<ans;
	return 0;
}
