#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100005
using namespace std;
int n,minn=0,maxx=MAXN,ans=0;
int d[MAXN];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&d[i]);
	minn=0;
	maxx=d[1];
	for(int i=1; i<=n; i++)
	{
		if(d[i]>minn)
		{
			ans+=d[i]-minn;
			minn=d[i];
		}
		if(minn>d[i]) minn=d[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
6
4 3 2 5 3 5
*/
