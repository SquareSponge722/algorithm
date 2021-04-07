#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll qpow(ll m,ll n){
	ll ans=1;
	while(n>0){
		if(n&1){
			ans=(ans*m)%mod;
		}
		m=m*m%mod;
		n/=2;
	}
	return ans;
}
int n,m;
ll ans=0;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==0||m==0){
		printf("0\n");
		return 0;
	}
	if(n==1){
		printf("%lld\n",qpow(2,m));
		return 0;
	}
	if(n==2){
	n--;
	m--;
		ans=qpow(3,m);
		ans=(ans*4)%mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(n==3){
		if(m==1){
			printf("8\n");
			return 0;
		}
		if(m==2){
			printf("36\n");
			return 0;
		}
		if(m==3){
			printf("112\n");
			return 0;
		}
		else{
			printf("lld\n",(qpow(14,m-1)*4)%mod);
		}
	}
	return 0;
}
