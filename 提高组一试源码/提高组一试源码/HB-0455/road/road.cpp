#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
int n,a[100010];
ll ans;
inline void ha(int l,int r){
	if(l>r) return;
	if(l==r){
		if(a[l]==0) return;
		ans+=a[l];
		return;
	}
	int maxn=9999999,p=0;
	for(int i=l;i<=r;i++)
		if(a[i]<maxn){
			maxn=a[i];
			p=i;
		}
	ans+=maxn;
	for(int i=l;i<=r;i++)
		a[i]-=maxn;
	ha(l,p-1);
	ha(p+1,r);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ha(1,n);
	cout<<ans;
	return 0;
}
