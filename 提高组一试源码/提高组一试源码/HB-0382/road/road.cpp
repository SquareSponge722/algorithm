#include <iostream>
#include <cstdio>

using namespace std;

const int N=100010;

int n,d[N],ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int i;
	
	scanf("%d",&n);
	
	for (i=1;i<=n;++i)
	{
		scanf("%d",d+i);
		if (d[i]>d[i-1])
		{
			ans+=d[i]-d[i-1];
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
