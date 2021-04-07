#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50000+5;
int n,m,a,b,l,en,head[N],to[N<<1],nex[N<<1],c[N<<1],d1[N],d2[N],s1[N],s2[N],f[N],ll[N],ans;
bool flag=true;

void read(int &x){
	char ch=getchar();x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
}
inline void add(int u,int v,int w){to[++en]=v,nex[en]=head[u],head[u]=en,c[en]=w;}
void dfs(int u,int fa){
	for(register int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa){
			dfs(v,u);
			if(d1[v]+c[i]>d1[u]) d1[u]=d1[v]+c[i],s1[u]=v;
			else if(d1[v]+c[i]>d2[u]) d2[u]=d1[v]+c[i],s2[u]=v;
		}
	}
}
void dfs_fa(int fa,int ff){
	for(register int i=head[fa];i;i=nex[i]){
		int u=to[i];
		if(u==ff) continue;
		if(s1[fa]!=u) f[u]=d1[fa]+c[i];
		else f[u]=d2[fa]+c[i];
		f[u]=max(f[u],f[fa]+c[i]);
		dfs_fa(u,fa);
	}
}
inline bool comp(int x,int y){return x>y;}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n),read(m);
	for(register int i=i;i<n;++i){
		read(a),read(b),read(l),add(a,b,l),add(b,a,l);if(a!=1) flag=false;ll[i]=l;
	}
	if(flag){
		sort(ll+1,ll+n,comp);
		printf("%d\n",ll[m]+ll[m+1]);return 0;
	}
	else if(m==1){
		dfs(1,0);
		dfs_fa(1,0);
		for(register int i=1;i<=n;++i) ans=max(ans,d1[i]+f[i]);
		printf("%d\n",ans); return 0;
	}
	return 0;
}
