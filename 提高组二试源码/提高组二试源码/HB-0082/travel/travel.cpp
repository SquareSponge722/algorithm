#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int N=5010;
int n,m,ste,ans[N];
bool vis[N],flag;
priority_queue <int,vector<int>,greater<int> > q[N];
void dfs(int x)
{
	ans[++ste]=x;
	vis[x]=true;
	if (ste==n)
	{
		flag=true;
		return ;
	}
	while (q[x].size())
	{
		int c=q[x].top();
		if (!vis[c]) dfs(c);
		if (flag) return;
		q[x].pop();
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf ("%d %d",&n,&m);
	for (int i=1; i<=m; i++)
	{
		int a,b;
		scanf ("%d %d",&a,&b);
		q[a].push(b),q[b].push(a);
	}
	if (m==n-1)
	{
		dfs(1);
		for (int i=1; i<=n; i++)
			printf ("%d ",ans[i]);
		printf ("\n");
	}

	return 0;
}
