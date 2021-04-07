#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cctype>
typedef long long LL;
using namespace std;
const int N=100005;
const LL INF=(LL)1<<40;
void rd(int &x){
	char cc=getchar();x=0;
	while(!isdigit(cc))cc=getchar();
	while(isdigit(cc)){x=(x<<3)+(x<<1)+cc-'0';cc=getchar();}
}
struct edge{
	int v,nt;
}e[N<<1];
int h[N],cnt=0;
inline void add(int u,int v){
	e[++cnt].v=v;e[cnt].nt=h[u];h[u]=cnt;
	e[++cnt].v=u;e[cnt].nt=h[v];h[v]=cnt;
}
int a,b,n,m,x,y;
char op[5];
int ji[N],fa[N],p[N],dep[N];
void pre_dfs(int u){
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].v;if(v==fa[u])continue;
		fa[v]=u;dep[v]=dep[u]+1;pre_dfs(v);
	}
}
map<pair<int ,int > ,int > mp;
int vis[N]; //vis[u]=1(1);vis[u]=2(0);
LL ans=0,f[N][2],sp1[N],sp2[N];

void dfs1(int u){
	int op1=0;  //op1 exit vis[v]=2;
	f[u][0]=f[u][1]=INF;
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].v;if(v==fa[u])continue;
		dfs1(v);
		if(vis[v]==2)op1=1;
		sp1[u]+=f[v][1];
		sp2[u]+=min(f[v][0],f[v][1]);
	}
	f[u][0]=sp1[u];
	f[u][1]=p[u]+sp2[u];
	if(vis[u]==1)f[u][0]=INF;
	if(vis[u]==2)f[u][1]=INF;
	if(op1)f[u][0]=INF;
}
int tu,_vis[N];
LL _f[N][2],_sp1[N],_sp2[N];
void dfs2(int u,int tag){
	if(dep[u]>dep[tu]&&!tag){
		_f[u][0]=f[u][0];_f[u][1]=f[u][1];
		return ;
	}
	int op1=0;  //op1 exit vis[v]=2;
	_f[u][0]=_f[u][1]=INF;_sp1[u]=_sp2[u]=0;
	if(!tag&&u==tu)tag=1;
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].v;if(v==fa[u])continue;
		dfs2(v,tag);
		if(vis[v]==2)op1=1;
		_sp1[u]+=_f[v][1];
		_sp2[u]+=min(_f[v][0],_f[v][1]);
	}
	_f[u][0]=_sp1[u];
	_f[u][1]=p[u]+_sp2[u];
	if(_vis[u]==1)_f[u][0]=INF;
	if(_vis[u]==2)_f[u][1]=INF;
	if(op1)_f[u][0]=INF;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",op);
	
	for(int i=1;i<=n;i++){
		//scanf("%d",&p[i]);
		rd(p[i]);
	}
	for(int i=1;i<n;i++){
		//scanf("%d%d",&x,&y);
		rd(x);rd(y);
		add(x,y);
		mp[make_pair(x,y)]=mp[make_pair(y,x)]=1;
	}
	pre_dfs(1);
	
	
	
	if(m<=2000){
		
		for(int i=1;i<=m;i++){
			memset(f,0,sizeof(f));memset(sp1,0,sizeof(sp1));memset(sp2,0,sizeof(sp2));
			memset(vis,0,sizeof(vis));
			//scanf("%d%d%d%d",&a,&x,&b,&y);
			rd(a);rd(x);rd(b);rd(y);
			if(mp[make_pair(a,b)]&&!x&&!y){printf("-1\n");continue;}
			if(x)vis[a]=1;else vis[a]=2;
			if(y)vis[b]=1;else vis[b]=2;
			fa[1]=0;
			dfs1(1);
			if(vis[1]==1)ans=f[1][1];else if(vis[1]==2)ans=f[1][0];
			else ans=min(f[1][1],f[1][0]);
			printf("%lld\n",ans);
		}
		return 0;
	}
	else{
	
		if(op[1]=='1'){
			int lb;
			vis[1]=1;dfs1(1);
			for(int i=1;i<=m;i++){
				//memset(_f,0,sizeof(_f));
				//memset(_sp1,0,sizeof(_sp1));
				//memset(_sp2,0,sizeof(_sp2));
				//scanf("%d%d%d%d",&a,&x,&b,&y);
				rd(a);rd(x);rd(b);rd(y);
				//if(mp[make_pair(a,b)]&&!x&&!y){printf("-1\n");continue;}
				_vis[lb]=0;
				if(y)_vis[b]=1;else _vis[b]=2;
				lb=b;
				_vis[1]=1;tu=b;dfs2(1,0);
				ans=_f[1][1];
				printf("%lld\n",ans);
			}
			return 0;
		}
		
		
		
		else{
			for(int i=1;i<=m;i++){
				memset(f,0,sizeof(f));memset(sp1,0,sizeof(sp1));memset(sp2,0,sizeof(sp2));
				memset(vis,0,sizeof(vis));
				//scanf("%d%d%d%d",&a,&x,&b,&y);
				rd(a);rd(x);rd(b);rd(y);
				if(mp[make_pair(a,b)]&&!x&&!y){printf("-1\n");continue;}
				if(x)vis[a]=1;else vis[a]=2;
				if(y)vis[b]=1;else vis[b]=2;
				fa[1]=0;
				dfs1(1);
				if(vis[1]==1)ans=f[1][1];else if(vis[1]==2)ans=f[1][0];
				else ans=min(f[1][1],f[1][0]);
				printf("%lld\n",ans);
			}
			return 0;
			
		}
		
	}
	return 0;
}
