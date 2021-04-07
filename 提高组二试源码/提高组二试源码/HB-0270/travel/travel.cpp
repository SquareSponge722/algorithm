#include<bits/stdc++.h>
using namespace std;

int n,m;
int vis[5005],a[5005][5005];

//void solve(int n) {
//	for (int i=1;i<=n;i++) {
//		if (!vis[i]) {
//			for (int j=1;j<=n;j++) {
//				if (a[i][j]) printf("%d",j);
//				solve()
//				vis[j] = 1;
//			}
//		}
//	}
//	
//}

void dfs(int x) {
	for (int i=1;i<=n;i++) {
		if (!vis[i]) {
			if (a[x][i]) {
				printf("%d ",i);
				vis[i] = 1;
				dfs(i);
			}
			else continue;
		}
	}
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	fill(vis+1,vis+n+1,0);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++) {
		scanf("%d%d",&u,&v);
		a[u][v] = 1;
		a[v][u] = 1;
	}
//	for (int i=2;i<=n;i++) vis[i] = 0;
	vis[1] = 1;
//	solve(n);
	printf("1 ");
	dfs(1);
	return 0;
}
