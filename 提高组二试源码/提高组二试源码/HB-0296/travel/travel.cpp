#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,M[5050][5050];
bool b[5050];
void dfs(int o) {
	printf("%d ",o);
	b[o]=1;
	for(int i=1; i<=M[o][0]; i++)
		if(!b[M[o][i]])dfs(M[o][i]);
	return;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		M[x][0]++;
		M[x][M[x][0]]=y;
		M[y][0]++;
		M[y][M[y][0]]=x;
	}
	for(int i=1; i<=n; i++)sort(M[i]+1,M[i]+M[i][0]+1);
	dfs(1);
	return 0;
}
