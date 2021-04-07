#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int tot;
int d[200];
bool flag[200];
int sum;
int main()
{
	freopen("road.in ","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	scanf("%d",&m);
	while (m--)
	{
		for (int i=1;d[i];i++)
			d[i]=0;
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&d[i]);
		int ans=n;
		sort(d,d+n);
		for (int i=1;i<n;i++)
		{
			for (int j=1;j<n;j++)
			{
				for (int k=2;k<=n;k++)
				{
					if (flag[k]==true)
						continue;
					if (d[i]+d[j]==d[k] || d[i]*j==d[k] || d[i]==d[k])
					{
						flag[k]=true;
						ans--;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
