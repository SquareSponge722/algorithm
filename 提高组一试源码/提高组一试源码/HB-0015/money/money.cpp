#include<bits/stdc++.h>
using namespace std;
int n,t,a[25010],b[250100],m,ans;
int mul(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
bool dfs(int x) {
	if(x==0)return 1;
	if(x<0)return 0;
	for(int i=m; i>=1; i--) {
		if(dfs(x-b[i]))return 1;
	}
	return 0;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		m=0;
		for(int i=1; i<=n; i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		ans=1;
		for(int i=0;a[1]*mul(2,i)<=a[n];i++)
			b[++m]=a[1]*mul(2,i);
		for(int i=2; i<=n; i++)
			if(!dfs(a[i])){
			ans++;
			for(int j=0;a[j]*mul(2,i)<=a[n];j++)
				b[++m]=a[i]*mul(2,j);
			}
		cout<<ans<<endl;
	}
	return 0;
}
