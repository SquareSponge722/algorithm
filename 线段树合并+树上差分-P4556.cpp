#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int M = 6e6 + 5;
const int K = 18;

struct tree{
	int num,cnt;
	int ls,rs;
}tre[M];

int n,m;
int x[N],y[N],z[N];

int tot,rmax;
int dep[N],fa[N][K],root[N];
int ans[N];
vector <int> path[N];

void dfs(int,int);
int Lca(int,int);
void add(int&,int,int,int,int);
void merge(int&,int,int,int);
void dfsFin(int,int);

inline void upp(int id){
	if(tre[tre[id].ls].cnt >= tre[tre[id].rs].cnt){
		tre[id].cnt = tre[tre[id].ls].cnt;
		tre[id].num = tre[tre[id].ls].num;
	}else{
		tre[id].cnt = tre[tre[id].rs].cnt;
		tre[id].num = tre[tre[id].rs].num;
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i = 1;i < n;i++){
		scanf("%d %d",&u,&v);
		path[u].push_back(v);
		path[v].push_back(u);
	}

	dfs(1,0);

	for(int i = 0;i < m;i++){
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		rmax = max(rmax,z[i]);
	}

	for(int i = 0;i < m;i++){
		int lca = Lca(x[i],y[i]);
		add(root[x[i]],1,rmax,z[i],1);
		add(root[y[i]],1,rmax,z[i],1);
		add(root[lca],1,rmax,z[i],-1);
		if(fa[lca][0]) add(root[fa[lca][0]],1,rmax,z[i],-1);
	}

	dfsFin(1,0);

	for(int i = 1;i <= n;i++) printf("%d\n",ans[i]);

	return 0;
}
void dfs(int cur,int fat){
	fa[cur][0] = fat;
	dep[cur] = dep[fat] + 1;

	for(int i = 1;i < K;i++){
		fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
		if(!fa[cur][i]) break;
	}

	int size = path[cur].size();
	for(int i = 0;i < size;i++){
		if(path[cur][i] == fat) continue;
		dfs(path[cur][i],cur);
	}
}
int Lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	for(int i = K - 1;i >= 0;i--)
		if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if(u == v) return u;
	for(int i = K - 1;i >= 0;i--)
		if(fa[u][i] != fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}
void add(int& id,int l,int r,int pos,int val){
	if(!id) id = ++tot;
	if(l == r){
		tre[id].cnt += val;
		tre[id].num = pos;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) add(tre[id].ls,l,mid,pos,val);
	else add(tre[id].rs,mid + 1,r,pos,val);
	upp(id);
}
void merge(int& id,int idMer,int l,int r){
	if(!id){
		id = idMer;
		return ;
	}
	if(!idMer) return ;
	if(l == r){
		tre[id].cnt += tre[idMer].cnt;
		return ;
	}
	int mid = (l + r) >> 1;
	merge(tre[id].ls,tre[idMer].ls,l,mid);
	merge(tre[id].rs,tre[idMer].rs,mid + 1,r);
	upp(id);
}
void dfsFin(int cur,int fat){
	int size = path[cur].size();
	for(int i = 0;i < size;i++){
		int son = path[cur][i];
		if(son == fat) continue;
		dfsFin(son,cur);
		merge(root[cur],root[son],1,rmax);
	}
	if(tre[root[cur]].cnt) ans[cur] = tre[root[cur]].num;
}
