#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int re = 0,ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) re = (re<<1) + (re<<3) + ch - '0',ch = getchar();
	return re;
}
const int maxn = 5005;
int n,m;
vector<int> g[maxn];
void dfs(int u,int fa){
	printf("%d ",u);
	sort(g[u].begin(),g[u].end());
	for(int i = 0;i < g[u].size();i++){
		int v = g[u][i];
		if(v != fa) dfs(v,u);
	}
}
struct edge{
	int u,v;
}e[maxn];
int ans[maxn],cnt,ansreal[maxn];
int disu,disv;
bool better,flag,vis[maxn],worse;
void able(int u,int fa){
	if(vis[u]) flag = 1;
	else vis[u] = 1,cnt++;
	if(flag) return;
	for(int i = 0;i < g[u].size();i++){
		int v = g[u][i];
		if((u == disu && v == disv) || (u == disv && v == disu)) continue;
		if(v != fa) able(v,u);
	}
}
void dfs2(int u,int fa){
	cnt++;
	ans[cnt] = u;
	if(!better && !worse){
		if(ansreal[cnt] < ans[cnt]) worse = 1;
		else if(ansreal[cnt] > ans[cnt]) better = 1;
	}
	if(worse) return;
	sort(g[u].begin(),g[u].end());
	for(int i = 0;i < g[u].size();i++){
		int v = g[u][i];
		if((u == disu && v == disv) || (u == disv && v == disu)) continue;
		if(v != fa) dfs2(v,u);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read(),m = read();
	for(int i = 1,u,v;i <= m;i++){
		u = read(),v = read();
		e[i].u = u,e[i].v = v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(m == n - 1) dfs(1,0);
	else{
		memset(ans,0x3f,sizeof(ans));
		memset(ansreal,0x3f,sizeof(ans));
		for(int i = 1;i <= m;i++){
			memset(vis,0,sizeof(vis));
			disu = e[i].u,disv = e[i].v;
			cnt = 0;
			flag = 0;
			able(1,0);
			if(cnt != n || flag) continue;
			better = 0;
			worse = 0;
			cnt = 0;
			dfs2(1,0);
			if(!worse) memcpy(ansreal,ans,sizeof(ans));
		}
		for(int i = 1;i <= n;i++)
			printf("%d ",ansreal[i]);
	}
	return 0;
}
