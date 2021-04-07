#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

inline int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

struct node{
	int to,next,w;
}edge[50005];
int head[50005],cnt;

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m;
int dis[50005];
bool vis[50005];

bool cmp(int xx,int yy){
	return xx > yy;
}

int ans = 0;
int dfs(int u,int cnt){
	vis[u] = 1;
	ans = max(ans,cnt);
	for(ri i = head[u];i;i = edge[i].next)
		if(!vis[edge[i].to])
			dfs(edge[i].to,cnt + edge[i].w);
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read(),m = read();
	int cnt = 0;
	int uu,vv,ww;
	for(ri i = 1;i < n;++ i){
		uu = read(),vv = read(),ww = read();
		add(uu,vv,ww);
		add(vv,uu,ww);
		if(uu == 1)
			cnt ++;
		dis[i] = ww;
	}
	
	if( cnt == (n-1) ){
		sort(dis+1,dis+n,cmp);
		printf("%d\n",dis[m]);
	}
	else if(m == 1){
		for(ri i = 1;i <= n;i ++){
			memset(vis,0,sizeof(vis));
			dfs(i,0);
		}
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
