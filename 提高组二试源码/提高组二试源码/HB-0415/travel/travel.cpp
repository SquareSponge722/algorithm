#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=5050;
int n,m,x,y,tot;
int ans[N];
vector < int > g[N];
void dfs(int,int);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,1);
	for(int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}
void dfs(int k,int fa)
{
	ans[++tot]=k;
	int siz=g[k].size();
	sort(g[k].begin(),g[k].end());
	for(int i=0;i<siz;i++)
	{
		int to=g[k][i];
		if(to==fa) continue;
		dfs(to,k);
	}
}
