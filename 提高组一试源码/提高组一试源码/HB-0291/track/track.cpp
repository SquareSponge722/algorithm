#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define rep(k,i,j) for(int k = i;k <= j; ++k)
#define FOR(k,i,j) for(int k = i;k >= j; --k)
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
const int size = 3e4+5;
int n,m,p,q,maxx;
struct edge{int nxt,y,v;}e[size*2];
int d[size],dist[size];
bool v[size];
int to[size],len;
inline void add(int xx,int yy,int vv){
	e[++len].nxt = to[xx];
	to[xx] = len;
	e[len].y = yy;
	e[len].v = vv;
}
inline void dfs1(int x){
	v[x] = 1;
	for(int i = to[x]; i;i = e[i].nxt){
		int y = e[i].y,z = e[i].v;
		if(v[y]) continue;
		d[y] = d[x]+1;
		dist[y] = dist[x]+z;
		dfs1(y);
	}
}
/*
inline void dp(int x){
	v[x] = 1;
	for(int i = to[x]; i;i = e[i].nxt){
		int y = e[i].y,z = e[i].v;
		if(v[y]) continue;
		minx = min(minx,z);
		dist[y] = min(dist[y],dist[x]+minx);		
		dp(y);
	}
}
*/
void work(){
	memset(d,0x3f,sizeof(d));
	memset(dist,0x3f,sizeof(dist));
	memset(v,0,sizeof(v));
	d[1] = 0;
	dfs1(1);
	maxx = -inf;
	rep(i,1,n){
		if(d[i]<inf&&(d[i]>maxx||d[i]==maxx&&dist[i]>dist[p]))
			maxx = d[i],p = i;
	}//距离点1最远的点 
//	printf("%d %d\n",maxx,p);
//	rep(i,1,n) printf("%d ",d[i]);
	
	memset(d,0x3f,sizeof(d));
	memset(dist,0x3f,sizeof(dist));	
	memset(v,0,sizeof(v));
	d[p] = 0,dist[p] = 0;
	dfs1(p);
	maxx = -inf;
	rep(i,1,n){
		if(d[i]<inf&&(d[i]>maxx||d[i]==maxx&&dist[i]>dist[q]))
			maxx = d[i],q = i;
	}
//	printf("%d %d\n",maxx,q);
//	rep(i,1,n) printf("%d ",d[i]);
	
	printf("%d\n",dist[q]);
}
void init(){
	n = read(),m = read();
	rep(i,1,n-1){
		int a,b,l;
		a = read(),b = read(),l = read();
		add(a,b,l),add(b,a,l);
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	init();
	work();
	return 0;
} 
