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
int ans[N],vis[N],next[N],cnt;
vector <int> g[N];
struct node
{
	int num,step;
	inline bool operator < (const node &b)const
		{	if (vis[num]!=vis[b.num]) return vis[num]>vis[b.num];
			if (step!=b.step) return step>b.step;
			return num>b.num;
		}
};
int n,m;
inline void bfs()
{
	priority_queue <node> q;
	node u;
	u.num=1,u.step=1,ans[1]=1;
	q.push(u);
	while (!q.empty())
		{
			node h=q.top();
			q.pop();
			if (!vis[h.num])
			{
				++cnt;
				ans[cnt]=min(h.num,ans[cnt]);
				if (cnt==n) break;
			}
			vis[h.num]++;
			int size=g[h.num].size();
			int fla=1;
			for (int i=0;i<size;i++) 
				{
					int v=g[h.num][i];
					if (!vis[v])
						{	
							fla=0;
							break;
						}
				}
			for (int i=0;i<size;i++)
				{
					int v=g[h.num][i];
					if (!vis[v])
						{
							node tmp;
							tmp.num=v,tmp.step=h.step+1;
							q.push(tmp);
							break;
						}
					else if (vis[v]>=1 and fla)
						{
							node tmp;
							tmp.num=v,tmp.step=cnt;
							q.push(tmp);
						}
				}
		}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}
inline void bfs1()
{
	priority_queue <node> q;
	node u;
	u.num=1,u.step=1,ans[1]=1;
	q.push(u);
	while (!q.empty())
		{
			node h=q.top();
			q.pop();
			if (!vis[h.num])
			{
				++cnt;
				ans[cnt]=min(h.num,ans[cnt]);
				if (cnt==n) break;
			}
			vis[h.num]++;
			int size=g[h.num].size();
			for (int i=0;i<size;i++)
				{
					int v=g[h.num][i];
					if (!vis[v])
						{
							node tmp;
							tmp.num=v,tmp.step=h.step+1;
							q.push(tmp);
						}
					else if (vis[v])
						{
							node tmp;
							tmp.num=v,tmp.step=h.step+2;
							q.push(tmp);
						}
				}
		}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(ans,0x3f3f3f3f,sizeof(ans));
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
		{
			int s,e;
			scanf("%d %d",&s,&e);
			g[s].push_back(e);
			g[e].push_back(s);
		}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	if (m==n-1) bfs();
	if (m==n) bfs1(); 
	return 0;
}
