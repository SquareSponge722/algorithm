#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 9999999
struct node {
	int to,nxt;
} e[N*2];
int head[N],dp[N][3],n,m,x,y,a,b,tot,v[N],sz[N],d[N];
bool g[2020][2020];
void add(int x,int y) {
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}
void dfs(int u,int f) {
	sz[u]=1;
	int num1=0;
	int num0=0;
	for(int i=head[u]; i; i=e[i].nxt) {
		int to=e[i].to;
		if(to==f)
			continue;
		dfs(to,u);
		sz[u]+=sz[to];
		num1+=min(dp[to][0],dp[to][1]);
		num0+=dp[to][1];
	}
	if(sz[u]>1) {
		if(u!=a && u!=b) {
			dp[u][0]=num0;
			dp[u][1]=num1+v[u];
		} else {
			if(u==a) {
				if(x==0) {
					dp[u][0]=num0;
				} else {
					dp[u][1]=num1+v[u];
				}
			} else {
				if(y==0) {
					dp[u][0]=num0;
				} else {
					dp[u][1]=num1+v[u];
				}
			}
		}
	} else {
		if(u!=a && u!=b) {
			dp[u][1]=v[u];
			dp[u][0]=0;
		} else {
			if(u==a) {
				if(x==1)
					dp[u][1]=v[u];
				else
					dp[u][0]=0;
			} else {
				if(y==1)
					dp[u][1]=v[u];
				else
					dp[u][0]=0;
			}
		}
	}
}
int fa[N];
void dfs1(int u){
	for(int i=head[u];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==fa[u])
			continue;
		fa[to]=u;
		dfs1(to);
	}
}
char ch[10];
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,ch);
	for(int i=1; i<=n; i++)
		scanf("%d",&v[i]);
	if(n<=2000) {
		for(int i=1; i<=n-1; i++) {
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			if(n<=2000) {
				g[x][y]=g[y][x]=1;
				d[x]++;
				d[y]++;
			}
		}
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(g[a][b] && x==0 && y==0 && (d[a]==1 || d[b]==1)) {
				printf("-1\n");
				continue;
			}
			memset(dp,0x3f,sizeof(dp));
			dfs(1,0);
			printf("%d\n",min(dp[1][1],dp[1][0]));
		}
		return 0;
	}
	if(ch[0]=='A') {
		for(int i=1; i<=n-1; i++) {
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
			if(ch[0]=='A') {
				d[x]++;
				d[y]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				dfs1(i);
				break;
			}
		}
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if((fa[b]==a || fa[b]==a) && x==0 && y==0 && (d[a]==1 || d[b]==1)) {
				printf("-1\n");
				continue;
			}
			memset(dp,0x3f,sizeof(dp));
			dfs(1,0);
			printf("%d\n",min(dp[1][1],dp[1][0]));
		}
		return 0;
	}
	return 0;
}
