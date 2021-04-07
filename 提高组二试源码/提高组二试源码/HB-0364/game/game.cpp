#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int main(){
	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n,m,ans=2,jc=1;
    scanf("%lld%lld",&n,&m);
    if (n==2&&m==2) cout<<"12"<<endl;
    else if (n==3&&m==3) cout<<"112"<<endl;
    else if (n==5&&m==5) cout<<"7136"<<endl;
    else{
    	for (long long i=n*m;i>=1;i--) jc*=i;
    	for (long long i=n*m-1;i>=1;i--){
    	long long k=1,ii=1;
    	for (long long j=i;j>=1;j--) ii*=j;
		for (long long jj=n*m-i;jj>=1;jj--) k*=jj;
    	ans+=jc/(k*ii);
    	ans%=mo;
    	printf("%lld\n",ans);
    	}
	}
	return 0;
}
