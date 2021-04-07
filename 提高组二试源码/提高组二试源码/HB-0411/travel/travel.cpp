#include <bits/stdc++.h>
using namespace std;
#define N 5010
int n,m,x,y,a[N][N],ans[N],b[N],tot;
struct node{
	int x,y;
}e[N];
void dfs1(int u,int f){
	ans[++tot]=u;
	for(int i=1;i<=a[u][0];i++){
		int to=a[u][i];
		if(to!=f)
			dfs1(to,u);
	}
}
bool vis[N];
void dfs2(int u,int f){
	b[++tot]=u;
	vis[u]=true;
	for(int i=1;i<=a[u][0];i++){
		int to=a[u][i];
		if(to==f || (to==x && u==y) || (to==y && u==x))
			continue;
		if(vis[to])
			continue;
		dfs2(to,u);
	}
}
bool cmp(){
	if(tot!=n)
		return true;
	if(ans[1]==0)
		return false;
	
	for(int i=1;i<=n;i++){
		if(ans[i]<b[i])
			return true;
		if(ans[i]>b[i])
			return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[i].x=x;
		e[i].y=y;
		a[y][++a[y][0]]=x;
		a[x][++a[x][0]]=y;
	}
	for(int i=1;i<=n;i++)
		sort(a[i]+1,a[i]+1+a[i][0]);
	if(m==n-1){
		dfs1(1,0);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	else{
		for(int i=1;i<=m;i++){
			tot=0;
			memset(vis,0,sizeof(vis));
			x=e[i].x;
			y=e[i].y;
			dfs2(1,0);
			if(!cmp())
				memcpy(ans,b,sizeof(b));
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	return 0;
}

