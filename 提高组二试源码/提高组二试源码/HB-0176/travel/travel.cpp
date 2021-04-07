#include<bits/stdc++.h>
using namespace std;
//priority_queue<int,vector<int>,greater<int> > pq;
stack<int> s;
const int N=5005;
struct Edge{
	int to,next;
}edge[N*2];
int n,m,en=0,head[N],dep[N],xl[N],b[N][N];
bool vis[N];
void addedge(int u,int v){
	edge[++en].to=v,edge[en].next=head[u],head[u]=en;
}

void init(int o){
	for(int i=head[o],v;i;i=edge[i].next){
		v=edge[i].to;
		if(dep[v]) continue;
		dep[v]=dep[o]+1;
		init(v);
	}
}

void dfs(int o){
	vis[o]=1;
	xl[++en]=o;
	int temp=0;
	for(int i=head[o];i;i=edge[i].next)
		if(dep[edge[i].to]>dep[o]) b[o][++temp]=edge[i].to;
	sort(b[o]+1,b[o]+temp+1);
	for(int i=1;i<=temp;i++)
		if(!vis[b[o][i]]) dfs(b[o][i]);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	if(m==n-1){
		dep[1]=1;
		init(1);
		en=0;
		dfs(1);
		for(int i=1;i<=n;i++){
			if(i==n) printf("%d\n",xl[i]);
			else printf("%d ",xl[i]);
		}
	}
	return 0;
}
