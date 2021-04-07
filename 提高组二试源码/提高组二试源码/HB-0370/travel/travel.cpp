#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> e[5010];
priority_queue<int> q;
int path[5010],n,m,t;
bool vis[5010];
void s()
{
	q.push(-1);
	while(!q.empty())
	{
		int x=-q.top();
		while(vis[x])q.pop(),x=-q.top();
		q.pop();
		vis[x]=true;
		path[++t]=x;
		for(unsigned int i=0;i<e[x].size();i++)
			if(!vis[e[x][i]])q.push(-e[x][i]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	s();
	for(int i=1;i<=n;i++)
		printf("%d ",path[i]);
	return 0;
}