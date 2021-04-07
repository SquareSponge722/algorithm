#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
int n,m;
struct node
{
	long long name;
	long long list;
};
queue <long long> qu[1000];
node d[10000];
int ans[10000];
int em,emm;
bool flag[10000];
void dfs(queue <long long> q)
{
	if (!q.empty())
	{
		int now=q.front();
		q.pop();
		if (flag[now])
		{
			dfs(q);
			return ;
		}
		else
		{
			flag[now]=true;
			ans[emm++]=now;
			dfs(q);
			return ;
		}
	}
	else
	{
		dfs(qu[em++]);
		return ;
	}
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (int i=0;i<m;i++)
	{
		scanf("%lld %lld",&d[i].name,&d[i].list);
		qu[d[i].name].push(d[i].list);
	}
	dfs(qu[d[em].name]);
	for (int i=0;ans[i];i++)
		printf("%d",ans[i]);
	return 0;
}
