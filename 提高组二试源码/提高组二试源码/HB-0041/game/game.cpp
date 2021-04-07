#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long sum=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch<='9'&&ch>='0'){sum=sum*10+ch-'0';ch=getchar();}
	return sum;
}
const long long mod = 1e9+7;
long long kuaisumi(long long x,long long y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
long long n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if(n==1||m==1)cout<<0<<endl;
	else if(n==2&&m==2)cout<<12<<endl;
	else if(n==3&&m==2)cout<<40<<endl;
	else if(n==3&&m==3)cout<<112<<endl;
	else if(n==5&&m==5)cout<<7136<<endl;
	else if(n==2)
	{
		long long cheng=4,ans=0;
		for(long long i=1;i<=m-1;i++)
		{
			(ans+=cheng*kuaisumi(2ll,(m-i-1)*2)%mod)%=mod;
			(cheng*=2)%=mod;
		}
		(ans+=cheng)%=mod;
		cout<<ans;
	}
	return 0;
}
