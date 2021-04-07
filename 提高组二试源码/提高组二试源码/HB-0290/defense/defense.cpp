#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100000+5;
const long long oo=1111111111111ll;
int n,m,u,v,en,head[N],to[N<<1],nex[N<<1],w[N],x,p,y,q,s;
long long dp[N][2];
char ch[10];

void read(int &x){
	char ch=getchar();x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
}
inline void add(int u,int v){to[++en]=v,nex[en]=head[u],head[u]=en;}
void dfs(int u,int fa){
	int v;
	dp[u][1]=(long long)w[u];
	for(register int i=head[u];i;i=nex[i]){
		v=to[i];
		if(v!=fa){
			dfs(v,u);
			dp[u][0]+=dp[v][1];
			dp[u][1]+=min(dp[v][0],dp[v][1]);
		}
	}
	if((u==x&&p)||(u==y&&q))  dp[u][0]=oo;
	if((u==x&&!p)||(u==y&&!q))dp[u][1]=oo;
}
void dfs0(int u,int fa){
	int v;
	dp[u][1]=(long long)w[u];
	for(register int i=head[u];i;i=nex[i]){
		v=to[i];
		if(v!=fa){
			dfs0(v,u);
			dp[u][0]+=dp[v][1];
			dp[u][1]+=min(dp[v][0],dp[v][1]);
		}
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n),read(m);scanf("%s",ch);
	for(register int i=1;i<=n;++i) read(w[i]);
	for(register int i=1;i<n;++i) read(u),read(v),add(u,v),add(v,u);
	if(ch[1]=='1'){
		dfs0(1,0);
		for(register int i=1;i<=m;++i){
			read(x),read(p),read(y),read(q);
			if(dp[1][1]>=oo) puts("-1");
			else printf("%lld\n",dp[1][1]);
		}
		return 0;
	}
	for(register int i=1;i<=m;++i){
		fill(dp[0],dp[0]+N*2,0);
		read(x),read(p),read(y),read(q);
		dfs(1,0);
		if(min(dp[1][0],dp[1][1])>=oo) puts("-1");
		else printf("%lld\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
