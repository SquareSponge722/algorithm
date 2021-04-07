#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=5050;
int n,m,h[N],en,cnt,ans[N],d[N],dfn[N],low[N];
bool vis[N],used[N*2];
priority_queue<pair<int,int> > q[N];

struct Edge{
	int to,next;
}e[N*2];

void add(int u,int v){
	e[++en].to=v;
	e[en].next=h[u];
	h[u]=en;
	q[u].push(make_pair(-v,en));
	e[en+n].to=u;
	e[en+n].next=h[v];
	h[v]=en+n;
	q[v].push(make_pair(-u,en+n));
}

void dfs(int u,int nn){
	vis[u]=1;
	ans[++cnt]=u;
	while(!q[u].empty()){
		int v=q[u].top().first,mm=q[u].top().second;
		v=-v;
		q[u].pop();
		while((mm==nn+n||mm==nn-n)&&!q[u].empty()){
			v=q[u].top().first,mm=q[u].top().second;
			v=-v;
			q[u].pop();
		}
		if(!vis[v]){
			dfs(v,mm);
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1,-n);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}
