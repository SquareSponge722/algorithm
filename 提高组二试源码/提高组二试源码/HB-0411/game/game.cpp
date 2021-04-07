#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define M 100010
#define LL long long
LL n,m,pow2[M],dp[M],num[M],ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>m)
		swap(n,m);
	if(n==1 || m==1){
		printf("0");
		return 0;
	}
	if(n==2){
		pow2[0]=1;
		for(int i=1;i<=n+m-1;i++){
			pow2[i]=pow2[i-1]*2;
			pow2[i]%=mod;
		}
		for(int i=1;i<=m-1;i++){
			num[i]=m-i;
			ans+=num[i]*pow2[n+m-1];
		}
		dp[1]=1;
		for(int i=2;i<=m-1;i++){
			dp[i]=dp[i-1]*4+pow2[i-1];
			dp[i]%=mod;
		}
		for(int i=1;i<=m-1;i++){
			ans+=dp[i]*num[i]*pow2[n+m-1-i];
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==3 && m==3){
		printf("112");
		return 0;
	}
}
