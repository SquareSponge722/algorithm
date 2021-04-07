#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[110],ans;
bool cmp(int x, int y) {
	return x>y;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int K=1; K<=T; K++) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		sort(a+1, a+1+n, cmp);
		ans=0;
		for(int i=1; i<=n; i++) {
			int u=a[i];
			for(int j=i+1; j<=n; j++) {
				u=u%a[j];
				if(u==0) {
					ans++;
					break;
				}
			}
		}
		cout<<n-ans<<endl;
	}
}
