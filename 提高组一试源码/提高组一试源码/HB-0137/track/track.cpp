#include<cstdio>
#include<iostream>
#include<algorithm>
//#include<ctime>
using namespace std;
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ymd(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxn=50005,inf=0x7fffffff;
struct edge{
	int u,v,w,next;
}e[maxn<<1];
int cnt=0,head[maxn],maxx,maxl=0,n,m;
bool vis[maxn];
void add(int u,int v,int w){
	e[++cnt].u=u;e[cnt].v=v;e[cnt].w=w;e[cnt].next=head[u];head[u]=cnt;
}
void dfs(int x,int len){
	if(len>maxl){
		maxx=x,maxl=len;
	}
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v,w=e[i].w;
		if(!vis[v]){
			vis[v]=1;
			dfs(v,len+w);
			vis[v]=0;
		}
	}
}
void solve1(){
	vis[1]=1;
	dfs(1,0);
	vis[1]=0;
	dfs(maxx,0);
	printf("%d\n",maxl);
	return ;
}
void solve2(){
	
}
bool cmp(edge e1,edge e2){
	return e1.w>e2.w;
}
void solve3(){//ai=1 
	sort(e+1,e+cnt+1,cmp);
	printf("%d\n",e[m*2-1].w);
}
int qzh[maxn];
int f[1005][1005];
int solve4(int i,int j){//bi=ai+1 i~n·Ö³Éj·Ý 
	if(j==1)return f[i][j]=qzh[cnt]-qzh[i-1];
//printf("%d %d \n",i,j);
	if(f[i][j])return f[i][j];
//	if(cnt-i+1==j)return f[i][j]=qzh[cnt]-qzh[i-1];
	int _max=0;
	FOR(k,i,cnt-j+2) {
//		f[i][j]
		_max=max(_max,min(qzh[k]-qzh[i-1],solve4(k+1,j-1)));
	}
	return f[i][j]=_max;
}
void Zack(){
	int u,v,w;
	bool flag1=1,flag2=1;
	n=read(),m=read();
	FOR(i,2,n){
		u=read(),v=read(),w=read();
		if(flag1&&u!=1)flag1=0;
		if(flag2&&v!=u+1)cout<<v<<endl,flag2=0;
		add(u,v,w),add(v,u,w);
	}
//	cout<<flag2<<endl;
	if(m==1)solve1();
//	else if(n<=15){
//		solve2();
//	}
	else if(flag1){
		solve3();
	}
	else if(flag2){
//		printf("yeah\n");
		cnt/=2;
		for(int i=1;i<=cnt;i++)qzh[i]=e[i*2-1].w+qzh[i-1];
//		FOR(i,1,cnt)printf("%d ",qzh[i]);
		printf("%d\n",solve4(1,m));
	}
	else solve3();
//	cout<<"mmm"<<endl;
	return ;
}
int main(){
//	int st=clock();
	ymd("track");
	Zack();
//	cout<<"time "<<clock()-st<<endl;
	return 0;
}
