#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N=5e3+5;
vector <int> ans;
vector <int> v[N];
int vis[N];
int fa[N];
int n,m;

//int getfather(int a)
//{
//	return fa[a]==a?fa[a]:fa[a]=getfather(fa[a]);
//}
//
//void merge(int a,int b)
//{
//	int x=getfather(a);
//	int y=getfather(b);
//	if (x!=y)fa[x]=y;
//	return;
//}

void dfs(int now)
{
	if (vis[now])return;
	vis[now]=1;
	ans.push_back(now);
	for (int i=0; i<v[now].size(); i++)
	{
		dfs(v[now][i]);
	}
}

void dfs2(int fa,int now,int step)
{
	if (vis[now])return;
	vis[now]=1;
	ans.push_back(now);
	for (int i=0; i<v[now].size(); i++)
	{
		if (step!=v[fa].size()-1)
		{
			if (v[now][i]>v[fa][step+1])
				dfs2(fa,v[fa][step+1],step+1);
			else
				dfs2(now,v[now][i],i);
		}

	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1; i<=n; i++)
		sort(v[i].begin(),v[i].end());
	dfs(1);
	for (int i=0; i<ans.size(); i++)
		printf("%d ",ans[i]);
	return 0;
}
