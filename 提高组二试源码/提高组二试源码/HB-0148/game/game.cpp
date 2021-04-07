//chf sj ycy -||-
#include<bits/stdc++.h>

using namespace std;

#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rrep(i,x,y) for(register int i=x;i>=y;i--)

typedef long long ll;
typedef double db;

const int p=1e9+7;
//const int maxn=;

int n,m;
ll Fac[100];
ll Ans;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll power(ll a,ll b)
{
	ll ans=1%p;
	for(;b;b>>=1,a=a*a%p) if(b&1) ans=ans*a%p;
	return ans;
}

void work()
{
	n=read();m=read();
	if(n>m) swap(n,m);
	Fac[0]=1;
	rep(i,1,10) Fac[i]=Fac[i-1]*i%p;
	ll Ans=Fac[n]*Fac[n+1]%p;
	Ans=Ans*power(n+1,m-n)%p;
	printf("%lld\n",Ans);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	work();
	return 0;
}
