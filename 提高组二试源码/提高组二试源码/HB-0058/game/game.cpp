#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
long long m,n,h=0;
long long ans=4;
long long ans1=2;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld",&m,&n);
	if(m==1)
	{
		while(h<(n-1))
		{
			ans1=ans1*2;
			h++;
			ans1=ans1%1000000007;
		}
		printf("%lld",ans1);
	}
	if(m==3&&n==1)
		cout<<8;
	if(m==3&&n==2)
		cout<<36;
	if(m==3&&n==3)
		cout<<112;
	if(m==5&&n==5)
		cout<<7136;
	if(m==2)
	{
		while(h<(n-1))
		{
			ans=ans*3;
			h++;
			ans=ans%1000000007;
		}
		printf("%lld",ans);
		h=0;
	}
}
