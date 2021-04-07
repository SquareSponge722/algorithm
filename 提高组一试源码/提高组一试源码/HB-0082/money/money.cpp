#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110;
const int M=25010;
int t,n,ans,a[N];
bool vis[M],flag;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf ("%d",&t);
	while (t--)
	{
		scanf ("%d",&n);
		ans=n;
		for (int i=1;i<=n;i++)
		{
			scanf ("%d",&a[i]);
			if (a[i]==1)
				flag=true;
		}
		if (flag)
		{
			printf ("1\n");
			continue;
		}
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++)
		{
			if (vis[a[i]])
			{
				ans--;
				continue;
			}
			vis[a[i]]=true;
			for (int j=2;a[i]+j<=a[n];j++)
				if (vis[j])
					vis[a[i]+j]=true;
		}
		printf ("%d\n",ans);
		flag=false;
		memset(vis,false,sizeof(vis));
		memset(a,0,sizeof(a));
	}
	return 0;
}
