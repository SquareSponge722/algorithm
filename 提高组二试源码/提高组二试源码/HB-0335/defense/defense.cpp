#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=999999999999;
struct node {
	int to,nxt;
}d[2*N];
int n,m,a[N],head[N],tot,xx,yy,limit1,limit2;//dp[x][1] xuan dp[x][0] buxuan
ll dp[N][2];
char ch[10];
inline void add(int x,int y) {
	tot++; d[tot].to=y; d[tot].nxt=head[x]; head[x]=tot;
}
inline void dfs(int x,int fa) {
	for(int i=head[x];i;i=d[i].nxt) {
		int u=d[i].to;
		if(u==fa) continue ;
		dfs(u,x);
	}
	dp[x][1]=a[x];
	for(int i=head[x];i;i=d[i].nxt) {
		int u=d[i].to;
		if(u==fa) continue ;
		dp[x][1]+=min(dp[u][0],dp[u][1]);
	}
	for(int i=head[x];i;i=d[i].nxt) {
		int u=d[i].to;
		if(u==fa) continue ;
		dp[x][0]+=dp[u][1];
	}
	if(x==xx) {
		if(limit1==1) {
			dp[x][0]=inf;
		}
		else dp[x][1]=inf;
	}
	else if(x==yy) {
		if(limit2==1) {
			dp[x][0]=inf;
		}
		else dp[x][1]=inf;
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,ch);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y); add(y,x);
	}
	for(int i=1;i<=m;i++) {
		memset(dp,0,sizeof dp);
		scanf("%d %d %d %d",&xx,&limit1,&yy,&limit2);
		dfs(1,1);
		if(min(dp[1][0],dp[1][1])>=inf) {
			printf("-1\n");
			continue ;
		}
		printf("%lld\n",min(dp[1][1],dp[1][0]));
	}
	return 0;
}
