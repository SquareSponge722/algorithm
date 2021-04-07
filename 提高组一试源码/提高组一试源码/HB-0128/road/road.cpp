#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll a[100002];
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	ll n=read();
 	for(ll i=1;i<=n;i++)
 	{
 		a[i]=read();
 	}
 	ll ans=0;
 	for(ll i=1;i<=n;i++)
 	{
 		if(a[i]>a[i-1])
 		{
 			ans+=a[i]-a[i-1];
 		}
 	}
 	printf("%lld\n",ans);
 	return 0;
}

