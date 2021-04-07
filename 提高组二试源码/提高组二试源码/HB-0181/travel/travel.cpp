#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5005;
int n,m,cnt=0,head[maxn];
bool vis[maxn],g[maxn][maxn];
struct edge{
	int nxt,to;
}e[maxn<<1];
void add(int u,int v){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int now){
	printf("%d%c",u,now==n?'\n':' ');
	vis[u]=true;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!vis[v])
			dfs(v,now+1);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(g[i][j]){
				add(i,j);
			}
		}
	}
	dfs(1,1);
	return 0;
}
