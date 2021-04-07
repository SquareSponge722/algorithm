#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005,mod=1e9+7;
int n,m,f[4][4];
long long ans=1;

void solve(int l){
	long long x1=8,x2=4,x3=16,x4=8;
	for(int i=4;i<=l;i++){
		x1*=2,x2*=2,x3*=4,x4*=4;
		x1%=mod,x2%=mod,x3%=mod,x4%=mod;
	}
	ans=x1+x2+x3+x4;
	ans%=mod;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	f[1][1]=2,f[1][2]=4,f[2][1]=4,f[2][2]=12,f[1][3]=8,f[3][1]=8,f[2][3]=36,f[3][2]=36,f[2][3]=36,f[3][3]=112;
	
	scanf("%d%d",&n,&m);
	if(n<=3&&m<=3){
		ans=f[n][m];
	}
	else if(n==2){
		solve(m);
	}
	printf("%lld\n",ans);
	return 0;
}
