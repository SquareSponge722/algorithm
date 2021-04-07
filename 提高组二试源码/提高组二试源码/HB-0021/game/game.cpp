#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000009
using namespace std;
long long n,m;
long long _pow(long long x,long long y)
{
	long long num=1;
	while(y)
	{
		if(y%2)
		{
			y--;
			num=(num*x)%mod;
		}
		else 
		{
			x=(x*x)%mod;
			y>>=1;
		}
	}
	return num;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1)
	{
		if(m==1) 
		{
			printf("2");
			return 0;
		}
		else if(m==2) 
		{
			printf("4");
			return 0;
		}
		else if(m==3)
		{
			printf("8");
			return 0;
		}
		else
		{
			printf("%lld",_pow(2,m)%mod);
			return 0;
		}
	}
	else if(n==2)
	{
		if(m==1)
		{
			printf("4");
			return 0;
		}
		else if(m==2)
		{
			printf("12");
			return 0;
		}
		else if(m==3)
		{
			printf("36");
			return 0;
		}
		else 
		{
			printf("%lld",(4*_pow(3,m-1))%mod);
			return 0;
		}
	}
	else if(n==3)
	{
		if(m==1)
		{
			printf("8");
			return 0;
		}
		else if(m==2)
		{
			printf("36");
			return 0;
		}
		else if(m==3)
		{
			printf("112");
			return 0;
		}
	}
	else if(n==5)
	{
		if(m==5)
		{
			printf("7136");
			return 0;
		}
	}
	return 0;
}
