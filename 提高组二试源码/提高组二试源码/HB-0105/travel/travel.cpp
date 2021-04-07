#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<ctime>
using namespace std;
const int maxn = 5010 * 2;
int to[maxn];
int nxt[maxn];
int head[maxn];
int tot = 0;
int n,m,cur,ans[maxn],x = 1;

void addEdge(int u,int v)
{
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void dfs(int x)
{
	if(sizeof(ans) == n) return;
	for(cur = head[x];cur;cur = nxt[cur])
	if(to[cur] < ans[x+1]) ans[x+1] = to[cur];
	x = to[cur];
	dfs(x);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	memset(ans,99999,sizeof(ans));
	ans[1] = 1;
	dfs(x);
	for(int i = 1;i <= n;i ++)
	cout << ans[i] <<" ";
	return 0;
}
