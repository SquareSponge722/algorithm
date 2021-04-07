#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n,m,to[2][110000],v[110000];
int id[110000],cnt,val[110000];
char s[10];
void dfs(int x,int fa){
	id[x]=++cnt;
	val[cnt]=v[x];
	for(int i=0;i<2;++i){
		int u=to[i][x];
		if(!u||u==fa)continue;
		dfs(u,x);
	}
}
int ans,dp[110000][2];
inline void slove(int a,int x,int b,int y){
	for(int i=1;i<=n;++i){
		dp[i][0]=dp[i-1][1];
		dp[i][1]=min(dp[i-1][1],dp[i-1][0])+v[i];
		if(i==a){
			if(x){
				dp[i][0]=99999999;
			}
			else{
				dp[i][1]=99999999;
			}
		}
		else{
			if(i==b){
				if(y){
				dp[i][0]=99999999;
			}
			else{
				dp[i][1]=99999999;
			}
			}
		}
	}
	ans=min(dp[n][0],dp[n][1]);
	if(ans==99999999)ans=-1;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	if(s[0]=='A'){
		int a,b;
		for(int i=1;i<=n;++i)scanf("%d",&v[i]);
		for(int i=1;i<n;++i){
			scanf("%d%d",&a,&b);
			if(to[0][a])to[1][a]=b;
			else to[0][a]=b;
			if(to[0][b])to[1][b]=a;
			else to[0][b]=a;
		}
		int now=1;
		for(int i=1;i<=n;++i){
			if(!to[1][i]){
				now=1;
				break;
			}
		}
		dfs(now,0);
		int x,y;
		for(int i=1;i<=m;++i){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			slove(id[a],x,id[b],y);
			printf("%d\n",ans);
		}
	}
	return 0;
}

