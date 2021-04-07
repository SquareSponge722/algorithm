#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n;
int a[1002];
bool use[1002];
bool dfs(int sz,int sl)
{
	if(sz%a[sl]==0)
		return true;
	else
	{
		if(sl==1)
			return false;
		int d=sz/a[sl];
		for(int k=0;k<=d;k++)
		{
			bool use=dfs(sz-k*a[sl],sl-1);
			if(use)
				return true;
		}
		return false;
	}
}
void init()
{
	for(int k=1;k<=n;k++)
	{
		a[k]=0;
		use[k]=false;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		int ans=0;
		scanf("%d",&n);
		for(int k=1;k<=n;k++)
		{
			scanf("%d",&a[k]);
			use[k]=true;
		}
		sort(a+1,a+n+1);
		for(int k=n;k>1;k--)
			if(dfs(a[k],k-1))
				use[k]=false;
		for(int k=1;k<=n;k++)
			if(use[k])
				ans++;
		printf("%d\n",ans);
		init();
	}
	return 0;
}
