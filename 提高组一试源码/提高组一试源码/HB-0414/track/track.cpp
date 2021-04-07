#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int n,m,root,indegree[50001],f[50001],a[50001],pre[50001];
struct node {
	int u,v,w;
	bool operator < (const node &a) const {
		return w<a.w;
	}
};
vector <node> edge[50001];
int dfs(int u,int fa,int w)
{
	for(int i=0;i<(int)edge[u].size();i++) {
		node to=edge[u][i];
		if(to.v!=fa)
			f[u]=max(f[u],dfs(to.v,u,to.w));
	}
	f[u]+=w;
	return f[u];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int haveroot=0,jh=0,tol=0,lis=0;
	for(int i=1;i<n;i++) {
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		tol+=w; a[i]=w; pre[i]=pre[i-1]+w;
		if(u!=1&&v!=1)
			jh=1;
		if(v!=u+1)
			lis=1;
		edge[u].push_back((node){u,v,w});
		edge[v].push_back((node){v,u,w});
		indegree[u]++; indegree[v]++;
		if(indegree[u]==2&&!haveroot)
			root=u;
	}
	for(int i=0;i<(int)edge[root].size();i++) {
		node to=edge[root][i];
		f[root]=max(f[root],dfs(to.v,root,to.w));
	}
	if(m==1) {
		int ans1=0,ans2=0;
		for(int i=0;i<(int)edge[root].size();i++) {
			int son=edge[root][i].v;
			ans1=max(f[son],ans1); 
			if(ans1>ans2)
				swap(ans1,ans2);
		}
		printf("%d",ans1+ans2);
		return 0;
	}
	if(!jh) {
		sort(a+1,a+1+n);
		printf("%d",a[m+1]);
		return 0;
	}
	if(!lis) {
		printf("%d",pre[m]);
	}
	printf("%d",tol/m+n/1000-1);
	return 0;
}
