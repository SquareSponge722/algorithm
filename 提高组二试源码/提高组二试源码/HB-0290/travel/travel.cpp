#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5000+5;
int n,m,en,head[N],to[N<<1],nex[N<<1],s,t;
bool ins[N],flag=false;
struct Edge{
	int u,v;
	bool operator < (const Edge &x) const{
		if(u!=x.u) return u>x.u;
		else return v>x.v;
	}
}e[N];

void read(int &x){
	char ch=getchar();x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
}
inline void add(int u,int v){to[++en]=v,nex[en]=head[u],head[u]=en;}
void dfs(int u,int fa){
	printf("%d ",u);
	int v;
	for(register int i=head[u];i;i=nex[i]){
		v=to[i];
		if(v!=fa){
			dfs(v,u);
		}
	}
}
void dfs2(int u,int fa){
	ins[u]=true;
	int v;
	for(register int i=head[u];i;i=nex[i]){
		v=to[i];
		if(v!=fa){
			if(ins[v]){
				s=v,t=u,flag=true;return ;
			} 
			dfs2(v,u);
		}
		if(flag) return ; 
	}
	ins[u]=false;
}
void dfs3(int u,int fa){
	printf("%d ",u);
	int v;if(u==s) flag=true;
	ins[u]=true;
	for(register int i=head[u];i;i=nex[i]){
		v=to[i];
		if(ins[v]) continue;
		if(v!=fa){
			if(flag&&v>t){
				flag=false;return ;
			};
			dfs3(v,u);
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n),read(m);
	for(register int i=1;i<=m;++i){
		read(e[i].u),read(e[i].v);
		if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
	}
	sort(e+1,e+m+1);
	for(register int i=1;i<=m;++i) add(e[i].u,e[i].v),add(e[i].v,e[i].u);
	if(m==n-1){
		dfs(1,0);
		return 0;
	}
	else{
		dfs2(1,0);
		flag=false;
		fill(ins,ins+N,false);
		dfs3(1,0);
		return 0;
	}
	return 0;
}
