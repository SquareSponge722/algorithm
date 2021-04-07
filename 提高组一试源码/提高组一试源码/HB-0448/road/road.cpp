#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
void work(int l,int r,int x) {
	if(l==r) {
		ans+=a[l]-x;
		return;
	}
	int minn=10010,o=1;
	for(int i=l; i<=r; i++) {
		if(a[i]<minn)minn=a[i],o=i;
	}
	if(minn!=10010)ans+=minn-x;
	if(o>l)work(l,o-1,minn);
	if(o<r)work(o+1,r,minn);
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	work(1,n,0);
	cout<<ans;
	return 0;
}
