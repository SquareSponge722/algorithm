#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
char buff[100010],*PA(buff),*PB(buff);
#define gc PA==PB&&(PA=buff,PB=fread(buff,1,100000,stdin)+buff,PA==PB)?EOF:*PA++
#define REP(i,u,v) for(int i=h[u],v;v=e[i].t,e[i].s==u&&!falg;i++)
using namespace std;
const int N=5010,INF=0x7fffffff;
int getint(){
	char ch_=gc;
	int s_=0,f_=1;
	while(ch_<'0'||ch_>'9'){
		if(ch_=='-')f_=-1;
		else f_=1;
		ch_=gc;
	}
	while(ch_>='0'&&ch_<='9')
		s_=s_*10+ch_-48,ch_=gc;
	return s_*f_;
}
int n,m,tot,dfn;
int h[N],ans[N],vis[N],now[N];
bool go[N][N];
bool flag,falg;
struct edge{
	int s,t;
}e[N<<1];
bool cmp(edge x,edge y){
	return x.s!=y.s?x.s<y.s:x.t<y.t;
}
void add_edge(){
	int x,y;
	x=getint();y=getint();
	e[++tot]=(edge){x,y};
	e[++tot]=(edge){y,x};
	go[x][y]=go[y][x]=true;
}
void input(){
	n=getint();m=getint();
	for(int i=1;i<=m;i++)
		add_edge();
}
void DFS(int u){
	if(vis[u]==dfn)return;
	else vis[u]=dfn;
	ans[++tot]=u;
	REP(i,u,v)DFS(v);
}
void init(){
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++)
		if(e[i].s!=e[i-1].s)
			h[e[i].s]=i;
	tot=0,dfn++;
	DFS(1);
}
void output(){
	printf("%d",ans[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",ans[i]);
}
void dfs(int u){
	if(vis[u]==dfn)return;
	else vis[u]=dfn;
	tot++;
	if(flag){
		if(ans[tot]>u)now[tot]=u,flag=false;
		else if(ans[tot]==u)now[tot]=u;
		else if(ans[tot]<u)falg=true;
	}
	else now[tot]=u;
	if(falg)return;
	REP(i,u,v)
		if(go[u][v])
			dfs(v);
}
void work(){
	if(m==n)
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(go[i][j]){
					flag=true,falg=false;
					go[i][j]=go[j][i]=false;
					tot=0,dfn++;
					dfs(1);
					if(!flag&&tot==n)
						for(int k=1;k<=n;k++)
							ans[k]=now[k];
					go[i][j]=go[j][i]=true;
				}
	output();
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	input();
	init();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
