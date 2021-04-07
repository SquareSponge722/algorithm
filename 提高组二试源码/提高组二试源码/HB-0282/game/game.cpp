#include<bits/stdc++.h>
using namespace std;

long long n,m;
const long long mo=1000000007;
long long ksm(long long x,long long k)
{
	long long base=x;long long ans=1;
	while(k)
	{
		if(k&1)ans=ans*base%mo;
		base=base*base%mo;
		k>>=1;
	}
	return ans;
}

long long fac(long long x)
{
	long long temp=1;
	for(int i=2;i<=x;i++)
	{
		temp*=i;
	}
	return temp;
}

long long C(long long n,long long m)
{
	return (fac(n)/fac(n-m)/fac(m))%mo;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	if(n==1||m==1)
	{
		cout<<0;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			ans+=ksm(2,i)*C(n-1,i)%mo;
		}
		ans+=1;
		ans*=4%mo;
		cout<<ans<<endl;
		return 0;
	}
	if(n==2)
	{
		for(int i=1;i<=m;i++)
		{
			ans+=ksm(2,i)*C(m-1,i)%mo;
		}
		ans+=1;
		ans*=4%mo;
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
}

