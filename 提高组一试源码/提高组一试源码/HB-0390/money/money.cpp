#include<bits/stdc++.h>
using namespace std;
int n,dp[1005],a[105],num,havefind,ans[105],m,t,maxn,anss;
int getnum(int i) {
	int num=0;
	while(i) {
		if(i&1)num++;
		i>>=1;
	}
	return num;
}
void work(int i) {
	if(getnum(i)<1)return;
	int num=0;
	memset(ans,0,sizeof(ans));
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int j=0; j<=n-1; j++) {
		if((i>>j)&1)ans[++num]=a[j+1];
	}
	for(int j=1; j<=maxn; j++) {
		for(int k=1; k<=num; k++) {
			if(j-ans[k]>=0)
				if(dp[j-ans[k]]) {
					dp[j]=1;
					break;
				}
		}
	}
	int f=1;
	for(int j=1; j<=n; j++)
		if(!dp[a[j]])f=0;
	if(f==1) {
		anss=min(anss,getnum(i));
		return;
	}
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(a,0,sizeof(a));
		havefind=0;
		cin>>n;
		anss=n;
		if(n==2) {
			cout<<2;
			return 0;
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		for(int i=0; i<=(1<<n)-1; i++) {
			work(i);
		}
		cout<<anss<<endl;
	}
	return 0;
}
/*
1
7
11 13 5 12 14 10 15
*/
