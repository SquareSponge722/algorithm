#include<iostream>
#include<cstdio>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=hd[u],v,w;v=e[i].v,w=e[i].w,i;i=e[i].n)
using namespace std;
const int N=100100,M=200200;
struct edge{int n,v,w;}e[M];
int n,m,ok1,ok2=1,ok3=1,u,v,w,fl,hd[N],fa[N],d[N],c[N]; 
void add(int u,int v,int w){e[++fl]=(edge){hd[u],v,w};hd[u]=fl;}
void dfs1(int u){
	REP(u)if(v!=fa[u]){
		fa[v]=u,d[v]=d[u]+1;
		c[v]=c[u]+w;dfs1(v);
	}
}
namespace task1{
	int s=1;
	void sol(){
		FOR(i,1,n) if(c[i]>c[s]) s=i;
		fa[s]=d[s]=c[s]=0;
		dfs1(s);
		FOR(i,1,n) if(c[i]>c[s]) s=i;
		printf("%d",c[s]);
	}
}//Ö±¾¶ 
namespace task2{
	int l,r,a[N]; 
	bool cmp(int x,int y){return x>y;}
	bool chk(int lim){
		int p=n+1,tmp;
		FOR(i,2,n)if(a[i]<lim) {p=i;break;}
		//cout<<lim<<' '<<p-2<<endl;
		if(p-2>=m) return 1;
		tmp=m-p+2; 
		if(n-p+1<2*tmp) return 0;
		FOR(i,p,tmp+p-1)
			if(a[i]+a[2*tmp+2*p-1-i]<lim) return 0;
		return 1;
	}
	void sol(){
		FOR(i,2,n) a[i]=c[i];
		sort(a+2,a+n+1,cmp);
		FOR(i,1,n) r=max(r,c[i]*2);
		while(l<r){
			int md=l+r+1>>1;
			chk(md)?l=md:r=md-1;
		}
		printf("%d",l);
	}
}//¾Õ»¨ 
namespace task3{
	int l,r;
	bool chk(int lim){
		int st=1,cnt=0;
		FOR(i,2,n)if(c[i]-c[st]>=lim) 
			st=i,cnt++;
		return cnt>=m;
	} 
	void sol(){
		r=c[n];
		while(l<r){
			int md=l+r+1>>1;
			chk(md)?l=md:r=md-1;
		}
		printf("%d",l);
	}
}//Á´ 
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout); 
	scanf("%d%d",&n,&m);
	ok1=m==1;
	FOR(i,2,n){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
		ok2&=u==1;
		ok3&=v==u+1; 
	} 
	dfs1(1);
	if(ok1) task1::sol();
	else if(ok2) task2::sol();
	else if(ok3) task3::sol();
}/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7

7 3
1 2 4
2 3 3
3 4 5
4 5 6
5 6 5
6 7 2
*/
