#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int N=2e5;
int n,m;
char s[100];
int co[N],ans,vis[N],unvis[N];
int nex[N],pre[N];
inline void work(int a,int x,int b,int y)
{
	if (x==1) vis[pre[a]]++,vis[nex[a]]++;
	if (x==0) unvis[a]=1;
	if (y==1) vis[pre[b]]++,vis[nex[b]]++;
	if (y==0) unvis[b]=1;
	for (int i=1;i<=n;i++)
		{	if (i==a or i==b) continue;
			if (unvis[i]) continue;
			if (!vis[i])
				ans+=co[i],vis[pre[i]]++,vis[nex[i]]++;
			else if (vis[i]>=2) continue;
			else if (vis[i]==1)
				{
					if (vis[pre[i]]>=1 and vis[nex[i]]>=1) continue;
					if (vis[pre[i]]==0 and vis[nex[i]]==0) 
						{
							ans+=co[i],ans+=co[i],vis[pre[i]]++,vis[nex[i]]++;
							continue;
						}
					if (vis[pre[i]]==0)
						{
							ans+=co[pre[i]],vis[i]++,vis[pre[pre[i]]]++;
							continue;
						}
				}
		}
		for (int i=1;i<=n;i++)
			if (!vis[i]) ans+=co[i];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s);
	for (int i=1;i<=n;i++) scanf("%d",&co[i]);
	for (int i=1;i<n;i++)
		{
			int s,e;
			scanf("%d %d",&s,&e);
		}
	for (int i=1;i<=n;i++)
			pre[i]=i-1,nex[i]=i+1;
	if (s[0]=='A')
		{	
			for (int i=1;i<=m;i++)
				{	int fla=1;
					ans=0;
					int a,x,b,y;
					scanf("%d %d %d %d",&a,&x,&b,&y);
					if (x==1) ans+=co[a],vis[a]=2;
					if (y==1) ans+=co[b],vis[b]=2;
					if (x==0) unvis[a]=1;
					if (y==0) unvis[b]=1;
					if ((nex[a]==b or pre[a]==b) and (x==0 and y==0))
						fla=0;
					if (!fla)
						{
							printf("-1\n");
							continue;
						}
					else
						{
							work(a,x,b,y);
							printf("%d\n",ans);
						}
				}
		}
	return 0;
}
