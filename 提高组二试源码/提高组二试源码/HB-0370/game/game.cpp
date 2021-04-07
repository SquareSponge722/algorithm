#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long MOD=1000000007;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	long long ans=4;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++)
	{
		long long t=1,x=1,y=i;
		while(x<=n && y)
			t++,x++,y--;
		ans=ans*t%MOD;
	}
	for(int i=2;i<n;i++)
	{
		long long t=1,x=i,y=n;
		while(x<=n && y)
			t++,x++,y--;
		ans=ans*t%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}