#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
static char buf[100000],*pa=buf,*pd=buf;
#define gc pa==pd&&(pd=(pa=buf)+fread(buf,1,100000,stdin),pa==pd)?EOF:*pa++
inline int read(){
	register int f(1),x(0);register char c(gc);
	while(c>'9'||c<'0')f=c=='-'?-1:1,c=gc;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc;
	return f*x;
}
const int N=100000;
struct edge{
	int to;
	int next;
};
edge e[N];
int head[N],tot;
void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
int n,m,cnt[5100],fa[5100],vis[5100],son[5100][5100];
priority_queue<int,vector<int>,greater<int> > q;
void dfs(int x){
	cout<<x<<' ';
	int i;
	sort(son[x]+1,son[x]+1+cnt[x]);
	for(i=1;i<=cnt[x];i++){
		if(fa[son[x][i]]==x)dfs(son[x][i]);
	}
}
void prim(){
	q.push(1);
	fa[1]=2147483647;
	int i;
	while(!q.empty()){
		int u=q.top();q.pop();
			if(!vis[u]){
				vis[u]=1;
			for(i=head[u];i;i=e[i].next)
				{
				if(e[i].to==fa[u])continue;
				if(!fa[e[i].to]){
				fa[e[i].to]=u;
				son[u][++cnt[u]]=e[i].to;
				q.push(e[i].to);
				}
				else if(fa[e[i].to]<u&&e[i].to>u){
					fa[e[i].to]=u;
					son[u][++cnt[u]]=e[i].to;
				}
			}
		}
	}
	dfs(1);
}
void search(int x,int fa){
	cout<<x<<' ';
	int i,cnt=0;
	for(i=head[x];i;i=e[i].next){
		if(e[i].to!=fa)
			son[x][++cnt]=e[i].to;
	}
	sort(son[x]+1,son[x]+1+cnt);
	for(i=1;i<=cnt;i++)
		search(son[x][i],x);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i,x,y;
	n=read();m=read();
	for(i=1;i<=m;i++){
		x=read();y=read();
		add(x,y);
		add(y,x);
	}
	if(m==n-1)
	search(1,0);
	else 
	prim();
	return 0;
}
