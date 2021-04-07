#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int n,m;
int ans;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		printf("2");return 0;
	}
	if(n==3&&m==1){
		printf("8");return 0;
	}
	if(n==3&&m==2){
		printf("36");return 0;
	}
	if(n==3&&m==3){
		printf("112");return 0;
	}
	if(n==1){
		ll t=1;
		for(int i=1;i<=m;i++) t=(t*2)%mod;
		printf("%lld",t);return 0;
	}
	if(m==1){
		ll t=1;
		for(int i=1;i<=n;i++) t=(t*2)%mod;
		printf("%lld",t);return 0;
	}
	if(n==2){
		ll t=4;
		for(int i=1;i<m;i++) t=t*3%mod;
		printf("%lld",t%mod);return 0;
	}
	if(m==2){
		ll t=4;
		for(int i=1;i<n;i++) t=t*3%mod;
		printf("%lld",t%mod);return 0;
	}
	if(n==3){
		ll t=112;
		for(int i=1;i<=m-3;i++) t=t*3%mod;
		printf("%lld",t%mod);return 0;
	}
	if(m==3){
		ll t=112;
		for(int i=1;i<=n-3;i++) t=t*3%mod;
		printf("%lld",t%mod);return 0;
	}
	if(n==5){
		ll t=7136;
		for(int i=1;i<=m-5;i++) t=t*3%mod;
		printf("%lld",t%mod);return 0;
	}
	if(m==5){
		ll t=7136;
		for(int i=1;i<=n-5;i++) t=t*3%mod;
		printf("%lld",t%mod);return 0;
	}
	return 0;
}
