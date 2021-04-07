#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=6005;
int n,mx,x,y,z;
struct edge{
	int v,nt;
}e[N<<1];
int h[N],cnt=0,ans[N],ind=0;
inline void add(int u,int v){
	e[++cnt].v=v;e[cnt].nt=h[u];h[u]=cnt;
	e[++cnt].v=u;e[cnt].nt=h[v];h[v]=cnt;
}
vector<int> q[N];
int fa[N],c[N],m;
void dfs1(int u){
	
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].v;if(v==fa[u])continue;
		q[u].push_back(v);fa[v]=u;
		dfs1(v);
	}
	sort(q[u].begin(),q[u].end());
}
void dfs2(int u){
	ans[++ind]=u;
	for(int i=0;i<q[u].size();i++){
		dfs2(q[u][i]);
	}
}
int vis[N],np=0;
struct node{
	int id;
	bool operator <(const node &bb)const {
		return id>bb.id;
	}
};
priority_queue<node> q1;
void dfs3(){
	q1.push((node){1});
	while(!q1.empty()){
		node na=q1.top();q1.pop();
		int u=na.id;
		if(vis[u])continue;
		vis[u]=1;
		ans[++ind]=u;
		for(int i=h[u];i;i=e[i].nt){
			int v=e[i].v;
			if(!vis[v])q1.push((node){v});
		}
		if(ind==n)break;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);add(x,y);
	}
	if(m==n-1){
		fa[1]=0;dfs1(1);
		dfs2(1);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		return 0;
	}
	else if(m==n){
		
		dfs3();
		for(int i=1;i<=n;i++){printf("%d ",ans[i]);}
	}
	return 0;
}
