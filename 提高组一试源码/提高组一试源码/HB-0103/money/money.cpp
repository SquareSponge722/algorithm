#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int t;
const int N=101;
int d[N];
bool use[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		bool is_1=false;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&d[j]);
			if(d[j]==1)
			is_1=true;
		}
		if(is_1)
		{
			printf("1\n");
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(k==j)
				continue;
				if(d[j]%d[k]==0)
				use[j]=true;
				if(d[j]-d[k]>0)
				{
					for(int a=1;a<=n;a++)
					{
						if(a==j || a==k)
						continue;
						else
						{
							if((d[j]-d[k])%d[a]==0)
							use[j]=true;
						}
					}
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(!use[j])
			ans++;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		use[i]=false;
	}
	return 0;
}
