#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,f,g;
int dt[maxn][maxn];
bool v[maxn];
void dfs(int o){
	printf("%d ",o);
	v[o]=1;
	for(int i=1;i<=n;i++){
		if(dt[o][i]&&!v[i]){
			dfs(i);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&f,&g);
		dt[f][g]=dt[g][f]=1;
	}
	dfs(1);
	return 0;
}
