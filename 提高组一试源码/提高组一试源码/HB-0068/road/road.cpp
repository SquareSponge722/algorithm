#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
int ans=0;
int minn,t;
bool ok;
void dg(int l,int r) {
	if(l>r) return;
	minn=20000;
	ok=true;
	for(int i=l; i<=r; i++)
		if(a[i]==0) {
			dg(l,i-1);
			dg(i+1,r);
		}
	for(int i=l; i<=r; i++)
		if(a[i]==0) {
			ok=false;
			return;
		}
	if(ok) {
		for(int i=l; i<=r; i++)
			if(a[i]<minn) {
				minn=a[i];
			}
		ans+=minn;
		for(int i=l; i<=r; i++) {
			a[i]-=minn;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	minn=20000;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	    if(minn>a[i]) minn=a[i];
	}
	ans+=minn;
	for(int i=1;i<=n;i++){
		a[i]-=minn;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0){
			dg(1,i-1);
			dg(i+1,n);
		}
	printf("%d",ans);
	return 0;
}





