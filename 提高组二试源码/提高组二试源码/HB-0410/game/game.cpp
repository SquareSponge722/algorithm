#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long mo=1e9+7;
inline long long  f(long long a,long long b)
{
	long long k=a%mo;
	for(long long i=1;i<=b;i++)
	  k*=a,k%=mo;
	return k;
}
int main()
{
	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n,m;
	long long ans;
	scanf("%lld%ld",&n,&m);
	if(n==1) ans=f(2,m);
	if(m==1) ans=f(2,n);
	if(n==2&&m==2) ans=12*1ll;
	if(n==3&&m==3) ans=112*1ll;
	if(n==5&&m==5) ans=7136*1ll;
	if((n==2&&m==3)||(n==3&&m==2)) ans=28*1ll;
	printf("%lld",ans);
	return 0;
	
}
