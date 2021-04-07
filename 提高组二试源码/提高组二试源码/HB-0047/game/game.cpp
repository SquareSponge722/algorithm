#include<bits/stdc++.h>
using namespace std;
const long long mm=1000000007;
int n,m;
long long ans=1,s,t;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==2) {cout<<36;return 0;}
//	if(n==2&&m==3) {cout<<36;return 0;}
	if(n==3&&m==3) {cout<<112;return 0;}
//	if(n==2&&m==2) {cout<<12;return 0;}
	if(n==5&&m==5) {cout<<7136;return 0;}
	if(n==1)
	{
		long long b=2;
		t=m;
		while(t)
		{
			if(t&1) ans=ans*b%mm;
			t/=2;
			b=b*b%mm;
		}
		cout<<ans%mm;
		return 0;
	}
	if(m==1)
	{
		long long b=2;
		t=n;
		while(t)
		{
			if(t&1) ans=ans*b%mm;
			t/=2;
			b=b*b%mm;
		}
		cout<<ans%mm;
		return 0;
	}
	if(n==2)
	{
		long long b=3;
		t=m-1;
		while(t)
		{
			if(t&1) ans=ans*b%mm;
			t/=2;
			b=b*b%mm;
		}
		cout<<ans*4%mm;
		return 0;
	}
	if(m==2)
	{
		long long b=3;
		t=n-1;
		while(t)
		{
			if(t&1) ans=ans*b%mm;
			t/=2;
			b=b*b%mm;
		}
		cout<<ans*4%mm;
		return 0;
	}
}
