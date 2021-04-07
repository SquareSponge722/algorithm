#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,m,cnt,e=-1,indexx=0;
int ans[5001],head[5001],num[5001],low[5001],final[5001];
bool book[5001],cut[10010];
vector <int> uedge;
struct node {
	int u,v,next;
}edge[10010];
void addedge(int u,int v)
{
	edge[++e].next=head[u]; head[u]=e; edge[e].u=u; edge[e].v=v;
	edge[++e].next=head[v]; head[v]=e; edge[e].u=v; edge[e].v=u;
	return;
}
void dfss(int u,int fa)
{
	num[u]=low[u]=++indexx;
	for(int i=head[u];i!=-1;i=edge[i].next) if(edge[i].v!=fa){
		int v=edge[i].v;
		if(!num[v]) {
			dfss(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]<=num[u])
				uedge.push_back(i);
		}
		else
			low[u]=min(low[u],num[v]);
	}
	return;
}
void dfs(int u,int fa)
{
	priority_queue <int> qu;
	book[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)
		if(edge[i].v!=fa&&!book[edge[i].v]&&!cut[i])
			qu.push(edge[i].v);
	while(!qu.empty()) {
		dfs(qu.top(),u);
		qu.pop();
	}
	ans[--cnt]=u;
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt=n+1;
	memset(head,-1,sizeof(head));
	memset(final,0x7f,sizeof(final));
	for(int i=1;i<=m;i++) {
		int u,v; scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	if(m==n-1) {
		dfs(1,0);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	if(m==n) {
		dfss(1,0);
		for(int i=0;i<(int)uedge.size();i++) {
			cut[uedge[i]]=cut[uedge[i]^1]=1;
			dfs(1,0);
			cut[uedge[i]]=cut[uedge[i]^1]=0;
			if(memcmp(final,ans,sizeof(ans)))
				memcpy(final,ans,sizeof(ans));
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		return 0;
	}
}
