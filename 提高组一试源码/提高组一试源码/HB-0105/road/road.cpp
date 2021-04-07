#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e6 + 10;
int d[maxn];
int n,r,l;
long long ans = 0;
inline void qwq()
{
	for(int cur = 1;cur <= n;cur ++)
	if(d[cur] != 0)
		{
			l = cur;
			break;
		}
	for(r = l;;r ++)
	  if(d[r] == 0)
		{
			r --;
			break;
		}
}
inline bool orz()
{
	for(int i = 1;i <= n;i ++)
	if(d[i] != 0) return true;
	return false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	scanf("%d",&d[i]);
	while(orz())
	{
		qwq();
		for(int i = l;i <= r;i ++)
		d[i] --;
//		for(int i = 1;i <= n;i ++)
//		printf("%d ",d[i]);
//		printf("\n");
		ans ++;
	}
	printf("%lld\n",ans);
	return 0;
}
