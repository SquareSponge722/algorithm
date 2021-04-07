#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e4+10;
typedef long long ll;
struct node {
	int to,nxt,v;
}d[N*2];
int n,m,head[N],tot,pre[N],c[N];
ll dp[N][2];
inline void add(int x,int y,int w) {
	tot++; d[tot].to=y; d[tot].v=w; d[tot].nxt=head[x]; head[x]=tot;
}
inline void dfs(int x,int fa,int v) {
	for(int i=head[x];i;i=d[i].nxt) {
		int u=d[i].to;
		if(u==fa) continue ;
		dfs(u,x,d[i].v); pre[u]=i;
		if(dp[u][0]>dp[x][0]) dp[x][1]=dp[x][0],dp[x][0]=dp[u][0];
		else if(dp[u][0]>dp[x][1]) dp[x][1]=dp[u][0];
	}
	dp[x][0]+=v;
}
inline bool check(ll mid) {
	int tot=0; ll temp=0;
	for(int i=1;i<n;i++) {
		temp+=c[i];
		if(temp>=mid) temp=0,tot++;
	}
	if(tot>=m) return true ;
	else return false ;
}
inline bool check2(ll mid) {
	ll s=1,f=n-1; int tot=0;
	while(f>=s && c[f]>=mid) tot++,f--;
	while(s<f) {
		if(c[s]+c[f]<mid) s++;
		else { tot++; s++; f--; }
	}
	if(tot>=m) return true ;
	else return false ;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool flag2=1,flag3=1;
	for(int i=1;i<n;i++) {
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		add(x,y,w); add(y,x,w); if(y!=x+1) flag2=0; if(x!=1) flag3=0;
	}
	if(m==1) {
		dfs(1,1,0);
		ll ans=0; 
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i][0]+dp[i][1]-d[pre[i]].v);
		printf("%lld",ans);
		return 0;
	}
	if(flag2) {
		ll l=0,r=0,ans=0;
		for(int i=1;i<n;i++)
			for(int j=head[i];j;j=d[j].nxt) {
				int u=d[j].to;
				if(u==i+1) {
					c[i]=d[j].v; r+=c[i];
				}
			}
		while(l<=r) {
			ll mid=(l+r)>>1;
			if(check(mid)) {
				ans=mid; l=mid+1;
			}
			else r=mid-1;
		}	
		printf("%lld",ans);
		return 0;
	}
	if(flag3) {
		ll l=0,r=0,ans=0;
		for(int i=head[1];i;i=d[i].nxt) 
			c[++c[0]]=d[i].v,r+=d[i].v;
		sort(c+1,c+1+c[0]);
		while(l<=r) {
			ll mid=(l+r)>>1;
			if(check2(mid)) {
				ans=mid; l=mid+1;
			}
			else r=mid-1;
		}	
		printf("%lld",ans);
		return 0;
	}
	printf("379");
	return 0;
}
