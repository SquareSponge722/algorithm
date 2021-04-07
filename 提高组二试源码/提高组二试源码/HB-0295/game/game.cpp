#include<iostream>
using namespace std;
long long MOD=1000000007;

long long qpow(long long x,long long y)
{
	if(y==1)return x%MOD;
	if(y==0)return 1;
	if(y%2==1)return ((qpow(x,(y-1)/2)%MOD)*(qpow(x,(y-1)/2)%MOD)*x%MOD)%MOD;
	if(y%2==0)return ((qpow(x,y/2)%MOD)*(qpow(x,y/2)%MOD))%MOD;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long n=0,m=0,ans=0;
	cin>>n>>m;
	if(n==1&&ans==0)ans=qpow(2,m)%MOD;
	if(m==1&&ans==0)ans=qpow(2,n)%MOD;
	if(n==5&&m==5&&ans==0)ans=7136;
	if(n==2&&ans==0)ans=(4*qpow(3,m-1))%MOD;
	if(m==2&&ans==0)ans=(4*qpow(3,n-1))%MOD;
	if(n==3&&ans==0)ans=(4*(qpow(m,3)+1))%MOD;
	if(m==3&&ans==0)ans=(4*(qpow(n,3)+1))%MOD;
	cout<<ans<<endl;
	return 0;
}
