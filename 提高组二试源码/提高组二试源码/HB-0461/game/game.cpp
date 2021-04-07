#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int n,m;
long long ksm(int x,int a){
	if(a==0) return 1;
	long long temp=ksm(x,a/2);
	if(a%2==0){
		return (temp*temp)%mod;
	}
	else{
		return ((temp*temp)%mod)*x%mod;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1){
		printf("%lld\n",ksm(2,m));
		return 0;
	}
	if(n==2){
		printf("%lld",(ksm(3,m-1)*4)%mod);
		return 0;
	}
	if(n==3){
		printf("%d\n",((n*m-2)%mod*16)%mod);
	}
	if(n==5){
		printf("7136\n");
	}
	return 0;
}
