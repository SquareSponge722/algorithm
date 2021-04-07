#include<iostream>
#include<cstdio>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=hd[u],v;v=e[i].v,i;i=e[i].n)
using namespace std;
const int N=5050,M=200200;
struct edge{int n,v;}e[M];
struct EDGE{
	int x,y;
	bool operator < (const EDGE P)const{return y>P.y;}
}E[M];
int n,m,u,v,cc,fl,ti,ok,tp,in[N],vi[N][N],fa[N],b[N][N];
int hd[N],ans[N],a[N],s[N],df[N],lo[N];
void add(int u,int v){e[++fl]=(edge){hd[u],v};hd[u]=fl;}
void dfs(int u){
	a[++cc]=u;
	REP(u)if(b[u][v]==0 && v!=fa[u])
		fa[v]=u,dfs(v);
}
void work1(){
	cc=0,ok=0;
	FOR(i,1,n) fa[i]=0;
	dfs(1);
	FOR(i,1,n) if(a[i]!=ans[i]){ok=a[i]<ans[i];break;}
	if(ok) FOR(i,1,n) ans[i]=a[i];
}
void tarjan(int u,int dad){
	df[u]=lo[u]=++ti;
	s[++tp]=u;
	int bg=tp;
	REP(u)if(v!=dad){
		if(!df[v]){
			tarjan(v,u);
			lo[u]=min(lo[u],lo[v]);
		}
		else lo[u]=min(lo[u],df[v]);
	}
	if(lo[u]>df[dad]){
		if(tp-bg>0){
			FOR(i,bg,tp) in[s[i]]=1;
		}
		tp=bg-1;
	}
}
void work2(){
	tarjan(1,0);
	FOR(i,1,2*m){
		if(in[E[i].x] && in[E[i].y]){
			if(!vi[E[i].x][E[i].y]){
				b[E[i].x][E[i].y]=b[E[i].y][E[i].x]=1;
				vi[E[i].x][E[i].y]=vi[E[i].y][E[i].x]=1;
				work1();
				b[E[i].x][E[i].y]=b[E[i].y][E[i].x]=0;
			}
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	FOR(i,1,m) scanf("%d%d",&E[i].x,&E[i].y);
	FOR(i,1,m) E[i+m].x=E[i].y,E[i+m].y=E[i].x;
	sort(E+1,E+m*2+1);
	FOR(i,1,2*m) add(E[i].x,E[i].y);
	FOR(i,1,n) ans[i]=n-i+1;
	if(m==n-1) work1();
	else work2();
	FOR(i,1,n) printf("%d ",ans[i]);
}
