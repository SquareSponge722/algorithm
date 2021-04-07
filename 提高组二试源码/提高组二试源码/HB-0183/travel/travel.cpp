#include<bits/stdc++.h>
#define N 5005
#define inf 0x3fffffff
using namespace std;
int n,m,minn[N];
bool f[N][N],vis[N],cnt;
void dfs(int s){	
	printf("%d ",s);
	vis[s] = true;
	for(int i=1;i<=n;i++){		
		if(f[s][i]!=false&&vis[i]!=true){
			dfs(i);			
		}		
	}
//	vis[s] = false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		f[u][v] = f[v][u] = true;
	}
	vis[1] = true;
	dfs(1);
	puts("");
	return 0;
}
