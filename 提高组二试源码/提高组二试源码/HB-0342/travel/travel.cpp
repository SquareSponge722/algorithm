#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cmath>
#define MAXN 5005
using namespace std;
int n,m,t=0;
int d[MAXN],inq[MAXN],ans=0x3f3f3f;
vector<int> ms[MAXN];
priority_queue <int> q;
queue <int> q_1;
priority_queue <int> q_2;
void dfs(int x)
{
	inq[x]=1;
	d[++t]=x;
	for(int i=0; i<ms[x].size(); i++)
	{
		if(!inq[ms[x][i]])
		{
			q.push(ms[x][i]);
		}
	}
	ms[x].clear();
	while(!q.empty())
	{
		int u=q.top();
		ms[x].push_back(u);
		q.pop();
	}
	for(int i=ms[x].size()-1; i>=0; i--)
	{
		if(!inq[ms[x][i]]);
		dfs(ms[x][i]);
	}
}
void dfs_E(int x,int s,int tot)
{
	inq[x]=1;
	if(tot==n)
	{
		ans=min(ans,s);
		return ;
	}
	for(int i=0;i<ms[x].size();i++)
	{
		int u=ms[x][i];
		if(!inq[u])
		{
			dfs_E(u,s+pow(10,tot)*u,tot+1);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ms[a].push_back(b);
		ms[b].push_back(a);
	}
	if(m==n-1)
		dfs(1);
	else
	{
		dfs_E(1,1,1);
		while(ans)
		{
			printf("%d ",ans%10);
			ans/=10;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(d[i])
     		printf("%d ",d[i]);
	}
	printf("\n");
	return 0;
}

