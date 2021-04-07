#include<iostream>
#include<cstdio>
using namespace std;
const long long MOD = 1000000007;
long long dp[10][1000005];
int main(){
	long long n,m;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	dp[1][0]=2;
	dp[2][0]=6;
	for(long long i=3;i<=m+n-1;i++){
		dp[i][0]=dp[i-1][1]*2%MOD+dp[i-1][0]*min(min(m,n),i)%MOD;
		dp[i][1]=dp[i-1][0]*min(min(m,n),i)%MOD;
	}
	long long ans=(dp[m+n-1][0]+dp[m+n-1][1])%MOD;
	cout<<ans;
	return 0;
}
