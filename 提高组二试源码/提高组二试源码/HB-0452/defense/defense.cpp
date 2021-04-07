#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100005,oo=0x3fffffff;
ll n,m,p[N],en,f[N][2],a,b,x,y;
int h[N];
char s[5];
bool vis[N];

struct Edge{
	int to,next;
}e[N];

void add(int u,int v){
	e[++en].to=v;
	e[en].next=h[u];
	h[u]=en;
	e[++en].to=u;
	e[en].next=h[v];
	h[v]=en;
}

void dfs(int u){
	vis[u]=1;
	f[u][0]=0;
	f[u][1]=p[u];
	if(u==a&&x==1) f[u][0]=-1;
	if(u==a&&x==0) f[u][1]=-1;
	if(u==b&&y==1) f[u][0]=-1;
	if(u==b&&y==0) f[u][1]=-1;
	for(int k=h[u];k!=0;k=e[k].next){
		if(!vis[e[k].to]){
			dfs(e[k].to);
			if(f[e[k].to][0]!=-1&&f[u][1]!=-1){
				f[u][1]+=f[e[k].to][0];
			}
			if(f[e[k].to][1]!=-1&&f[u][0]!=-1){
				f[u][0]+=f[e[k].to][1];
			}
			if(f[e[k].to][1]==-1){
				f[u][0]=-1;
			}
		}
	}
	vis[u]=0;
}



void solve(){
	fill(f[0],f[0]+2*N,oo);
	add(0,1);
	bool bj=0;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
		if(x==0&&y==0)
		for(int k=h[a];k!=0;k=e[k].next){
			if(e[k].to==b){
				printf("-1\n");
				bj=1;
				break;
			}
		}
		if(!bj){
			dfs(0);
			if(f[0][1]<=0){
				printf("%lld\n",f[0][0]);
			}
			else if(f[0][0]<=0){
				printf("%lld\n",f[0][1]);
			}
			else{
				printf("%lld\n",min(f[0][1],f[0][0]));
			}
		}
		bj=0;
	}
	
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",p+i);
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v);
	}
		solve();
	return 0;
}
