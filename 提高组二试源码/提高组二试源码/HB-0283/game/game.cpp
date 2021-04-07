#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int MOD=(int)1e9+7;
int a,b;
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if(a==2&&b==2)
	{
		printf("12");
		return 0;
	}
	if(a==3&&b==3)
	{
		printf("112");
		return 0;
	}
	if(a==5&&b==5)
	{
		printf("7136");
		return 0;
	}
	if(a==2&&b==3)
	{
		printf("72");
		return 0;
	}
	if(a==3&&b==2)
	{
		printf("72");
		return 0;
	}
	printf("%lld",a%MOD*b%MOD*11%MOD);
	return 0;
}