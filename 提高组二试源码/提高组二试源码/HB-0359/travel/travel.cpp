#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=5005;
struct Edge{
	int to,next;
}edge[N*2];
int head[N],n,m,cnt;



namespace ONE{
	int g[1001][1001];
	int ret[1001]={0};
	
	bool cmp(int a,int b){
		return a<b;
		}
		
	void dfs(int x,int y){
		printf("%d ",x);
		if(ret[x]==1&&x!=1){
			return ;
		}
		for(int i=1;i<=ret[x];i++){
			if(g[x][i]!=y) dfs(g[x][i],x);
			else continue;
		}
		return ;
	}
	
	int main(){
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			g[u][++ret[u]]=v;
			g[v][++ret[v]]=u;
		}
		int ree=1;
		for(int i=1;i<=n;i++)
			sort(g[i]+1,g[i]+ret[i]+1,cmp);
		dfs(1,0);
		return 0;
	}
}

namespace TWO{
	int g[5005][5005];
	int ret[5005]={0};
	
	bool cmp(int a,int b){
		return a<b;
		}
		
	void dfs(int x,int y){
		printf("%d ",x);
		if(ret[x]==1&&x!=1){
			return ;
		}
		for(int i=1;i<=ret[x];i++){
			if(g[x][i]!=y) dfs(g[x][i],x);
			else continue;
		}
		return ;
	}
	
	int main(){
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&u,&v);
			g[u][++ret[u]]=v;
			g[v][++ret[v]]=u;
		}
		for(int i=1;i<=n;i++)
			sort(g[i]+1,g[i]+ret[i]+1,cmp);
		dfs(1,0);
		return 0;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
		if(n<=1000)return ONE::main();
		else return TWO::main();
}

