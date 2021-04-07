#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 100005
using namespace std;
int n,m,h[N],cnt,a,b,x,y,col[N],p[N];
long long tot[3];
char c[10];
struct edge{
	int to,nex;
}e[N<<1];
int erfen=1;

void add(const int &u,const int &v){
	e[++cnt].to=v;e[cnt].nex=h[u];h[u]=cnt;
}

void dfs(int u,int color){
	if(col[u]==color)
	if(col[u]==(3-color)){
		erfen=0;
		return;
	}
	col[u]=color;
	tot[color]+=(long long)p[u];
	for(int i=h[u],v;i;i=e[i].nex){
		v=e[i].to;
		if(col[v]==0)	dfs(v,3-color);
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,2);
	if(erfen){
		for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		x++;y++;
		if(x!=col[a]&&y!=col[b]) printf("%d\n",tot[1]);
		else if(x==col[a]&&y==col[b]) printf("%d\n",tot[2]);
		else if(x!=col[a]&&y==col[b]) puts("-1");
		else if(x==col[a]&&y!=col[b]) puts("-1");
		}
	}
	
	return 0;
}
