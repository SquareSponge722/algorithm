#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define ull unsigned long long 
#define rep(k,i,j) for(int k = i;k <= j; ++k)
#define FOR(k,i,j) for(int k = i;k >= j; --k)
inline int read(){
	int x = 0,f = 1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
const int size = 5e3+5;
struct edge{int y,nxt;}e[size*2];
int len,to[size],tot;
int a[size]={};
bool v[size];
int n,m;
vector<int>d[size];
vector<int> link[size];
inline void add(int xx,int yy){
	e[++len].nxt = to[xx];
	to[xx] = len;
	e[len].y = yy;
}
void dfs(int x){
	if(tot==n) return;
//	a[++tot] = x; 
	v[x] = 1;
	int x_ = inf;
	for(int i = to[x]; i;i = e[i].nxt){
		int y = e[i].y;
		if(v[y]) continue;
		dfs(y);	
		a[++tot] = y;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	n = read(),m = read();
	scanf("%d %d",&n,&m);
	memset(v,0,sizeof(v));
	rep(i,1,size) link[i].clear();
	rep(i,1,m){
		int u,v;
//		int u = read(),v = read();
		scanf("%d %d",&u,&v);
		add(u,v),add(v,u);
	}
	tot = 0;
	dfs(1);
//	cout << tot<<endl;
	cout <<1<<" ";
	rep(i,1,tot) printf("%d ",a[tot-i+1]);
//	rep(i,tot,1) printf("%d ",a[i]);
	return 0;
}
