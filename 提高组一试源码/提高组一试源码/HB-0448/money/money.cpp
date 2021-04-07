#include <bits/stdc++.h>
using namespace std;
int t,n,a[110],sum;
bool ok;
void dfs(int x,int now) {
	if(now<0)return;
	if(ok)return;
	for(int i=x-1; i>=1; i--) {
		if(a[i]==999999)continue;
		if(now%a[i]==0)ok=1;
		dfs(x,now-a[i]);
	}
	return;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++) {
			if(a[i]==999999)continue;
			for(int j=i+1; j<=n; j++) {
				if(a[j]==999999)continue;
				if(a[i]==__gcd(a[i],a[j]))a[j]=999999;
			}
		}
		int tot=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==999999)continue;
			if(++tot>=3){
				ok=0;
				dfs(i,a[i]);
				if(ok)a[i]=999999;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=999999)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
