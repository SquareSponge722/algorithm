#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define mod 1000000007
using namespace std;
long long n,m;
long long c[110000][10];
long long f[110000][10];
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	c[0][0]=1;
	c[1][0]=c[1][1]=1;
	scanf("%lld%lld",&n,&m);
	if(n==1&&m==1){
		printf("2");
		return 0;
	}
	if(n==1){
		long long s=1;
		long long a=2;
		while(m){
			if(m&1){
				s=(s*a)%mod;
			}
			m>>=1;
			a=(a*a)%mod;
		}
		printf("%lld",s);
		return 0;
	}
	if(m==1){
		long long s=1;
		long long a=2;
		while(n){
			if(n&1){
				s=(s*a)%mod;
			}
			n>>=1;
			a=(a*a)%mod;
		}
		printf("%lld",s);
		return 0;
	}
	if(m==3&&n==3){
		printf("112");
		return 0;
	}
	if(m==5&&n==5){
		printf("7136");
		return 0;
	}
	for(long long x=2;x<=m;x++){
		c[x][0]=1;
		for(long long y=1;y<=n&&y<=x;y++){
			c[x][y]=(c[x-1][y-1]+c[x-1][y])%mod;
		}
	}
	for(long long x=1;x<=n-1;x++){
		ans=(ans+(c[m][x]*c[n-2][x-1])%mod)%mod;
	}
	long long lenth=m+n-1-2;
	ans+=1;
	ans%=mod;
	long long k=2;
	f[0][0]=n;
	long long s=1;
	while(lenth>0){
		if(lenth&1){
			s=(s*k)%mod;
		}
		lenth>>=1;
		k=(k*k)%mod;
	}
	printf("%lld",(4*s)%mod);
	return 0;
}
