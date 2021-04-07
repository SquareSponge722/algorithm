#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int mod=1000000007;
unsigned long long ans=0;
long long qpow(int a,int b)
{
	long long aans=1,base=a;
	while(b)
	{
		if(b&1)
			aans=(aans*base)%mod;
		b>>=1;
		base=(base*base)%mod;
	}
	return aans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1||m==1)
		ans=0;
	if(n==2)
	{
		for(int i=2;i<=m;i++)
		{
			int a=qpow(2,i-1),b=a+1;
			ans+=(((2*(a*b)%mod)%mod)*(m-i+1))%mod;
			ans%=mod;
		}
	}
	if(n==3)
	{
		for(int i=2;i<=m;i++)
		{
			int a=qpow(2,i-1),b=a+1;
			ans+=(((2*(a*b)%mod)%mod)*(m-i+1))%mod;
			ans%=mod;
		}
		ans=(ans*2)%mod;
		ans-=16;
	}
	else{
		for(int i=2;i<=m;i++)
		{
			int a=qpow(2,i-1),b=a+1;
			ans+=(((2*(a*b)%mod)%mod)*(m-i+1))%mod;
			ans%=mod;
		}
		unsigned long long r=(qpow(2,n)*qpow(n-2,n-2))%mod;
		ans=(ans*qpow(2,n-2))%mod-r;
		
	}
	printf("%lld",ans);
}
