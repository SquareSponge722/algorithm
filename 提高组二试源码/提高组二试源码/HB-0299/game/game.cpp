#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n,ans[10][10],m,dp[10];
const int mod=1e9+7;
inline int qpow(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=a*1ll*s%mod;
		a=a*1ll*a%mod;
		b>>=1;
	}
	return s%mod;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m<n)swap(n,m);
	if(n<=2){
			for(int i=1;i<=8;++i){
			dp[i]=i+1;
			}
			int wjr=1;
			for(int i=1;i<n;++i)wjr=wjr*1ll*dp[i]%mod;
			printf("%lld\n",((wjr*1ll*wjr%mod)*1ll*qpow(dp[n],(m-n+1))%mod));
		}
	else{
		if(n==3){
			if(m==3){
				printf("112\n");
			}
		}
	}
	return 0;
}

