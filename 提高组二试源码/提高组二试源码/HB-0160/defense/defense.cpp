#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int re = 0,ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) re = (re<<1) + (re<<3) + ch -'0',ch = getchar();
	return re;
}
const int maxn = 100005;
struct edge{
	int v,nxt;
}e[maxn<<1];
int h[maxn],cnt;
void add(int u,int v){
	e[++cnt].v = v,e[cnt].nxt = h[u],h[u] = cnt;
	e[++cnt].v = u,e[cnt].nxt = h[v],h[v] = cnt;
}
int n,m,val[maxn];
char ty[3];
bool vis[maxn];
int costr,costdr,c;
void dfs(int u,int fa){
	if(vis[u]) costr += val[u];
	else costdr += val[u];
	for(int i = h[u];i;i = e[i].nxt){
		int v = e[i].v;
		if(v != fa){
			if(!vis[u]) vis[v] = 1;
			dfs(v,u);
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n = read(),m = read();
	scanf("%s",&ty);
	for(int i = 1;i <= n;i++) val[i] = read();
	for(int i = 1,u,v;i < n;i++){
		u = read(),v = read();
		add(u,v);
	}
	vis[1] = 1;
	dfs(1,0);
	//cout << costr << ' ' << costdr;
	for(int i = 1,a,x,b,y;i <= m;i++){
		a = read(),x = read(),b = read(),y = read();
		int cr = costr,cdr = costdr;
		int able1 = 1,able2 = 1;
		//root is selected
		if((vis[a] && !x) || (vis[b] && !y)) able1 = 0;
		if((!vis[a] && !x) || (!vis[b] && !y)) able2 = 0;
		if(!able1 && !able2) printf("-1\n");
		else{
			if(able1){
				if(x && !vis[a]) cr += val[a];
				if(y && !vis[a]) cr += val[b];
			}else cr = (1<<31)-1;
			if(able2){
				if(x && vis[a]) cdr += val[a];
				if(y && vis[a]) cdr += val[b];
			}else cdr = (1<<31)-1;
			printf("%d\n",min(cr,cdr));
		}
	}
	return 0;
}
