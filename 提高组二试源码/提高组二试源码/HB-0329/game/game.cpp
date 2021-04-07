#include<cstdio>
#define ll long long
#define FOR(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
ll ans;
const ll mod=1e9+7;

ll read()
{
	ll p=1,q=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0'&&c<='9'){q=q*10+c-'0';c=getchar();}
	return p*q;
}

ll qpow(ll x,ll y,ll z){
	ll num=1;
	for(;y;y>>=1,x=x*x%z)
	if(y&1)num=num*x%z;
	return num;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll n=read(),m=read();
	if(m==n){
		ans=4*(n+1);
		for(int i=n;i>=3;i--){
			ans*=i*i;ans%=mod;
		}
		printf("%lld",ans);
	}
	if(n<m){
		for(int i=n;i>=3;i--){
			ans*=i*i;ans%=mod;
		}
		ans=qpow(n+1,m-n+1,mod);
		ans=ans*4%mod;
		printf("%lld",ans);
	}
	if(n>m){
		ans=4;
		for(int i=m+1;i>=3;i--){
			ans*=i*i;ans%=mod;
		}
		printf("%lld",ans);
	}
	return 0;
}
