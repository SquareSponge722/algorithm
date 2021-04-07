#include<cstdio>
#include<algorithm>
#include<string>
#define maxn 20001

using namespace std;
int n,m,dp[maxn][2],p[maxn];
bool g[maxn][maxn],vis[maxn];

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-') f=-1;c=getchar();}
	while((c>='0')&&(c<='9')){
		x=x*10+(int)(c-'0');
		c=getchar();
	}
	return x*f;
}

void work(int x){
	vis[x]=1;
	for(int i=1;i<=n;++i){
		if((g[x][i])&&(!(vis[i]))){
			work(i);
			dp[x][1]+=min(dp[i][1],dp[i][0]);
			dp[x][0]+=dp[i][1];
		}
	}
	vis[x]=0;
}


int main()
{
	n=read();m=read();
	int t=read();
	for(int i=1;i<=n;++i) p[i]=read();
	int u,v;
	for(int i=1;i<n;++i){
		u=read();v=read();
		g[u][v]=g[v][u]=1;
	}
	int a,b,x,y;
	bool wa=0;
	while(m--){
		for(int i=1;i<=n;++i) dp[i][1]=p[i];
		a=read();x=read();b=read();y=read();
		if(x) dp[a][0]=dp[a][1];
		if(y) dp[b][0]=dp[b][1];
		if((!x)&&(!y)){
			if(a>b) swap(a,b);
			for(int i=1;i<=n;++i)
			    if((i==b)&&(g[a][b])){
				   printf("-1\n");
				   wa=1;break;
				}
			if(wa) continue;
		}
		int ans=0x7ffff;
		for(int i=1;i<=n;++i){
			work(i);
			ans=min(min(dp[i][0],dp[i][1]),ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
