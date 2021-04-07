#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
#define ymd(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxn=5005,maxm=5005;
int n,m,pr[maxn];
bool vis[maxn],f[maxn][maxn];
/*
struct edge {
	int u,v,next;
} e[maxm<<1];
int cnt=0,n,m,head[maxn],pr[maxn];
void add(int u,int v) {
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}*/
/*
void bfs() {
	priority_queue<int>Q;
	Q.push(-1);
	while(!Q.empty()) {
		int fr=-Q.top();
		vis[fr]=1;
		Q.pop();
		printf("%d ",fr);
		FOR(i,1,n)if(f[fr][i]&&!vis[i])Q.push(-i);
	}
	return ;
}
//*/
int sum=0;
void dfs(int u) {
//if(sum<=10)	printf("%d %d\n",u,sum);
	pr[++sum]=u;
	vis[u]=1;
	if(sum==n) {
		FOR(i,1,n)printf("%d ",pr[i]);
		return ;
	}

	FOR(i,1,n){
		if(f[u][i]&&!vis[i])
			dfs(i);
//		break ;
	}
//	for(int i=head[u]; i; i=e[i].next)
	

//	int maxv=maxn;
//	for(int i=head[u]; i; i=e[i].next) {
//		int v=e[i].v;
////		if(!vis[v])bian[num++]=v;
//		maxv=min(maxv,v);
//	}
//	if(maxv==maxn)return ;
//	dfs(maxv);
//		*/
}
void Zack() {
	n=read(),m=read();
	int u,v;
	FOR(i,1,m) {
		u=read(),v=read();
		f[u][v]=f[v][u]=1;
	}
	dfs(1);
//	f[huan][lian]
//	bfs();
	return ;
}
int main() {
	ymd("travel");
	Zack();
	return 0;
}
