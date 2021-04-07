#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++)
		while(a[i]>0) {
			ans++;
			a[i]--;
			for(int j=i+1; j<=n; j++)
				if(a[j])a[j]--;
				else break;
		}
	cout<<ans;
	return 0;
}
