#include <cstdio>
#include <algorithm>
using namespace std;
int d[100005];
bool judge(int n)
{
	for(int i=1;i<=n;i++)
		if(d[i]>0)
			return 1;
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	long long cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	while(judge(n))
	{
		int i=1,j=1;
		while(i<=n)
		{
			int need=999999999;
			for(i=j;i<=n;i++)
			{
				if(d[i]<=0)
				{
					i--;
					break;
				}
				need=min(need,d[i]);
			}
			if(need==999999999)
			{
				for(i=i+1;;i++)
					if(d[i]>0)
						break;
				j=i;
				continue;
			}
			for(int k=j;k<=i;k++)
				d[k]-=need;
			cnt+=need;
			for(i=i+1;;i++)
				if(d[i]>0)
					break;
			j=i;
		}
	}
	printf("%lld",cnt);
	return 0;
}