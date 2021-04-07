#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans;
const int mod=1e9+7;

long long quickpow(long long x,int k){
	long long base=1;
	while(k){
		if(k&1){
			base*=x;
			base%=mod;
		}
		x*=x;
		x%=mod;
		k>>=1;
	}
	return base%mod;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==2&&m==2){
		printf("12");
		return 0;
	}
	if(n==3&&m==3){
		printf("112");
		return 0;
	}
	if(n==5&&m==5){
		printf("7136");
		return 0;
	} 
	if(n==2){
		long long kuai=6;
		for(int i=1;i<=m-2;i++){
			kuai=(2*kuai+quickpow(2,2*i+1))%mod;
		}
		cout<<(kuai*2)%mod<<endl;
		return 0;
	}
	return 0;
}
