#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5005;
int h[N],n,m,cnt,dfn[N],a[N],loop[N],tot;
int sum,flag,lp[N];
struct edge{
	int to,nex;
}e[N<<1];
bool vis[N],ok,dlt[N<<1],found;
vector<int> b[N];

void add(const int &u,const int &v){
	e[++cnt].to=v;e[cnt].nex=h[u];h[u]=cnt;
}

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	int cur=0;
	dfn[++tot]=u;
	for(int i=h[u];i;i=e[i].nex){
		if(dlt[i]) continue;
		int v=e[i].to;
		if(!vis[v]) a[++cur]=v;
	}
	if(!cur) return;
	sort(a+1,a+cur+1);
	for(int i=1;i<=cur;i++) b[u].push_back(i);
	for(int i=0;i<cur;i++){
		dfs(b[u][i]);
	}
	
}

void fd(int u){
	if(found) return;
	if(vis[u]){
		lp[++sum]=u;
		ok=1;
		return;
	}
	vis[u]=1;
	for(int i=h[u],v;i;i=e[i].nex){
		if(dlt[i]) continue;
		v=e[i].to;
		for(int j=h[v];j;j=e[j].nex)
			if(e[j].to==u){
				dlt[j]=1;break;
			}
		fd(v);
		if(found) return;
		if(ok&&lp[1]!=u){
			lp[++sum]=u;
			return;
		}
		if(ok&&lp[1]==u){
			ok=0;
			found=1;
			return;
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	if(n==m+1){
		dfs(1);
		for(int i=1;i<=tot;i++)
			printf("%d ",dfn[i]);
	}
	if(n==m){
		fd(1);
		sort(lp+1,lp+sum+1);
		int u=lp[sum-1],v=lp[sum];
		int a,c;
		for(a=h[u];a;a=e[a].nex)
			if(e[a].to==v){
				dlt[a]=1;
				break;
			}
		for(c=h[v];c;c=e[c].nex)
			if(e[c].to==u){
				dlt[c]=1;
				break;
			}
		for(int i=1;i<=n;i++) b[i].clear();
		memset(vis,0,sizeof vis);
		dfs(1);
		for(int i=1;i<=n;i++)
			printf("%d ",dfn[i]);
	}
	return 0;
} 
