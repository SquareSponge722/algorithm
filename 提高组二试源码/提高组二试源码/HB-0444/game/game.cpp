#include<iostream>
#include<cstdio>
using namespace std;
long long dp0[9][10000002];
long long dp1[9][10000002];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	const long long mod=1000000007;
	scanf("%d%d",&n,&m);
	dp0[1][1]=dp1[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i-1>0){
				dp0[i][j]=(dp0[i][j]+dp0[i-1][j])%mod;
				dp1[i][j]=(dp1[i][j]+dp1[i-1][j])%mod;
				dp1[i][j]=(dp1[i][j]+dp0[i-1][j])%mod;
				dp0[i][j]=(dp0[i][j]+dp1[i][j-1])%mod;
			}
			if(j-1>0){
				dp0[i][j]=(dp0[i][j]+dp0[i][j-1])%mod;
				dp1[i][j]=(dp1[i][j]+dp1[i][j-1])%mod;
				dp0[i][j]=(dp0[i][j]+dp1[i][j-1])%mod;
				dp1[i][j]=(dp1[i][j]+dp0[i-1][j])%mod;
			}
		}
	}
	printf("%lld",dp0[n][m]+dp1[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}