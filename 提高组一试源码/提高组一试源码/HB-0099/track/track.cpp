#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;
const int N=4e5;
int d1[N],d2[N],n,m,ans1,ans2,vis[N],l[N];
struct node
{
	int e,l;
};
vector <node> g[N];
inline void dfs(int u)
{
	vis[u]=1;
	int size=g[u].size();
	for (int i=0;i<size;i++)
		{
			node v=g[u][i];
			if (vis[v.e]) continue;
			dfs(v.e);
			if (d1[u]<d1[v.e]+v.l)
				{
					d2[u]=d1[u];
					d1[u]=d1[v.e]+v.l;
				}
			else if (d2[u]<d1[v.e]+v.l) d2[u]=d1[v.e]+v.l;
		}
}
inline void work1()
{
	for (int i=1;i<n;i++)
		{
			int s,e,l;
			scanf("%d %d %d",&s,&e,&l);
			node tmp;
			tmp.e=e,tmp.l=l;
			g[s].push_back(tmp);
			tmp.e=s;
			g[e].push_back(tmp);
		}
	dfs(1);
	for (int i=1;i<=n;i++) ans1=max(ans1,d1[i]+d2[i]);
	printf("%d",ans1);
	return;
}
inline bool check(int x)
{
	int tot=0,sum=0;
	for (int i=1;i<=n;i++)
		{
			if (sum+l[i]<=x)
				sum+=l[i];
			else
				{
					tot++;
					sum=l[i];
				}
		}
	return tot>=m;
}
inline void work2()
{
	if (m==n-1)
		{	int ans2=0;
			for (int i=1;i<n;i++)
			{
				int s,e,l;
				scanf("%d %d %d",&s,&e,&l);
				node tmp;
				tmp.e=e,tmp.l=l;ans2=max(ans2,tmp.l);
				g[s].push_back(tmp);
				tmp.e=s;
				g[e].push_back(tmp);
			}
			printf("%d",ans2);
			return;
		}
	else
		{	int ll=0x3f3f3f3f,r=0;
			for (int i=1;i<n;i++)
				{
					int s,e,len;
					scanf("%d %d %d",&s,&e,&len);
					l[i]=len;r+=l[i];
					ll=min(ll,l[i]);
				}
			while (r>ll)
				{
					int mid=(ll+r)/2;
					if (check(mid)) r=mid-1;
					else ll=mid;
				}
			printf("%d",r);
			return;
		}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	if (m==1)
		work1();
	else
		work2();
	return 0;
}
