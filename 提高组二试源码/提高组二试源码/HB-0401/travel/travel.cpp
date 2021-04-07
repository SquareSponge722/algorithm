# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
# define N 5005
struct Edge{
	int next;
	int to;
} e[2*N];
int too[N][505];
int head[N];
int num[N];
int sum;
int path[N];
void dfs1(int x,int fa,int ans);
int n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[i]=(Edge){head[u],v};
		head[u]=i;
		e[i+m]=(Edge){head[v],u};
		head[v]=i+m;
	}
	sum++;
	path[sum]=1;
	if(m==n-1){
		dfs1(1,0,1);
		for(int i=1;i<=sum;i++){
			printf("%d ",path[i]);
		}
	}
	else if(m==n){
		
	}
	return 0;
}
void dfs1(int x,int fa,int ans){
	if(ans==n){
		return ;
	}
	for(int i=head[x];i;i=e[i].next){
		if(e[i].to!=fa){
			too[x][++num[x]]=e[i].to;
		}
	}
	sort(too[x]+1,too[x]+1+num[x]);
	for(int i=1;i<=num[x];i++){
		path[++sum]=too[x][i];
		dfs1(too[x][i],x,ans+1);
	}
	return ;
}
