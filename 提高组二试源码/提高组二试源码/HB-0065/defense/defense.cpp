#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N 100010
#define inf 0x7f7f7f7f
using namespace std;
int n,m,ans;
map <pair<int,int>,bool> p;
int c[N],d[N],vis[N],v[N];
char s[3];
struct rec{
	int x,y;
}e[N];
int dfs(int i,int now){
	if(i==n) return 0;
	if(v[e[i].x]==0){
		now=c[e[i].y];
		vis[e[i].y]=1;
		now+=dfs(i+1,inf);
		vis[e[i].y]=0;
		return now;
	}
	if(v[e[i].y==0]){
		now=c[e[i].x];
		vis[e[i].x]=1;
		now+=dfs(i+1,inf);
		vis[e[i].x]=0;
		return now;
	}
	if(v[e[i].x]==1){
		now=c[e[i].x];
		vis[e[i].x]=1;
		now+=dfs(i+1,inf);
		vis[e[i].x]=0;
		return now;
	}
	if(v[e[i].y]==1){
		now=c[e[i].y];
		vis[e[i].y]=1;
		now+=dfs(i+1,inf);
		vis[e[i].y]=0;
		return now;
	}
	if(!vis[e[i].x] && !vis[e[i].y]){
		vis[e[i].x]=1;
		now=min(now,c[e[i].x]+dfs(i+1,inf));
		vis[e[i].x]=0;
		vis[e[i].y]=1;
		now=min(now,c[e[i].y]+dfs(i+1,inf));
		return now;
	}
	if((vis[e[i].x] && v[e[i].x]==inf) || (vis[e[i].y] && v[e[i].y]==inf)){
		return 0+dfs(i+1,inf);
	}
	if(v[e[i].x]==0){
		now=c[e[i].y];
		vis[e[i].y]=1;
		now+=dfs(i+1,inf);
		vis[e[i].y]=0;
		return now;
	}
	if(v[e[i].y==0]){
		now=c[e[i].x];
		vis[e[i].x]=1;
		now+=dfs(i+1,inf);
		vis[e[i].x]=0;
		return now;
	}
	if(v[e[i].x]==1){
		now=c[e[i].x];
		vis[e[i].x]=1;
		now+=dfs(i+1,inf);
		vis[e[i].x]=0;
		return now;
	}
	if(v[e[i].y]==1){
		now=c[e[i].y];
		vis[e[i].y]=1;
		now+=dfs(i+1,inf);
		vis[e[i].y]=0;
		return now;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&e[i].x,&e[i].y);
		p[make_pair(e[i].x,e[i].y)]=true;
	}
	for(int i=1;i<=m;i++){
		int x,y,a,b;
		scanf("%d %d %d %d",&a,&x,&b,&y);
		memset(vis,0,sizeof(vis));
		memset(v,inf,sizeof(v));
		v[a]=x;
		v[b]=y;
		if((s[2]=='2' || p[make_pair(a,b)]) && x==0 && y==0){
			printf("-1\n");
			continue;
		}
		ans=0;
		ans=dfs(1,inf);
		printf("%d\n",ans);
	}
	return 0;
}
