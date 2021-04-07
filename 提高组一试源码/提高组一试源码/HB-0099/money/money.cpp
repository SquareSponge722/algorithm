#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;
const int N=3000;
int a[N],m,b[N],vis[N],cnt[N],cnt1[N],tot,n;
set <int> s;
inline bool check()
{
	for (int i=1;i<=N*2;i++) if(cnt[i]!=cnt1[N]) return false;
	return true;
}
inline bool dfs(int sum)
{
	if (!sum)
		{
			for (int i=1;i<=tot;i++)
				for (int j=i;j<=tot;j++)
					cnt1[a[i]*a[j]-a[i]-a[j]]=1;
			if (check()) 
				{	
					memset(cnt1,0,sizeof(cnt1));
					return true;
				}
			else
				{
					memset(cnt1,0,sizeof(cnt1));
					return false;
				}
		}
	for (int i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			vis[i]=1;
			b[++tot]=a[i];
			if (dfs(sum-1))
				return true;
			vis[i]=0;
			b[tot]=0;
			tot--;
		}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
		{	int fla=0;
			scanf("%d",&n);
			for (int i=1;i<=n;i++)
				scanf("%d",&a[i]);
			if (n==2)
				{
					if (a[1]%a[2]==0 or a[2]%a[1]==0)
						printf("1\n");
					else printf("2\n");
					memset(a,0,sizeof(a));
					memset(b,0,sizeof(b));
					memset(cnt,0,sizeof(cnt));
					memset(cnt1,0,sizeof(cnt1));
					memset(vis,0,sizeof(vis));
					continue;
				}
			
			for (int i=1;i<=n;i++)
				for (int j=i;j<=n;j++)
					cnt[a[i]*a[j]-a[i]-a[j]]=1;
			for (int i=1;i<=n-1;i++)
				if (dfs(i))
					{	
						fla=1;
						tot=0;
						memset(vis,0,sizeof(vis));
						memset(cnt1,0,sizeof(cnt1));
						memset(b,0,sizeof(b));
						printf("%d\n",i);
						break;
					}
			if (!fla) printf("%d\n",n);
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(cnt,0,sizeof(cnt));
			memset(cnt1,0,sizeof(cnt1));
			memset(vis,0,sizeof(vis));
		}
	return 0;
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
