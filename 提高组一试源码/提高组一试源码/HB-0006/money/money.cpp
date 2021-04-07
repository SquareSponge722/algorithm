#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
int a[maxn],b[maxn],cnt=0,vis[maxn];
int main()
{	
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(a[j]%a[i]==0 && !vis[i])
					vis[j]=1;
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{	
				for(int j=1;j<=n;++j)
					if(!vis[j] && j!=i && a[i]>a[j])
					{
						for(int k=1;k<=n;++k)
							if(!vis[k] && k!=i && k!=j)	
							{
								if((a[i]-a[j])%a[k]==0)
									vis[i]=1;
							}
					}	
			}
		for(int i=1;i<=n;++i)
			if(!vis[i])
				++ans;
		printf("%d\n",ans);
	}	
	return 0;
}
