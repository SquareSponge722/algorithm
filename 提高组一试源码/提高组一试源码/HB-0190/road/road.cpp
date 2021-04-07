#include<iostream>
#include<cstdio>
#define fro(i,a,b) for(int i=a;i<=b;++i)
#define fr(i,a) for(int i=1;i<=a;++i)
using namespace std;
const int maxn=100100;
int n,nan[maxn];
int mn(int a,int b) {
	return a<b?a:b;
}
int solve(int l,int r) {
	if(l==r) return nan[l];
	if(l>r) return 0;
	int sum=0,ans=2147483647,ll=l,rr=r;
	fro(i,l,r) ans=mn(ans,nan[i]);
	sum=ans;
	fro(i,l,r) {
		nan[i]-=ans;
		if(nan[i]==0) {
			rr=i-1;
			sum+=solve(ll,rr);
			ll=i+1,rr=r;
		}
	}
	sum+=solve(ll,rr);
	return sum;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n; fr(i,n) cin>>nan[i];
	cout<<solve(1,n);
	return 0;
}
