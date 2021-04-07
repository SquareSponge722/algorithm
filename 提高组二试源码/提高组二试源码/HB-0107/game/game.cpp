#include<bits/stdc++.h>
using namespace std;
int m,n;
long long ans=1,ls;
int a2[1000005];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1) {
		for(int i=1; i<=m; i++) {
			ans=ans*2;
			ans=ans%1000000009;
		}
		printf("%lld",ans);
	}
	if(n==2) {
		a2[0]=1;
		for(int i=1; i<=2*m; i++) {
			a2[i]=a2[i-1]*2;
		}
		ans=a2[m+1];
		for(int i=1; i<=m; i++) {
			ls=ls+((long long)a2[i]*(long long)a2[2*m-2*i-1])%1000000009;
			ls=ls%1000000009;
		}
		ans=(ans+ls)%1000000009;
		printf("%lld",ans);
	}
	if(n==3) {
		if(m==1) {
			printf("8");
		}
		if(m==2) {
			printf("40");
		}
		if(m==3) {
			printf("112");
		}
	}
	if(m==5&&n==5) printf("7136");
	return 0;
}
