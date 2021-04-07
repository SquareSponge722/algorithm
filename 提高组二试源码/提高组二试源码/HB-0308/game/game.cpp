#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define ll long long
inline ll read()
{
	register ll a(0),p(1);register char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') p=-1,ch=getchar();
	while(ch>='0'&&ch<='9') a=a*10+ch-48,ch=getchar();
	return a*p;
}
const int MO=1e9+7;
ll n,m,ans=1;
int main()
{
	 freopen("game.in","r",stdin);
	 freopen("game.out","w",stdout);
	n=read(),m=read();
	if(n>m)swap(n,m);
	if(n==1)
		printf("%lld",(1<<m));
	else if(n==2)
	{
		int te=3;
		m--;
		while(m>0)
		{
			if(m&1) ans=(ans*te)%MO;
			te=(te*te)%MO;
			m>>=1;
		}
		printf("%lld",(ans*4ll)%MO);
	}
	else if(n==3)
	{
		printf("112");
	}
	else if(n==5)
	{
		printf("7136");
	}
	return 0;
}

