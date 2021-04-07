#include<bits/stdc++.h>
using namespace std;
int t,n,a[105];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	for(int s=1; s<=t; s++) {
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(a[2]%a[1]==0)cout<<1<<endl;
		else cout<<n<<endl;
	}
	return 0;
}
