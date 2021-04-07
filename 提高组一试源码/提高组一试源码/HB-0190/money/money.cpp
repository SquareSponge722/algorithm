#include<iostream>
#include<cstdio>
#include<algorithm>
#define fro(i,a,b) for(int i=a;i<=b;++i)
#define fr(i,a) for(int i=1;i<=a;++i)
using namespace std;
const int maxn=200;
int t,n,tot,nan[maxn],ans[maxn];
bool cmp(int a,int b) { return a<b; }
void clear() {
	fr(i,n) nan[i]=0; fr(i,tot) ans[i]=0;
	n=0;tot=0;
	return;
}
bool check(int a,int b) {
	if(b>tot) return a==0;
	if(a==0) return 1;
	if(a<0) return 0;
	fro(i,0,a/ans[b]) {
		a-=ans[b]*i;
		if(check(a,b+1)) return 1;
		a+=ans[b]*i;
	}	return 0;
}
void work() {
	clear();
	cin>>n; fr(i,n) cin>>nan[i];
	sort(nan+1,nan+1+n,cmp);
	fr(i,n) {
		fr(j,tot) if(nan[i]%ans[j]==0) continue;
		if(check(nan[i],1)) continue;
		tot++;ans[tot]=nan[i];
	}	cout<<tot<<endl;
	return;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;	while(t--) work();
	return 0;
}
