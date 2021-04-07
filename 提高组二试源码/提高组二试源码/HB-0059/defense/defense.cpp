#include<iostream>
#include<cstdio>
#include<cstring>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
#define TU(x) for(register int i=head[x];i;i=h[i].next)
using namespace std;
struct edge{
	int next,to;
}h[4005];
int n,m,tot,ans,head[2005],zhu[2005];
bool vis[2005],f;
string s;
int a[2005];
void add(int u,int v){
	h[++tot].to=v;
	h[tot].next=head[u];
	head[u]=tot;
}
void dfs(int u,bool jia){
//	cout<<u<<" "<<zhu[u]<<" "<<jia<<"\n";
	if (zhu[u]!=-1&&zhu[u]!=jia) f=1,cout<<-1<<"\n";
	else if ((zhu[u]==jia||zhu[u]==-1)&&jia==1) ans+=a[u];
	if (f) return;
	zhu[u]=jia;
	TU(u){
		if (!vis[h[i].to]){
			vis[h[i].to]=1;
			dfs(h[i].to,jia^1);
//			vis[h[i].to]=0;
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;cin>>s;
	int u,v,x,y;
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,n-1){
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	while(m--){
		cin>>u>>x>>v>>y;
		memset(zhu,-1,sizeof(zhu));memset(vis,0,sizeof(vis));
		zhu[u]=x,zhu[v]=y;f=0;ans=0;vis[u]=1;
		dfs(u,x);
		if (!f) cout<<ans<<"\n";
	}
	return 0;
}

